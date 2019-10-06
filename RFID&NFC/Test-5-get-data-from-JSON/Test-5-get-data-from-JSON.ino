// json for data
#include <ArduinoJson.h>
// --------------------
// Wifi Setting

#include <ESP8266WiFi.h>
#define ssid "Q9_9335"
#define password "a12345678"
const char* host = "15b77b08.ngrok.io"; // 앞에 http 쓰지 말것
// --------------------
// Display Setting
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r
#include "Image_SALE.h"
// --------------------
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/Org_01.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include <Fonts/Picopixel.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#if defined(ESP8266)
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 1); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 1, /*BUSY=D2*/ 4); // default selection of TX(1), D2(4) //D4(=2), D2(=4)
#endif
#define HAS_RED_COLOR

// --------------------
// Speaker Setting
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySoftwareSerial(5, 16); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// --------------------
// RFID Setting
#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

// --------------------
/* 등록된 RF CARD ID */

// UID의 첫 숫자로만 파악하기
int memberCards[3][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
    {0xF9, 0xF2, 0xCB, 0x56}, //member2 민주's Card
    {0xC9, 0xAA, 0x54, 0x47}  //member3 선미's token
  };

int isFirstTag;
void setup() { 
  // Select to Serial Monitor
  Serial.begin(9600); 
  Serial.println();
  
  /* ------- get data from server -------------
  // Connect to Wifi
  Serial.printf("Wifi Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  // Connect to HTTP
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) //이거 말고 HTTPClinet http 깔꼼함? -> Sticky Note
  {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/";
  //  url += streamId;
  //  url += "?private_key=";
  //  url += privateKey;
  //  url += "&value=";
  //  url += value;
   
  Serial.print("Requesting URL: ");
  Serial.println(url);
   
  // This will send the request to the server
  // GET Method
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0)
  {
    if (timeout - millis() < 0)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }

  // Allocate the JSON document
  // Use arduinojson.org/v6/assistant to compute the capacity.
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonDocument doc(capacity);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  // Extract values
  Serial.println(F("Response:"));
  Serial.println(doc["product"].as<char*>());
  Serial.println(doc["price"].as<long>());
  Serial.println(doc["data"][0].as<char*>());
  Serial.println(doc["data"][1].as<char*>());
  //숫자인 경우 Serial.println(doc["data"][1].as<float>(), 6);

  // AWS 서버에서 상품번호로 데이터 요청해서 받은 
  // json 데이터들을
  // 변수로 정의해서 Display에 출력하기



  // Disconnect
  client.stop();
   
  //00 ------- get data from server ------------- */
  
  //Start of DFPlayer
  mySoftwareSerial.begin(9600); 
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
  
  //Start Display (essential code)
  display.init(9600);
  
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작
  isFirstTag = 0; // 처음 태그 시 ( ==1 일때만 따로 코딩)

}
 
void loop() {
  // 카드가 인식 안되었다면 더이상 진행하지 말고 빠져나감
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  //RF카드의 ID가 인식 안되었다면 더이상 진행하지 x말고 빠져나감
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  //PICC 타입 읽어오기
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));


  //MIFARE 방식이 아니라면 더이상 진행하지 말고 빠져나감
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  
  // RFID 태그 인식 ok -> UID check -> 처음 숫자만 보기!
  int memberNum = NULL;
  for (int i = 0; i <= 3; i++) {
    if( rfid.uid.uidByte[0] == memberCards[i][0] ){
      memberNum = i+1;
      break;
    }

  }
  isFirstTag++;
  
  if(memberNum == NULL){
      Serial.println(F("This Card doesn't enroll."));   
  }
  
  // tagging Card ID가 1번이면
  else if (memberNum == 1) {

    Serial.println(F("This is a 선미's Card."));   
    Serial.println(F("Motor On!!"));   

    myDFPlayer.play(1);
   
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showFont("123", u8g2_font_inb63_mn, 10, 50);
    /*
    showBitmap( "banana", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member1] 바나나 2송이 250g", u8g2_font_unifont_t_korean1, 10, 20);
    //showNum(isFirstTag, u8g2_font_unifont_t_korean1,10,40);
    showFont("100g당 2400원", u8g2_font_unifont_t_korean1,10,40);
    if(isFirstTag == 1){
        showfreeFont("10,000",&FreeSans9pt7b,80,55,GxEPD_BLACK);
      }
    else{
        showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
      }

    showfreeFont("8,000",&FreeSansBold18pt7b, 80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    */
    display.update();
  }
  
  // tagging Card ID가 1번이면
  else if(memberNum == 2){
    Serial.println(F("This is a 민주's Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
   
    myDFPlayer.play(2);
    
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showBitmap( "banana", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member2] 바나나 2송이 250g", u8g2_font_unifont_t_korean1,10,20);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1,10,40);
    if(isFirstTag == 1){
        showfreeFont("10,000",&FreeSans9pt7b,80,55,GxEPD_BLACK);
      }
    else{
        showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
      }
    //showfreeFont("6,000", &FreeSansBold18pt7b,90,95);
    showfreeFont("6,000",&FreeSansBold18pt7b, 80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();   
  }

    // tagging Card ID가 3번이면
  else if(memberNum == 3){
    Serial.println(F("This is a 민주's Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
    
    myDFPlayer.play(2);
    
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showBitmap( "banana", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member3] 바나나 2송이 250g", u8g2_font_unifont_t_korean1, 10, 20);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1, 10, 40);
    if(isFirstTag == 1){
        showfreeFont("10,000",&FreeSans9pt7b,80,55,GxEPD_BLACK);
      }
    else{
        showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
      }
    //showfreeFont("6,000", &FreeSansBold18pt7b, 90, 95);
    showfreeFont("5,000",&FreeSansBold18pt7b, 80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();   
  }
  
  //종료
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!
}



/* (Start) Define Function that Print to Display  */
void showBitmap(const char image[], const int num1, const int num2, const int num3, const int num4 )
{
  if(image == "banana"){
      display.setRotation(0);
      display.drawExampleBitmap(banana, num1, num2, num3, num4, GxEPD_RED);//10, 10, 40, 40,
      
    }
  if(image == "arrow"){
      display.setRotation(1);
      display.drawExampleBitmap(arrow, num1, num2, num3, num4, GxEPD_RED); //70, 55, 120, 40,
      display.setRotation(0);
    }
  delay(500);
}

void showFont(const char name[], const uint8_t *f, const int num1, const int num2) //const char name[]
{
  display.setRotation(1);
  Serial.println("HERE");
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setCursor(num1 , num2);
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.println(name);
  display.setRotation(0);
}
/*
void showNum(const int name, const uint8_t *f, const int num1, const int num2) //const char name[]
{
  display.setRotation(1);
  Serial.println("HERE");
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setCursor(num1 , num2);
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.println(name);
  display.setRotation(0);
}*/
/*
void showfreeFont(const char name[], const GFXfont* f,const int num1, const int num2)
{
  display.setRotation(1);
  display.setTextColor(GxEPD_BLACK);
  display.setCursor(num1 ,num2);
  display.setFont(f);
  display.println(name);
  display.setRotation(0);
}*/
void showfreeFont(const char name[], const GFXfont* f,const int num1, const int num2, uint16_t fontcolor)
{
  display.setRotation(1);
  display.setTextColor(fontcolor);
  //display.setTextColor(GxEPD_BLACK);
  display.setCursor(num1 ,num2);
  display.setFont(f);
  display.println(name);
  display.setRotation(0);
}
/* (End) Define Function that Print to Display */

//RFID UID(16진수) 표시를 위함
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

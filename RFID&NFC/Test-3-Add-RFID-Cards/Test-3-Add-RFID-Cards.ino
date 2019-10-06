// Display Setting
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r
#include "Image_SALE.h"
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/Org_01.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#if defined(ESP8266)
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 1); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 1, /*BUSY=D2*/ 4); // default selection of TX(1), D2(4) //D4(=2), D2(=4)
#endif
#define HAS_RED_COLOR

// Speaker Setting
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySoftwareSerial(5, 16); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// RFID Setting
#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

/* 등록된 RF CARD ID */
// Card : D9 AD C8 55
// Token : C9 AA 54 47

/*
#define PICC_0 0xD9 
#define PICC_1 0xAD
#define PICC_2 0xC8
#define PICC_3 0x55 */

// UID의 첫 숫자로만 파악하기
int memberCards[3][4] = {
  {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
  {0xF9, 0xF2, 0xCB, 0x56}, //member2 민주's Card
  {0xC9, 0xAA, 0x54, 0x47}  //member3 선미's token
  };


void setup() { 
  Serial.begin(9600); //Serial Monitor 시작
  
  mySoftwareSerial.begin(9600); //DFPlayer 시작
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
  
  display.init(9600);
  
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작

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

  // RFID UID check
  // 처음 숫자만 보기!
  int memberNum = NULL;
  for (int i = 0; i <= 3; i++) {
    if( rfid.uid.uidByte[0] == memberCards[i][0] ){
      memberNum = i+1;
      break;
    }
  }


  if(memberNum == NULL){
      Serial.println(F("This is a confirmed Card."));   
  }
  
  // tagging Card ID가 1번이면
  else if (memberNum == 1) {

    Serial.println(F("This is a 선미's Card."));   
    Serial.println(F("Motor On!!"));   

    myDFPlayer.play(1);
    
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showBitmapExample();
    
    display.setCursor(10, 20);
    //String Text = "선미";
    //showNum(Text.length(), u8g2_font_unifont_t_korean1);
    
    showFont("선미선미선미선미선미선미선미선미선미", u8g2_font_unifont_t_korean1);
    
    display.setCursor(10, 40);
    String Text2 = "ABC";
    showNum(Text2.length(), u8g2_font_unifont_t_korean1);
    
    //showFont("100g당 2400원", u8g2_font_unifont_t_korean1);
    
    display.setCursor(80 ,60); //80 ,55
    showfreeFont("10,000", &FreeSans9pt7b);
    display.setCursor(90 ,95);
    showfreeFont("8,000", &FreeSansBold18pt7b);
    display.update();
  }
  
  // tagging Card ID가 1번이면
  else if(memberNum == 2){
    //등록된 카드가 아니라면 시리얼 모니터로 ID 표시
    Serial.println(F("This is a 민주's Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
   
    myDFPlayer.play(2);
    
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showBitmapExample();
    display.setCursor(10, 20);
    showFont("민주민주민주[Dole] 바나나 2송이 250g", u8g2_font_unifont_t_korean1);
    display.setCursor(10, 40);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1);
    display.setCursor(80 ,60);
    showfreeFont("10,000", &FreeSans9pt7b);
    display.setCursor(90 ,95);
    showfreeFont("6,000", &FreeSansBold18pt7b);
    display.update();   
  }

    // tagging Card ID가 3번이면
  else if(memberNum == 3){
    //등록된 카드가 아니라면 시리얼 모니터로 ID 표시
    Serial.println(F("This is a 민주's Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
    
    myDFPlayer.play(2);
    
    //display.init(9600);
    display.fillScreen(GxEPD_WHITE);
    showBitmapExample();
    display.setCursor(10, 20);
    showFont("민주민주민주[Dole] 바나나 2송이 250g", u8g2_font_unifont_t_korean1);
    display.setCursor(10, 40);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1);
    display.setCursor(80 ,60);
    showfreeFont("10,000", &FreeSans9pt7b);
    display.setCursor(90 ,95);
    showfreeFont("6,000", &FreeSansBold18pt7b);
    display.update();   
  }
  
  //종료
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!
}



/* (Start) Define Function that Print to Display  */
void showBitmapExample()
{
  display.setRotation(0);
  display.drawExampleBitmap(banana, 10, 10, 40, 40, GxEPD_RED);
  display.setRotation(1);
  display.drawExampleBitmap(arrow, 70, 55, 120, 40, GxEPD_RED);
  delay(500);
}
/*
void showNum(const int name, const uint8_t *f) //const char name[]
{
  //display.setRotation(1);
  Serial.println("HERE");
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.println(name);
}
*/
void showFont(const char name[], const uint8_t *f) //const char name[]
{
  //display.setRotation(1);
  Serial.println("HERE");
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.println(name);
}

void showfreeFont(const char name[], const GFXfont* f)
{
  //display.setRotation(1);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.println(name);
}
/* (End) Define Function that Print to Display */

//RFID UID(16진수) 표시를 위함
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

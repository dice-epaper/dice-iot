// This is for Big Display format !!

/* Display Setting */
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>
/* Choose your display size */
//#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r
#include <GxGDEW042Z15/GxGDEW042Z15.h> // 4.2" b/w/r

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#if defined(ESP8266)
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 1); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 1, /*BUSY=D2*/ 4); // default selection of TX(1), D2(4) //D4(=2), D2(=4)
#endif
#define HAS_RED_COLOR

#include "Image_SALE_Big_Display.h"

/* Add FreeFonts from Adafruit_GFX */
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>


/* Speaker Setting */
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySoftwareSerial(5, 16); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

/* RFID Setting */
#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

/* 등록된 RF CARD ID */

/* 4개 숫자 말고 첫 숫자로만 파악하기
#define PICC_0 0xD9 
#define PICC_1 0xAD
#define PICC_2 0xC8
#define PICC_3 0x55 */

// UID의 첫 숫자로만 파악하기
int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
    {0xC9, 0xAA, 0x54, 0x47}, //member2 선미's token
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 민주's Card
    {0xA9, 0x30, 0x50, 0x47} //member4 민주's token
  };

//int isFirstTag; //10000원 위로 밀려나는 거 solution
void setup() { 
  Serial.begin(9600); //Serial Monitor 시작
  
  mySoftwareSerial.begin(9600); //DFPlayer 시작
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
  
  display.init(9600);
  
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작

  /* 처음 기본 행사 없을 때 아무 그림도 안 띄움 */
  display.fillScreen(GxEPD_WHITE);
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  thirdscreen_default();
  showBitmap("arrow", 260, 190, 120, 40, GxEPD_RED);
  display.drawExampleBitmap(salesale, 20, 240, 160, 40, GxEPD_RED);
  display.setCursor(20, 190);
  showFont("[Dole] 바나나 2송이 250g", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  display.setCursor(20, 220);
  showFont("100g당 3200원", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  display.setCursor(280 ,200);
  showfreeFont("10,000", &FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(250,250);
  showfreeFont("8,000", &FreeSansBold24pt7b,GxEPD_BLACK);
  display.setCursor(230,290);
  showfreeFont("19.08.25 ~ 19.08.29",&FreeSans9pt7b,GxEPD_BLACK);
  display.update();

}
 
void loop() {
  // 카드가 인식 안 되었다면 더이상 진행하지 말고 빠져나감
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
  
  if(memberNum == NULL){
      Serial.println(F("This Card doesn't enroll."));   
  }
  
  // tagging Card ID가 1번이면
  else if (memberNum == 1) {

    Serial.println(F("This is a Member1 (VIP)'s Card."));   
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 

    myDFPlayer.play(1);
   
   display.fillScreen(GxEPD_WHITE);
    
    showBitmap( "sale_vip", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Hello VIP] 바나나 2송이 250g", u8g2_font_unifont_t_korean1, 10, 20);
    showFont("100g당 2400원", u8g2_font_unifont_t_korean1,10,40);
    
    showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
    showfreeFont("3,000",&FreeSansBold18pt7b,80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();
  }
  
  // tagging Card ID가 2번이면
  else if(memberNum == 2){
    Serial.println(F("This is a Member2's => (2+1)Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
   
    myDFPlayer.play(2);
    
    display.fillScreen(GxEPD_WHITE);
    showBitmap( "sale_2plus1", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member2] 바나나 2송이 250g", u8g2_font_unifont_t_korean1,10,20);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1,10,40);
    showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);

    showfreeFont("8,000",&FreeSansBold18pt7b,80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();   
  }

    // tagging Card ID가 3번이면
  else if(memberNum == 3){
    Serial.println(F("This is a Member3's (time sale)Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
    
    myDFPlayer.play(3);

    display.fillScreen(GxEPD_WHITE);
    showBitmap( "sale_magam", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member3] 바나나 2송이 250g", u8g2_font_unifont_t_korean1, 10, 20);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1, 10, 40);
    showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
    showfreeFont("7,500",&FreeSansBold18pt7b,80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();   
  }

 // tagging Card ID가 4번이면
  else if(memberNum == 4){
    Serial.println(F("This is a Member4's (time sale)Card."));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size); 
    
    myDFPlayer.play(4);

    display.fillScreen(GxEPD_WHITE);
    showBitmap( "sale_1plus1", 10, 10, 40, 40 );
    showBitmap( "arrow", 70, 55, 120, 40 );
    
    showFont("[Member4] 바나나 2송이 250g", u8g2_font_unifont_t_korean1, 10, 20);
    showFont("100g당 3200원", u8g2_font_unifont_t_korean1, 10, 40);
    showfreeFont("10,000",&FreeSans9pt7b,80,62,GxEPD_BLACK);
    showfreeFont("7,500",&FreeSansBold18pt7b,80,90,GxEPD_RED);
    showfreeFont("19.08.25~19.08.26", &Org_01, 120,100,GxEPD_BLACK);
    display.update();   
  }
  
  //종료
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!
}

/* (Start) Define Function that Print to Display  */
void showBitmap(const char image[], const int num1, const int num2, const int num3, const int num4, uint16_t image_color)
{ /*
   if(image == "arrow"){
    display.setRotation(1);
    display.drawExampleBitmap(arrow, num1, num2, num3, num4, GxEPD_RED); //70, 55, 120, 40,
    display.setRotation(0);
  }
  /*멤버별 할인*/
  if(image == "sale_vip"){
    display.setRotation(0);
    display.drawExampleBitmap(sale_vip, num1, num2, num3, num4, GxEPD_RED);//10, 10, 40, 40,
  }

  /*다양한 세일 종류*/
  if(image == "sale_super"){
    display.setRotation(0);
    display.drawExampleBitmap(sale_super, num1, num2, num3, num4, image_color);//GxEPD_RED);//10, 10, 40, 40,
  }
  else if(image == "sale_magam"){
    display.setRotation(0);
    display.drawExampleBitmap(sale_magam, num1, num2, num3, num4,image_color);// GxEPD_RED);//10, 10, 40, 40,
  }
  else if(image == "sale_1plus1"){
    display.setRotation(0);
    display.drawExampleBitmap(sale_1plus1, num1, num2, num3, num4,image_color);// GxEPD_RED);//10, 10, 40, 40,
  }
  else if(image == "sale_2plus1"){
    display.setRotation(0);
    display.drawExampleBitmap(sale_2plus1, num1, num2, num3, num4, image_color);//GxEPD_RED);//10, 10, 40, 40,
  }
  
  /*qr Code*/
  else if(image == "qrcode"){
    display.setRotation(0);
    display.drawExampleBitmap(qrcode, num1, num2, num3, num4, image_color);//GxEPD_RED);//10, 10, 40, 40,
  }
  else if(image == "qrcode_deco"){
    display.setRotation(0);
    display.drawExampleBitmap(qrcode_deco, num1, num2, num3, num4,image_color);// GxEPD_RED);//10, 10, 40, 40,
  }
  
  /*above*/
  else if(image == "qrcode_guide"){
    display.setRotation(0);
    display.drawExampleBitmap(qrcode_guide, num1, num2, num3, num4,image_color);// GxEPD_RED);//10, 10, 40, 40,
  }
  else if(image == "discount_arrow"){
    display.setRotation(0);
    display.drawExampleBitmap(discount_arrow, num1, num2, num3, num4, image_color);// GxEPD_RED);//10, 10, 40, 40,
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

void showfreeFont(const char name[], const GFXfont* f,const int num1, const int num2, uint16_t fontColor)
{
  display.setRotation(1);
  display.setTextColor(fontColor);
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

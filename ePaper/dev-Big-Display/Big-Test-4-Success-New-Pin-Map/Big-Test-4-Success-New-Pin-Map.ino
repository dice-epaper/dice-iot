// This is for Big Display format !!

/* Display Setting */
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>

/* Choose your display size */
//#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r
#include <GxGDEW042Z15/GxGDEW042Z15.h>  // 4.2" b/w/r

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#if defined(ESP8266)
//onenote test7 pin map
GxIO_Class io(SPI, /*CS=*/ 15, /*DC=*/ 0, /*RST=*/ 4); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=*/ 4, /*BUSY=*/ 5); // default selection of D4(=2), D2(=4)
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
SoftwareSerial mySoftwareSerial(10, 16); 
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

/* UID의 첫 숫자로만 파악하기 */
int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
    {0xC9, 0xAA, 0x54, 0x47}, //member2 선미's token
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 민주's Card
    {0xA9, 0x30, 0x50, 0x47} //member4 민주's token
  };
  
void setup()
{
  Serial.begin(9600); //Serial Monitor 시작
  
  mySoftwareSerial.begin(9600); //DFPlayer 시작
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
  
  display.init(9600);
  
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작
  Serial.println("setup done");

  /* (처음) 기본 행사 없을 때 아무 그림도 안 띄움 */
  display.fillScreen(GxEPD_WHITE);
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  thirdscreen_default();
  display.drawExampleBitmap(arrow, 260, 190, 120, 40, GxEPD_RED);
  display.drawExampleBitmap(sale_1plus1, 20, 240, 160, 40, GxEPD_RED);
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

void loop()
{
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
  
  // tagging Card ID가 1번, 4번이면
  else if (memberNum == 1 || memberNum == 3) {
    myDFPlayer.play(1);
    firstscreen_timesale();
    display.update(); 
  }
    
  // tagging Card ID가 2번, 4번이면
  else if(memberNum == 2 || memberNum == 4){
    myDFPlayer.play(2);
    secondscreen_discount();
    display.update(); 
  }

  //종료
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!
  
}


/* (Start) Define Function that Print to Display  */

void firstscreen_timesale()
{
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  display.setCursor(20, 30);
  showfreeFont("before",&FreeSansBold12pt7b,GxEPD_WHITE);
  display.setCursor(40, 140);
  showFont("58",u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
  display.setCursor(170,130);
  showfreeFont("min",&FreeSansBold24pt7b,GxEPD_WHITE);
}

void secondscreen_discount()
{
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  display.drawExampleBitmap(discount_arrow, 160, 35, 90, 90 ,GxEPD_RED);
  display.setCursor(20, 115);
  showFont("40",u8g2_font_logisoso78_tn,GxEPD_WHITE,GxEPD_RED);
  display.setCursor(120, 105);
  showfreeFont("%",&FreeSansBold24pt7b,GxEPD_WHITE);
}

void thirdscreen_default()
{
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  display.drawExampleBitmap(qrcode_guide, 20, 20, 70, 80, GxEPD_RED);
  display.setCursor(95, 50);
  showfreeFont("Scan this",&FreeSansBold18pt7b,GxEPD_WHITE);
  display.setCursor(90, 100);
  showfreeFont("QR Code!",&FreeSansBold18pt7b,GxEPD_WHITE);
  display.setCursor(20, 130);
  showFont("오늘의 행사 확인하기!", u8g2_font_unifont_t_korean1,GxEPD_WHITE,GxEPD_RED);
}

void showFont(const char name[], const uint8_t *f,uint16_t foreColor,uint16_t backColor)
{
  display.setRotation(0);
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(foreColor);  // apply Adafruit GFX color
  display.setBackgroundColor(backColor);  // apply Adafruit GFX color
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.println(name);
}

void showfreeFont(const char name[], const GFXfont* f, uint16_t color)
{
  display.setRotation(0);
  display.setTextColor(color);
  display.setFont(f);
  display.println(name);
}

/* (End) Define Function that Print to Display */

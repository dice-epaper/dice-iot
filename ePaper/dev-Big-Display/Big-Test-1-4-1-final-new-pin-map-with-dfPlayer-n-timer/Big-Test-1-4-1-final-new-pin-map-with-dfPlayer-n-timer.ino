// This is for Big Display format !!

// Tagging 하고 소리 louder.. ㅜㅜ
// 가끔 처음 setup() 함수내의 화면 변경안됨

/*Timer Setting*/
#include <ESP8266WiFi.h>
#include <time.h>

#define ssid "Q9_9335"
#define password "a12345678"

int timezone = 3;
int dst = 0;
double     d_diff;
time_t     tm_st;
time_t     tm_nd;
int        tm_day, tm_hour, tm_min, tm_sec;
struct tm  user_stime;

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
GxIO_Class io(SPI, /*CS=*/ 0, /*DC=*/ 4, /*RST=*/ 5); 
GxEPD_Class display(io, /*RST=*/ 5, /*BUSY=*/ 16);

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

//SoftwareSerial mySoftwareSerial(9,10);
DFRobotDFPlayerMini myDFPlayer;
SoftwareSerial mySoftwareSerial(1,3); 
//myDFPlayer.volume(8);

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
  Serial.println("Start Serial");
  
  /* Speaker Set-up*/
  Serial.end();
  SoftwareSerial mySoftwareSerial(1,3); 
  mySoftwareSerial.begin(9600); //DFPlayer 시작
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
  myDFPlayer.play(1);
  Serial.begin(9600);

  /*RFID Set-up*/
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작

  /*display Set-up*/
  display.init(9600);
  
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

  Serial.println("Print default-screen");

  /* (start) for thirdScreen - time sale */
  /* set dead line (마감 시간) */

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  configTime(9 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");

  /*마감시간 설정*/
  user_stime.tm_year   = 2019   -1900;   // 주의 :년도는 1900년부터 시작
  user_stime.tm_mon    = 8      -1;      // 주의 :월은 0부터 시작
  user_stime.tm_mday   = 30;
  user_stime.tm_hour   = 22;
  user_stime.tm_min    = 50;
  user_stime.tm_sec    = 0;
  user_stime.tm_isdst  = 0;              // 썸머 타임 사용 안함
  
  Serial.println("");
  tm_st = mktime(&user_stime); 
  Serial.println("마감 시간 is");
  //Serial.println(tm_st);
  Serial.println(ctime(&tm_st));
  /* (start) for thirdScreen - time sale */
  
  Serial.println("Setup Done!");
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
      Serial.println("This Card doesn't enroll.");   
  }
  
  // tagging Card ID가 1번, 3번이면
  // ★☆★ time Sale (시간 변화 적용)
  else if (memberNum == 1 || memberNum == 3) {
    Serial.println("Card!!");
      Serial.end();
      SoftwareSerial mySoftwareSerial(1,3); 
      mySoftwareSerial.begin(9600); //DFPlayer 시작
      myDFPlayer.begin(mySoftwareSerial);
      myDFPlayer.volume(8);
      myDFPlayer.play(1);
      Serial.begin(9600);
      //display.init(9600);
    Serial.println("------------------");
    int remainMin = getRemainMin();
    Serial.println("------------------");
    Serial.print("first remainMin is ");
    Serial.println(remainMin);
    for(int i= remainMin; i>0; i--){

      Serial.print("\n Now, Remain min is : ");
      Serial.println(i);
      firstscreen_timesale(i);      

      display.update(); 
      delay(46000); //46초 뒤에 다시 check

    } 
  }
    
  // tagging Card ID가 2번, 4번이면
  else if(memberNum == 2 || memberNum == 4){
    Serial.println("token tagging"); 
      Serial.end();
      SoftwareSerial mySoftwareSerial(1,3); 
      mySoftwareSerial.begin(9600); //DFPlayer 시작
      myDFPlayer.begin(mySoftwareSerial);
      myDFPlayer.volume(8);
      myDFPlayer.play(2);
      Serial.begin(9600);
      //display.init(9600);
    secondscreen_discount();
    display.update(); 
  }

  //종료
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!

}


/* (Start) Define Function that Print to Display  */

void firstscreen_timesale(int min)//(const char min[])
{
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  display.setCursor(20, 30);
  showfreeFont("before",&FreeSansBold12pt7b,GxEPD_WHITE);
  
  //int minToInt = int(min);
  Serial.print("in firstscreen_fn >> remainMin is : ");
  Serial.println(min);  
  //Serial.println(minToInt); 
  /*if(min <0){
    Serial.println("pass the sale time"); 
    display.setCursor(95, 140);
    showFont("No Sale",u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
  
  }*/
  if(min <10){
    Serial.println("it is lower than 10"); 
    display.setCursor(95, 140);
    showFont(String(min).c_str(),u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
    display.setCursor(170,130);
    showfreeFont("min",&FreeSansBold24pt7b,GxEPD_WHITE);
  }
  else if(min >10){
    Serial.println("it is Bigger than 10"); 
    display.setCursor(40, 140);
    showFont(String(min).c_str(),u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
    display.setCursor(170,130);
    showfreeFont("min",&FreeSansBold24pt7b,GxEPD_WHITE);
  }


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


/* (Start) get 현재 시간 */
int getRemainMin(){
  Serial.println("");
  Serial.println("현재 시간 is");
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  //getTextTime(now);
  struct tm * timeinfo;
  timeinfo = localtime(&now);
  Serial.println(timeinfo->tm_hour);
  Serial.println(timeinfo->tm_min);
  Serial.println(timeinfo->tm_wday); //요일
  String text = String(timeinfo->tm_hour)+String(timeinfo->tm_min)+String(timeinfo->tm_wday);
  Serial.println(text);
  delay(1000);

  /*시차 계산*/
  d_diff   = difftime( tm_st,now );
  
  tm_day   = d_diff / ( 60 *60 * 24);
  d_diff   = d_diff - ( tm_day *60 *60 *24);
  
  tm_hour  = d_diff / ( 60 *60);
  d_diff   = d_diff - ( tm_hour *60 *60);
  
  tm_min   = d_diff / 60;
  d_diff   = d_diff - ( tm_min *60);
  
  tm_sec   = d_diff;
  String Text = String("지금부터 2019년 08월 28일 15시까지는")+
              String(tm_day)+"일 "+String(tm_hour)+"시 "+String(tm_min)+"분 "+String(tm_sec)+"초 남았음";
  Serial.println(Text);
  return tm_min;
}
/* (End) get 현재 시간 */

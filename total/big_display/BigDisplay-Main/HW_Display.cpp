#include "HW_Display.h"

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

/* Add FreeFonts from Adafruit_GFX */
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>

/* (Start) Call basic function */
void call_display_init(){
  display.init(9600);
}

void call_display_update(){
  display.update();
}
/* (End) Call basic function */

/* (Start) Print screen function */

/* 0. 가격 화면 */
void screen0_under(){
  display.fillScreen(GxEPD_WHITE);
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  //thirdscreen_default();
  display.drawExampleBitmap(arrow, 260, 190, 120, 40, GxEPD_RED);
  display.drawExampleBitmap(sale_1plus1, 20, 240, 160, 40, GxEPD_RED);
  display.setCursor(20, 190);
  showFont("[Dole] 바나나 2송이 250g", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  display.setCursor(20, 220);
  showFont("100g당 3200원", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  display.setCursor(280 ,193);
  showfreeFont("10,000", &FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(250,250);
  showfreeFont("8,000", &FreeSansBold24pt7b,GxEPD_BLACK);
  display.setCursor(230,290);
  showfreeFont("19.08.25 ~ 19.08.29",&FreeSans9pt7b,GxEPD_BLACK);
}

/* 1. 기본 화면*/
void screen1_default()
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

/* 2. 기본 할인 화면 */
void screen2_discount()
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

void screen3_magam_Over(){
  display.fillRect(0, 0, 400, 150, GxEPD_RED);  
  display.setCursor(70, 70);
  showfreeFont("TIME OVER!" ,&FreeSansBold24pt7b,GxEPD_WHITE);
  display.setCursor(70, 100);
  showfreeFont("set magam time Again!",&FreeSansBold12pt7b,GxEPD_WHITE);
}

void screen3_magam(const char min[])
{
  display.fillRect(0, 0, 400, 150, GxEPD_RED);
  display.fillRect(263, 13, 124, 2, GxEPD_WHITE);
  display.fillRect(263, 13, 2, 124, GxEPD_WHITE);
  display.fillRect(385, 13, 2, 124, GxEPD_WHITE);
  display.fillRect(263, 135, 124, 2, GxEPD_WHITE);
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  
  display.fillRect(0, 0, 250, 150, GxEPD_BLACK);
  display.setCursor(20, 30);
  showfreeFont("before",&FreeSansBold12pt7b,GxEPD_WHITE);
  
  String minToInt = String(min);
  Serial.print(minToInt);
  Serial.print(" 길이 is : ");
  Serial.println(minToInt.length());
  
  if(minToInt.length() <= 1 ){
    Serial.print("10 보다 작음(1의 자리) : ");
    Serial.println(minToInt);
    display.setCursor(80, 140);
    showFont(min,u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_BLACK);
  }
  else if(minToInt.length() == 2 ){
    Serial.print("큼(10의자리) : ");
    Serial.println(minToInt);
    display.setCursor(30, 140);
    showFont(min,u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_BLACK);
  }

  display.setCursor(155,130);
  showfreeFont("min",&FreeSansBold24pt7b,GxEPD_WHITE);
}

void screen4_wine(){
  //바탕색 design//
  //display.fillScreen(GxEPD_WHITE);
  display.fillRect(0, 0, 400, 40, GxEPD_RED);
  display.fillRect(0, 42, 400, 108, GxEPD_BLACK);
  display.fillRect(0, 40, 400, 2, GxEPD_WHITE);
  
  /*당도, 도수 표기 design*/
  display.setRotation(0);
  
  // ★ 수정사항
  // 들어오는 인자 (개수)로 선택되도록 change
  // (제안) 빈잔 그림 있으면 어때 ?
  
  //당도//
  display.drawExampleBitmap(winecup, 170, 50 , 20, 40 ,GxEPD_BLACK); //1잔
  display.drawExampleBitmap(winecup, 205, 50 , 20, 40 ,GxEPD_BLACK); //2잔
  display.drawExampleBitmap(winecup, 240, 50 , 20, 40 ,GxEPD_BLACK); //3잔
  display.drawExampleBitmap(winecup, 275, 50 , 20, 40 ,GxEPD_BLACK); //4잔
  display.drawExampleBitmap(winecup, 310, 50 , 20, 40 ,GxEPD_BLACK); //5잔
  display.drawExampleBitmap(winecup, 345, 50 , 20, 40 ,GxEPD_BLACK); //6잔
  
  //도수//
  display.drawExampleBitmap(winecup, 170, 100 , 20, 40 ,GxEPD_BLACK); //1잔
  display.drawExampleBitmap(winecup, 205, 100 , 20, 40 ,GxEPD_BLACK); //2잔
  display.drawExampleBitmap(winecup, 240, 100 , 20, 40 ,GxEPD_BLACK); //3잔
  display.drawExampleBitmap(winecup, 275, 100 , 20, 40 ,GxEPD_BLACK); //4잔
  display.drawExampleBitmap(winecup, 310, 100 , 20, 40 ,GxEPD_BLACK); //5잔
  display.drawExampleBitmap(winecup, 345, 100 , 20, 40 ,GxEPD_BLACK); //6잔
  
  //design//
  display.setCursor(85, 25);
  showfreeFont("WINE OF",&FreeSansBold12pt7b,GxEPD_WHITE);
  display.setCursor(210, 33);
  showfreeFont("France",&FreeSansBold18pt7b,GxEPD_WHITE);
  display.setCursor(25, 80);
  showfreeFont("sweetness",&FreeSansBold12pt7b,GxEPD_WHITE);
  display.setCursor(30, 125);
  showfreeFont("oxidation",&FreeSansBold12pt7b,GxEPD_WHITE);
}

void screen5_cow(){
  Serial.println("\n now screen5");
  /* 1. base design : 표 테두리 & 등급 기본 설정 */
  base_layout();
 
  /* 2. 등급 표기 - 무조건 등급 기본 설정보다 다음에 있어야 함 
   * gradeArr : {111, 11, 1, 2, 3};
   * ex) 111 -> 1++
   */
  select_grade(11);

  /* 3. 표 채우기 */ 
  /* fill_table(int origin, int use, int deliverNum)
   * 
   * origin : [0]"국내산", [1]"미국산", [2]"호주산"
   * use : [0] "구이",  [1]"육수",  [2]"국",  [3]"탕/찜"};
   * Number : 유통식별번호
   */
  fill_table_else(0,3,800102613245); //<- 기존 800102613244
  
  /* 4. 기본 가격표 */
  display.setCursor(15, 216);
  showfreeFont("100g",&FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(260, 260);
  showfreeFont("5,000",&FreeSansBold24pt7b,GxEPD_BLACK);
  
  /* 5. 소 부위 함수 */
  /* void select_meat_part(int partNum)
   *  
   * meat_partArr[13]= {[0] "목심", [1]"등심",[2]"채끝",[3]"우둔", [4]"앞다리", 
                     [5]"갈비", [6]"안심", [7]"사태", [8]"양지", [9]"설도", 
                      [10]"꼬리", [11]"사골", [12]"우족" };  */
  select_meat_part(10);//"꼬리"
  
  /*6. 행사 시 - 화살표(+ 행사 전 가격) & sale image & 행사 날짜*/
  event();

  /*7. 마감 옵션 - 나중에 추가할 수도 있음*/ 
  // => 다른 screen에서도 사용 가능!
  //display.fillRect(318,274,74,20,GxEPD_RED);
  //display.setCursor(319, 290);
  //showfreeFont("19.08.29",&FreeSans9pt7b,GxEPD_WHITE);

}

/* (End) Print screen function */

/*(Start) for screen5_cow() */
void base_layout(){
  
  //표 & 테두리 design//
  display.fillScreen(GxEPD_WHITE);
  display.fillRect(0,0,400,2,GxEPD_BLACK);  display.fillRect(398,0,2,300,GxEPD_BLACK);
  display.fillRect(0,0,2,300,GxEPD_BLACK);  display.fillRect(0,298,400,2,GxEPD_BLACK);
  display.fillRect(200,0,2,45,GxEPD_BLACK);  display.fillRect(250,0,2,45,GxEPD_BLACK);
  display.fillRect(299,0,2,45,GxEPD_BLACK);  display.fillRect(332,0,2,45,GxEPD_BLACK);
  display.fillRect(365,0,2,45,GxEPD_BLACK);  display.fillRect(200,45,80,90,GxEPD_BLACK);
  display.fillRect(200,45,200,2,GxEPD_BLACK);  display.fillRect(280,90,119,2,GxEPD_BLACK);
  display.fillRect(200,90,80,2,GxEPD_WHITE);  display.fillRect(0,135,200,45,GxEPD_BLACK);
  display.fillRect(0,135,400,2,GxEPD_BLACK);  display.fillRect(0,180,400,2,GxEPD_BLACK);
  
  //등급 기본 설정//
  display.setCursor(205, 30);  showfreeFont("1++",&FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(261, 30);  showfreeFont("1+",&FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(310, 30);  showfreeFont("1",&FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(343, 30);  showfreeFont("2",&FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(376, 30);  showfreeFont("3",&FreeSans12pt7b,GxEPD_BLACK);
  
  // 소 부위 그림 //
  display.drawExampleBitmap(cow, 22, 20, 158, 97, GxEPD_WHITE);
  display.fillRect(85,76,1,2,GxEPD_WHITE);
}

void select_grade(int grade){
  //int gradeArr[4]= {111, 11, 1, 2, 3};

  if(grade == 111){ //first_pp() // 등급 중 '1++' 색칠
    display.fillRect(202,2,48,43,GxEPD_RED);
    display.setCursor(205, 30);
    showfreeFont("1++",&FreeSans12pt7b,GxEPD_WHITE);
  }
  else if(grade == 11){ //first_p() // 등급 중 '1+' 색칠
    display.fillRect(252,2,47,43,GxEPD_RED);
    display.setCursor(261, 30);
    showfreeFont("1+",&FreeSans12pt7b,GxEPD_WHITE);
  }
  else if(grade == 1){ //first() // 등급 중 '1' 색칠
    display.fillRect(301,2,31,43,GxEPD_RED);
    display.setCursor(310, 30);
    showfreeFont("1",&FreeSans12pt7b,GxEPD_WHITE);
  }
  else if(grade ==2) { //second() //  등급 중 '2' 색칠
    display.fillRect(334,2,31,43,GxEPD_RED);
    display.setCursor(343, 30);
    showfreeFont("2",&FreeSans12pt7b,GxEPD_WHITE);
  }
  else if(grade == 3) { //third() // 등급 중 '3' 색칠 
    display.fillRect(367,2,31,43,GxEPD_RED);
    display.setCursor(376, 30);
    showfreeFont("3",&FreeSans12pt7b,GxEPD_WHITE);
  }
}

void fill_table_else(int origin, int use, int deliverNum){
  /* 원산지 */
  display.setCursor(210, 73);
  showFont("원 산 지", u8g2_font_unifont_t_korean1,GxEPD_WHITE,GxEPD_BLACK);
  display.setCursor(315, 73);
  String originArr[3]= {"국내산", "미국산", "호주산"};
  showFont(originArr[origin].c_str(), u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);

  /* 용도 */
  display.setCursor(208, 120);
  showFont("용    도", u8g2_font_unifont_t_korean1,GxEPD_WHITE,GxEPD_BLACK); 
  String useArr[4]= {"구이", "육수", "국", "탕/"};
  // 위 arr 굳이 안씀.. 그냥 indexing 편하려고..
  if(use == 0){
    display.setCursor(323, 120);
    showFont("구이", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  }
  else if(use == 1){
    display.setCursor(324, 120);
    showFont("육수", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  }
  else if(use == 2){
    display.setCursor(332, 120);
    showFont("국", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
  
  }
  else if(use == 3){
    display.setCursor(320, 120);
    showFont("탕/", u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
    display.drawExampleBitmap(zzim, 345, 108, 11, 13, GxEPD_BLACK);
  }
  
  display.setCursor(30, 163);
  showFont("유 통 식 별 번 호", u8g2_font_unifont_t_korean1,GxEPD_WHITE,GxEPD_BLACK);
  display.setCursor(250, 163);
  showFont(String(deliverNum).c_str(), u8g2_font_unifont_t_korean1,GxEPD_BLACK,GxEPD_WHITE);
}

/* (Start) 고기 부위 고르기 */
void select_meat_part(int partNum){
  String meat_partArr[13]= {"목심", "등심","채끝","우둔", "앞다리", 
                        "갈비", "안심", "사태", "양지", "설도", 
                        "꼬리", "사골", "우족" };

  // Text Print
  display.setCursor(22, 115);
  showFont(meat_partArr[partNum].c_str(), u8g2_font_unifont_t_korean1,GxEPD_RED,GxEPD_WHITE);

  // Paint Part
  if(partNum == 0){ // 부위 중 '목심' 색칠
    display.fillRect(65,28,2,1,GxEPD_RED); display.fillRect(65,29,13,8,GxEPD_RED);
    display.fillRect(66,37,12,2,GxEPD_RED); display.fillRect(67,39,11,2,GxEPD_RED);
  }
  
  else if(partNum == 1){ // 부위 중 '등심' 색칠
    display.fillRect(86,28,8,1,GxEPD_RED); display.fillRect(81,29,44,12,GxEPD_RED);
  }
  
  else if(partNum == 2){// 부위 중 '채끝' 색칠
    display.fillRect(129,29,15,3,GxEPD_RED); display.fillRect(128,32,16,8,GxEPD_RED);
    display.fillRect(128,40,15,1,GxEPD_RED);
  }

  else if(partNum == 3){ // 부위 중 '우둔' 색칠
    display.fillRect(147,29,13,4,GxEPD_RED); display.fillRect(147,33,14,1,GxEPD_RED);
    display.fillRect(147,34,15,1,GxEPD_RED); display.fillRect(147,35,16,1,GxEPD_RED);
    display.fillRect(147,36,17,1,GxEPD_RED); display.fillRect(147,37,18,1,GxEPD_RED);
    display.fillRect(147,38,19,2,GxEPD_RED); display.fillRect(147,40,20,4,GxEPD_RED);
    display.fillRect(146,44,21,5,GxEPD_RED); display.fillRect(149,49,18,1,GxEPD_RED);

    //"둔"이 없어서 만듦//
    display.drawExampleBitmap(dun,40, 102, 11, 14, GxEPD_RED);
  }
  else if(partNum == 4){ // 부위 중 '앞다리' 색칠
    display.fillRect(68,44,17,1,GxEPD_RED); display.fillRect(67,45,19,1,GxEPD_RED);
    display.fillRect(66,46,21,2,GxEPD_RED); display.fillRect(65,48,22,17,GxEPD_RED);
    display.fillRect(66,65,20,2,GxEPD_RED);
  }
  else if(partNum == 5){ // 부위 중 '갈비' 색칠
    display.fillRect(93,44,20,1,GxEPD_RED); display.fillRect(91,45,34,1,GxEPD_RED);
    display.fillRect(90,46,39,1,GxEPD_RED); display.fillRect(90,47,43,1,GxEPD_RED);
    display.fillRect(90,48,45,1,GxEPD_RED); display.fillRect(90,49,46,3,GxEPD_RED);
    display.fillRect(90,52,45,6,GxEPD_RED); display.fillRect(90,58,44,6,GxEPD_RED);
    display.fillRect(90,64,43,2,GxEPD_RED); display.fillRect(91,66,41,1,GxEPD_RED);
  }
  else if(partNum == 6){ // 부위 중 '안심' 색칠
    display.fillRect(136,44,6,1,GxEPD_RED); display.fillRect(138,45,5,1,GxEPD_RED);
    display.fillRect(139,46,3,1,GxEPD_RED); display.fillRect(141,47,1,1,GxEPD_RED);
  }
  else if(partNum == 7){ // 부위 중 '사태' 색칠
    display.fillRect(68,70,15,1,GxEPD_RED); display.fillRect(67,71,17,1,GxEPD_RED);
    display.fillRect(68,72,16,1,GxEPD_RED); display.fillRect(69,73,15,1,GxEPD_RED);
    display.fillRect(70,74,14,1,GxEPD_RED); display.fillRect(71,75,13,1,GxEPD_RED);
    display.fillRect(73,76,11,1,GxEPD_RED); display.fillRect(74,77,9,1,GxEPD_RED);
    display.fillRect(76,78,7,1,GxEPD_RED); display.fillRect(77,79,6,2,GxEPD_RED);
    display.fillRect(78,81,5,1,GxEPD_RED); display.fillRect(79,82,3,1,GxEPD_RED);
    display.fillRect(149,73,4,1,GxEPD_RED); display.fillRect(145,74,8,1,GxEPD_RED);
    display.fillRect(146,75,7,1,GxEPD_RED); display.fillRect(146,76,2,1,GxEPD_RED);
  }
  else if(partNum == 8){ // 부위 중 '양지' 색칠
    display.fillRect(87,70,43,1,GxEPD_RED); display.fillRect(87,71,45,3,GxEPD_RED);
    display.fillRect(88,74,44,2,GxEPD_RED); display.fillRect(88,76,42,1,GxEPD_RED);
    display.fillRect(99,77,28,1,GxEPD_RED); display.fillRect(103,78,22,1,GxEPD_RED);
    display.fillRect(111,79,12,1,GxEPD_RED);
  }  
  else if(partNum == 9){ // 부위 중 '설도' 색칠
    display.fillRect(139,51,4,1,GxEPD_RED); display.fillRect(139,52,7,1,GxEPD_RED);
    display.fillRect(139,53,27,2,GxEPD_RED); display.fillRect(138,55,27,3,GxEPD_RED);
    display.fillRect(138,58,26,2,GxEPD_RED); display.fillRect(138,60,25,1,GxEPD_RED);
    display.fillRect(137,61,25,2,GxEPD_RED); display.fillRect(137,63,24,1,GxEPD_RED);
    display.fillRect(137,64,23,2,GxEPD_RED); display.fillRect(137,66,22,1,GxEPD_RED);
    display.fillRect(136,67,22,1,GxEPD_RED); display.fillRect(136,68,19,1,GxEPD_RED);
    display.fillRect(135,69,16,1,GxEPD_RED); display.fillRect(135,70,11,1,GxEPD_RED);
    display.fillRect(135,71,6,1,GxEPD_RED); display.fillRect(135,72,3,1,GxEPD_RED);
    display.fillRect(136,73,1,1,GxEPD_RED);
  }  
  else if(partNum == 10){ // 부위 중 '꼬리' 색칠
    display.fillRect(163,29,2,1,GxEPD_RED); display.fillRect(164,30,3,1,GxEPD_RED);
    display.fillRect(164,31,4,1,GxEPD_RED); display.fillRect(165,32,3,1,GxEPD_RED);
    display.fillRect(166,33,3,1,GxEPD_RED); display.fillRect(167,34,3,1,GxEPD_RED);
    display.fillRect(168,35,3,1,GxEPD_RED); display.fillRect(169,36,2,1,GxEPD_RED);
    display.fillRect(169,37,3,1,GxEPD_RED); display.fillRect(170,38,2,1,GxEPD_RED);
    display.fillRect(171,39,1,2,GxEPD_RED); display.fillRect(171,41,2,1,GxEPD_RED);
    display.fillRect(172,42,1,16,GxEPD_RED); display.fillRect(171,58,1,3,GxEPD_RED);
    display.fillRect(170,61,2,4,GxEPD_RED); display.fillRect(169,65,3,1,GxEPD_RED);
    display.fillRect(169,66,4,9,GxEPD_RED); display.fillRect(168,75,5,1,GxEPD_RED);
    display.fillRect(168,76,4,6,GxEPD_RED); display.fillRect(169,82,2,5,GxEPD_RED);
    display.fillRect(169,87,1,2,GxEPD_RED);
    
    //이전 '꼬리' 덮어씌우기
    display.fillRect(18,90,48,30,GxEPD_WHITE);
    display.setCursor(22, 115);
    showFont("  리", u8g2_font_unifont_t_korean1,GxEPD_RED,GxEPD_WHITE);
    
    //"꼬"가 없어서 만듦//
    display.drawExampleBitmap(kko ,22, 104, 11, 11, GxEPD_RED);
  }
  else if(partNum == 11){ // 부위 중 '사골' 색칠
    display.fillRect(78,85,7,3,GxEPD_RED); display.fillRect(78,88,6,2,GxEPD_RED);
    display.fillRect(79,90,5,3,GxEPD_RED); display.fillRect(79,93,4,2,GxEPD_RED);
    display.fillRect(80,95,3,2,GxEPD_RED); display.fillRect(150,78,5,1,GxEPD_RED);
    display.fillRect(144,79,11,1,GxEPD_RED); display.fillRect(145,80,10,3,GxEPD_RED);
    display.fillRect(146,83,9,3,GxEPD_RED); display.fillRect(148,86,8,1,GxEPD_RED);
    display.fillRect(148,87,9,2,GxEPD_RED); display.fillRect(147,89,9,3,GxEPD_RED);
    
    //"골"이 없어서 만듦//
    display.drawExampleBitmap(gol ,42, 101, 11, 14, GxEPD_RED);
  }
  else if(partNum == 12){ // 부위 중 '우족' 색칠
    display.fillRect(80,97,2,9,GxEPD_RED); display.fillRect(80,106,3,2,GxEPD_RED);
    display.fillRect(79,108,4,2,GxEPD_RED); display.fillRect(78,110,5,1,GxEPD_RED);
    display.fillRect(77,111,6,1,GxEPD_RED); display.fillRect(77,112,4,1,GxEPD_RED);
    display.fillRect(148,92,7,3,GxEPD_RED); display.fillRect(148,95,6,1,GxEPD_RED);
    display.fillRect(147,96,7,1,GxEPD_RED); display.fillRect(147,97,6,3,GxEPD_RED);
    display.fillRect(147,100,5,3,GxEPD_RED); display.fillRect(146,103,5,5,GxEPD_RED);
    display.fillRect(146,108,3,1,GxEPD_RED); display.fillRect(145,109,4,2,GxEPD_RED);
    display.fillRect(144,111,5,2,GxEPD_RED); display.fillRect(143,113,6,1,GxEPD_RED);
  }
}/* (End) 고기 부위 고르기 */

/*행사 기간 출력 */
void event() //행사 시 추가사항
{
  display.drawExampleBitmap(arrow, 260, 200, 120, 40, GxEPD_RED);
  display.drawExampleBitmap(sale_super, 18, 242, 160, 40, GxEPD_RED);
  display.setCursor(280 ,210);
  showfreeFont("6,000", &FreeSans12pt7b,GxEPD_BLACK);
  display.setCursor(260, 260);
  showfreeFont("5,000",&FreeSansBold24pt7b,GxEPD_RED);
  display.setCursor(230,290);
  showfreeFont("19.08.25 ~ 19.08.29",&FreeSans9pt7b,GxEPD_BLACK);
}

/*(End) for screen5_cow() */

/* (Start) Print Font function */
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
/* (Start) Print Font function */

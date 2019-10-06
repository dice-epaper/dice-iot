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
void screen0_under(){
    /* (처음) 기본 행사 없을 때 아무 그림도 안 띄움 */
  //display.fillScreen(GxEPD_WHITE);
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
  display.setRotation(0);
  display.drawExampleBitmap(qrcode_deco, 263, 13, 124, 124 ,GxEPD_RED);
  display.drawExampleBitmap(qrcode, 275, 25, 100, 100, GxEPD_WHITE);
  display.setCursor(20, 30);
  showfreeFont("before",&FreeSansBold12pt7b,GxEPD_WHITE);
  
  //int minToInt = int(min);
  String minToInt = String(min);
  Serial.print(minToInt);
  Serial.print(" 길이 is : ");
  Serial.println(minToInt.length());
  
  if(minToInt.length() <= 1 ){
    Serial.print("10 보다 작음(1의 자리) : ");
    Serial.println(minToInt);
    display.setCursor(100, 140);
    showFont(min,u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
  }
  else if(minToInt.length() == 2 ){
    Serial.print("큼(10의자리) : ");
    Serial.println(minToInt);
    display.setCursor(40, 140);
    showFont(min,u8g2_font_logisoso92_tn,GxEPD_WHITE,GxEPD_RED);
  }

  display.setCursor(170,130);
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
/* (End) Print screen function */

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

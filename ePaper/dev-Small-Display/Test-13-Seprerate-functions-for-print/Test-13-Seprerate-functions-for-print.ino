#include <GxEPD.h>
//#include <GxFont_GFX.h>
//#include <Adafruit_GFX.h>

#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r

#include "Image_SALE.h"
//#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
/*#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/Org_01.h>*/

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)
#endif

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");

  /*Display Test*/
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(0, 0);
  showFont("바나나 2송이 250g [Dole] 하이하이하이하이하이ㅎ", u8g2_font_unifont_t_korean1);
  //display.setCursor(0, 20);
  //showFont("100G당 1,432원", u8g2_font_unifont_t_korean1);
  //display.println("honey almond 210g");
  //display.setTextColor(GxEPD_DARKGREY);
  //display.setFont(&Org_01);
  //display.setCursor(10,40);
  //display.println("1895won/100g");
  display.setRotation(0);
  showBitmapExample();
  display.update();
}

void loop()
{
  //
}


#define HAS_RED_COLOR
void showBitmapExample()
{
  display.drawExampleBitmap(Image_SALE, 10, 10, 40, 40, GxEPD_RED);
  delay(500);
  display.update();
}

void showFont(const char name[], const uint8_t *f)
{
  Serial.println("I am here");
  display.setRotation(1);
  //display.fillScreen(GxEPD_WHITE);
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  //display.setCursor(0, 0);
  display.println();
  display.println(name);
  //display.update();
}

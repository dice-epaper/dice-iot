#include <GxEPD.h>
#include <GxFont_GFX.h>

#include <GxEPD.h>
#include <Adafruit_GFX.h>

#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/Org_01.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.4.2\variants\generic\common.h

GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)
// Heltec E-Paper 1.54" b/w without RST, BUSY
//GxEPD_Class display(io, /*RST=D4*/ -1, /*BUSY=D2*/ -1); // no RST, no BUSY

#endif


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");
}

void loop()
{
  showBitmapExample();
  delay(10000);
  display.update();
}

#if defined(_GxGDEW0213Z16_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  display.init();
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeSansBold9pt7b);
  display.setCursor(0, 0);
  display.println();
  display.setCursor(10,20);
  display.println("honey almond 210g");
  display.setTextColor(GxEPD_DARKGREY);
  display.setFont(&Org_01);
  display.setCursor(10,40);
  display.println("1895won/100g");
  display.setRotation(0);
  display.drawExampleBitmap(minjoo, 10, 10, 40, 40, GxEPD_RED);
  delay(500);
  display.update();
}
#endif

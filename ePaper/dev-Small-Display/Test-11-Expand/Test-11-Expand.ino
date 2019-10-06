// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r


#if !defined(_GxFont_GFX_TFT_eSPI_H_)
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
//#include <Fonts/FreeMonoBold18pt7b.h>
//#include <Fonts/FreeMonoBold24pt7b.h>
#endif
#if defined(_ADAFRUIT_TF_GFX_H_)
#include <Fonts/Open_Sans_Bold_12pt.h>
#endif


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>


#if defined(ESP8266)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.4.2\variants\generic\common.h

GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io /*RST=D4*/ /*BUSY=D2*/); // default selection of D4(=2), D2(=4)


#endif

#if defined(_GxGDEW0154Z04_H_) || defined(_GxGDEW0213Z16_H_) || defined(_GxGDEW029Z10_H_) || defined(_GxGDEW027C44_H_) || defined(_GxGDEW042Z15_H_) || defined(_GxGDEW075Z09_H_)
#define HAS_RED_COLOR
#endif

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");

//  Serial.print("가",HEX)
}

void loop()
{
#if !defined(_ADAFRUIT_TF_GFX_H_) && !defined(_GxFont_GFX_TFT_eSPI_H_) && !defined(U8g2_for_Adafruit_GFX_h)
  showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
#endif
#if defined(U8g2_for_Adafruit_GFX_h)
  //showFont("u8g2_font_helvR14_tf", u8g2_font_unifont_t_korean2);// u8g2_font_helvR14_tf); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  //delay(2000);
  //showFont("u8g2_font_profont22_mr", u8g2_font_profont22_mr); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  //delay(2000);
#endif
#if defined(_GxFont_GFX_TFT_eSPI_H_)
  Serial.println(5);
#endif
#if defined(_ADAFRUIT_TF_GFX_H_)
  showFont("Open_Sans_Bold_12pt", OPENSANSBOLD_12);
#endif
  delay(10000);
}

void showFont(const char name[], const GFXfont* f)
{
Serial.println(4);
}

#if defined(U8g2_for_Adafruit_GFX_h)
void showFont(const char name[], const uint8_t *f)
{
  Serial.println("I am here");
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  display.setFontDirection(0);              // left to right (this is default)
  display.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  display.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.setCursor(0, 0);
  display.println();
  //display.println(name);

/*#if defined(HAS_RED_COLOR)
  display.setForegroundColor(GxEPD_RED);
#endif*/
  //display.println("Umlaut ÄÖÜäéöü");
  display.println("드디어!");
  display.println("한글 출력되요!!");
  display.println("다이스 팀 힘냅시다!!");
  display.update();
}
#endif

#if defined(_ADAFRUIT_TF_GFX_H_)
void showFont(const char name[], uint8_t f)
{
Serial.println(3);
}
#endif

#if defined(_GxFont_GFX_TFT_eSPI_H_)
void showFreeFont(const char name[], const GFXfont* f)
{
 Serial.println(2);
}
void showTextFont(const char name[], uint8_t f, uint8_t size)
{
Serial.println(1);
}
#endif

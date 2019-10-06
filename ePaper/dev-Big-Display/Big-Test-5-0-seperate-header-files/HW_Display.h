
#ifndef HW_Display_h
#define HW_Display_h

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


/* Function Define*/
void firstscreen_timesale();

void secondscreen_discount();

void thirdscreen_default();

void showFont(const char name[], const uint8_t *f,uint16_t foreColor,uint16_t backColor);

void showfreeFont(const char name[], const GFXfont* f, uint16_t color);



#endif

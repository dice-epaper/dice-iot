
/* Display Setting */
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>
#include "Image_SALE_Big_Display.h"

// function call
void call_display_init();
void call_display_update();

// screens
void setup_screen();
void screen_magam(const char min[]);
void firstscreen_timesale();
void secondscreen_discount();
void thirdscreen_default();

// print font
void showFont(const char name[], const uint8_t *f,uint16_t foreColor,uint16_t backColor);
void showfreeFont(const char name[], const GFXfont* f, uint16_t color);

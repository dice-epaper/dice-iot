
/* Display Setting */
#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <Adafruit_GFX.h>

#include "IMG_SALE.h"
#include "IMG_ARROW.h"
#include "IMG_QR.h"
#include "IMG_WINE_n_MEAT.h"

/* Call basic function */
void call_display_init();
void call_display_update();

/* Print screen function */
void screen0_under();
void screen1_default();
void screen2_discount();
void screen3_magam_Over();
void screen3_magam(const char min[]);
void screen4_wine();
void screen5_cow();

/*for screen5_cow() */
void base_layout();
void select_grade(int grade);
void fill_table_else(int origin, int use, int deliverNum);
void select_meat_part(int partNum);
void event();

/* Print Font function */
void showFont(const char name[], const uint8_t *f,uint16_t foreColor,uint16_t backColor);
void showfreeFont(const char name[], const GFXfont* f, uint16_t color);

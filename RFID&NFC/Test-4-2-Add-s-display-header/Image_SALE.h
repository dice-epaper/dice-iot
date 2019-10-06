
#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

/* Caution!! Size is (40*40) OR (120*40) */
// showBitmap( "banana", 10, 10, 40, 40 );
// showBitmap( "arrow", 70, 55, 120, 40 );

/*세일 종류*/
// 멤버별 : sale_vip
// 세일별 : sale_super ,sale_magam, sale_1plus1, sale_2plus1
// 세일 작대기 : arrow 
const unsigned char sale_super[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xfe,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0xce,0x00,0x30,0x02,
  0x41,0xcf,0x00,0x30,0x02,
  0x43,0x9b,0x80,0x30,0x02,
  0x43,0x19,0x81,0xb7,0xfa,
  0x43,0x31,0x81,0xb7,0xfa,
  0x43,0xb3,0x81,0xb6,0xda,
  0x41,0xe7,0x01,0xb6,0xda,
  0x40,0xe6,0x01,0xb6,0xda,
  0x43,0x00,0x01,0xb6,0xda,
  0x43,0xc0,0x01,0xb6,0xda,
  0x41,0xf8,0x01,0xb6,0xda,
  0x40,0x7e,0x01,0xb6,0xda,
  0x40,0x67,0x0f,0xb6,0xda,
  0x40,0x67,0x0f,0xb6,0xda,
  0x40,0x7e,0x00,0x30,0x02,
  0x40,0xf8,0x00,0x30,0x02,
  0x43,0xc0,0x00,0x30,0x02,
  0x43,0x00,0x00,0x00,0x02,
  0x40,0x00,0x06,0x00,0xc2,
  0x43,0xff,0x06,0x00,0xc2,
  0x43,0xff,0x07,0x00,0xc2,
  0x43,0x00,0x03,0x80,0xc2,
  0x43,0x00,0x01,0xe0,0xc2,
  0x43,0x00,0x00,0xf8,0xc2,
  0x43,0x00,0x00,0x3e,0xc2,
  0x43,0x00,0x00,0x0f,0xc2,
  0x40,0x00,0x00,0x03,0xc2,
  0x43,0xff,0x00,0x00,0x02,
  0x43,0xff,0x00,0x00,0x02,
  0x43,0x33,0x0f,0xff,0xfa,
  0x43,0x33,0x0f,0xff,0xfa,
  0x43,0x33,0x00,0x0c,0x02,
  0x43,0x33,0x00,0x0c,0x02,
  0x43,0x33,0x00,0x0c,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x7f,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_vip[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xfe,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0xce,0x00,0x00,0x02,
  0x41,0xdf,0x00,0x00,0x02,
  0x43,0x9b,0x80,0x00,0xc2,
  0x43,0x19,0x80,0x03,0xc2,
  0x43,0x31,0x80,0x0f,0xc2,
  0x43,0xb3,0x80,0x3f,0x82,
  0x41,0xe7,0x00,0xfe,0x02,
  0x40,0xe6,0x03,0xf8,0x02,
  0x43,0x00,0x07,0xe0,0x02,
  0x43,0xc0,0x07,0x80,0x02,
  0x41,0xf8,0x07,0xe0,0x02,
  0x40,0x7e,0x03,0xf8,0x02,
  0x40,0x67,0x00,0xfe,0x02,
  0x40,0x67,0x00,0x3f,0x82,
  0x40,0x7e,0x00,0x0f,0xc2,
  0x40,0xf8,0x00,0x03,0xc2,
  0x43,0xc0,0x00,0x00,0xc2,
  0x43,0x00,0x00,0x00,0x02,
  0x40,0x00,0x07,0xff,0xc2,
  0x43,0xff,0x07,0xff,0xc2,
  0x43,0xff,0x07,0xff,0xc2,
  0x43,0x00,0x00,0x00,0x02,
  0x43,0x00,0x07,0xff,0xc2,
  0x43,0x00,0x07,0xff,0xc2,
  0x43,0x00,0x07,0xff,0xc2,
  0x43,0x00,0x00,0x39,0xc2,
  0x40,0x00,0x00,0x39,0xc2,
  0x43,0xff,0x00,0x39,0xc2,
  0x43,0xff,0x00,0x39,0xc2,
  0x43,0x33,0x00,0x3f,0xc2,
  0x43,0x33,0x00,0x1f,0x82,
  0x43,0x33,0x00,0x0f,0x02,
  0x43,0x33,0x00,0x00,0x02,
  0x43,0x33,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x7f,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_magam[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xfe,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0xce,0x00,0xff,0xc2,
  0x41,0xcf,0x00,0xff,0xc2,
  0x43,0x9b,0x80,0xc0,0xc2,
  0x43,0x19,0x80,0xc0,0xc2,
  0x43,0x31,0x80,0xc0,0xc2,
  0x43,0xb3,0x80,0xc0,0xc2,
  0x41,0xe7,0x00,0xc0,0xc2,
  0x40,0xe6,0x00,0xff,0xc2,
  0x43,0x00,0x00,0xff,0xc2,
  0x43,0xc0,0x00,0x00,0x02,
  0x41,0xf8,0x00,0x00,0x02,
  0x40,0x7e,0x0f,0xff,0xe2,
  0x40,0x67,0x0f,0xff,0xe2,
  0x40,0x67,0x00,0x18,0x02,
  0x40,0x7e,0x00,0x18,0x02,
  0x40,0xf8,0x00,0x18,0x02,
  0x43,0xc0,0x00,0x00,0x02,
  0x43,0x00,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x43,0xff,0x00,0x18,0x62,
  0x43,0xff,0x0f,0xd8,0x62,
  0x43,0x00,0x0f,0xdc,0x62,
  0x43,0x00,0x0c,0xce,0x62,
  0x43,0x00,0x0c,0xc7,0x62,
  0x43,0x00,0x0c,0xc3,0xe2,
  0x43,0x00,0x0c,0xc1,0xe2,
  0x40,0x00,0x0c,0xc0,0xe2,
  0x43,0xff,0x0c,0xc0,0x02,
  0x43,0xff,0x0c,0xc0,0x02,
  0x43,0x33,0x0f,0xdf,0xe2,
  0x43,0x33,0x0f,0xdf,0xe2,
  0x43,0x33,0x00,0x03,0x02,
  0x43,0x33,0x00,0x03,0x02,
  0x43,0x33,0x00,0x03,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x7f,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_1plus1[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xfe,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x03,0x80,0x02,
  0x40,0x00,0x03,0xc0,0x02,
  0x40,0x00,0x01,0xe0,0x02,
  0x40,0x00,0x00,0xf0,0x02,
  0x40,0x00,0x00,0x78,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x07,0xff,0xc0,0x02,
  0x40,0x07,0xff,0xc0,0x02,
  0x40,0x07,0xff,0xc0,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x38,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x03,0x80,0x02,
  0x40,0x00,0x03,0xc0,0x02,
  0x40,0x00,0x01,0xe0,0x02,
  0x40,0x00,0x00,0xf0,0x02,
  0x40,0x00,0x00,0x78,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x7f,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_2plus1[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xfe,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x1f,0x00,0xe0,0x02,
  0x40,0x1f,0x80,0xf0,0x02,
  0x40,0x1f,0xc0,0xf8,0x02,
  0x40,0x1d,0xe0,0x3c,0x02,
  0x40,0x1c,0xf0,0x1c,0x02,
  0x40,0x1c,0x70,0x1c,0x02,
  0x40,0x1c,0x38,0x1c,0x02,
  0x40,0x1c,0x3c,0x3c,0x02,
  0x40,0x1c,0x1e,0x78,0x02,
  0x40,0x1c,0x0f,0xf0,0x02,
  0x40,0x1c,0x07,0xe0,0x02,
  0x40,0x00,0x01,0xc0,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x01,0xff,0xe0,0x02,
  0x40,0x01,0xff,0xe0,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x0c,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x40,0x00,0x01,0xc0,0x02,
  0x40,0x00,0x01,0xe0,0x02,
  0x40,0x00,0x00,0xf0,0x02,
  0x40,0x00,0x00,0x78,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x1f,0xff,0xf8,0x02,
  0x40,0x00,0x00,0x00,0x02,
  0x7f,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,
};


const unsigned char arrow[] PROGMEM = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x03,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xfe,0x0f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xf8,0x3f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xf0,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x41,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x03,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x07,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0f,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x07,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x03,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x00,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x00,0x7f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};
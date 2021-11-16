
#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

const unsigned char sale_super[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x00,0x0e,0x00,0x00,0x0f,0xf0,0x00,0x38,0x00,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x03,0x80,0x00,0x01,0xff,0xfc,0x0e,0x00,0x00,0x1f,0xfc,0x00,0x7c,0x00,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x03,0xff,0xff,0x01,0xff,0xfc,0x0e,0x00,0x00,0x3f,0xfe,0x00,0x7c,0x00,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x03,0xff,0xff,0x01,0xff,0xfc,0x0e,0x00,0x00,0x78,0x1f,0x00,0x7c,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x1c,0x0e,0x00,0x00,0x70,0x07,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0x80,0x00,0x00,0x00,0x1c,0x0e,0x00,0x00,0x70,0x03,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x38,0x0e,0x00,0x00,0x70,0x00,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x38,0x0e,0x00,0x00,0x78,0x00,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x00,0x38,0x0e,0x00,0x00,0x3c,0x00,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x70,0x0f,0xf0,0x00,0x3f,0x80,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x70,0x0f,0xf0,0x00,0x0f,0xf8,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x3f,0xff,0xff,0xf0,0x00,0xe0,0x0f,0xf0,0x00,0x03,0xfe,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x3f,0xff,0xff,0xf0,0x01,0xe0,0x0e,0x00,0x00,0x00,0x3f,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x06,
  0x60,0x3f,0xff,0xff,0xf0,0x03,0xc0,0x0e,0x00,0x00,0x00,0x07,0x07,0xff,0xc0,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x07,0x80,0x0e,0x00,0x00,0xe0,0x03,0x87,0xff,0xc0,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x0f,0x00,0x0e,0x00,0x00,0xe0,0x03,0x8f,0xff,0xe0,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x1e,0x00,0x0e,0x00,0x00,0xf0,0x03,0x8e,0x00,0xe0,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0x7c,0x00,0x0e,0x00,0x00,0x70,0x03,0x8e,0x00,0xe0,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x03,0xff,0xff,0x00,0xf8,0x00,0x0e,0x00,0x00,0x7c,0x0f,0x1c,0x00,0x70,0xe0,0x00,0xe0,0x00,0x06,
  0x60,0x00,0x00,0x07,0x00,0xe0,0x00,0x0e,0x00,0x00,0x3f,0xff,0x1c,0x00,0x70,0xff,0xfc,0xff,0xfc,0x06,
  0x60,0x00,0x00,0x07,0x00,0x00,0x00,0x0e,0x00,0x00,0x1f,0xfe,0x38,0x00,0x38,0xff,0xfc,0xff,0xfc,0x06,
  0x60,0x00,0x00,0x07,0x00,0x00,0x00,0x0e,0x00,0x00,0x07,0xf8,0x38,0x00,0x38,0xff,0xfc,0xff,0xfc,0x06,
  0x60,0x00,0x00,0x07,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x07,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_vip[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0xe0,0x03,0x87,0x0f,0xff,0x00,0x00,0x0f,0xf0,0x00,0x38,0x00,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0xe0,0x03,0x87,0x0f,0xff,0xc0,0x00,0x1f,0xfc,0x00,0x7c,0x00,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0xe0,0x03,0x87,0x0f,0xff,0xc0,0x00,0x3f,0xfe,0x00,0x7c,0x00,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x70,0x07,0x07,0x0e,0x01,0xe0,0x00,0x78,0x1f,0x00,0x7c,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x70,0x07,0x07,0x0e,0x00,0xe0,0x00,0x70,0x07,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x70,0x07,0x07,0x0e,0x00,0xe0,0x00,0x70,0x03,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x38,0x0e,0x07,0x0e,0x00,0xe0,0x00,0x70,0x00,0x00,0xee,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x38,0x0e,0x07,0x0e,0x00,0xe0,0x00,0x78,0x00,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x38,0x0e,0x07,0x0e,0x00,0xe0,0x00,0x3c,0x00,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x1c,0x07,0x0e,0x01,0xe0,0x00,0x3f,0x80,0x01,0xc7,0x00,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x1c,0x07,0x0f,0xff,0xc0,0x00,0x0f,0xf8,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x1c,0x1c,0x07,0x0f,0xff,0x80,0x00,0x03,0xfe,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x0e,0x38,0x07,0x0f,0xff,0x00,0x00,0x00,0x3f,0x03,0x83,0x80,0xe0,0x00,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x0e,0x38,0x07,0x0e,0x00,0x00,0x00,0x00,0x07,0x07,0xff,0xc0,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x0e,0x38,0x07,0x0e,0x00,0x00,0x00,0xe0,0x03,0x87,0xff,0xc0,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x07,0x70,0x07,0x0e,0x00,0x00,0x00,0xe0,0x03,0x8f,0xff,0xe0,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x07,0x70,0x07,0x0e,0x00,0x00,0x00,0xf0,0x03,0x8e,0x00,0xe0,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x07,0x70,0x07,0x0e,0x00,0x00,0x00,0x70,0x03,0x8e,0x00,0xe0,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x03,0xe0,0x07,0x0e,0x00,0x00,0x00,0x7c,0x0f,0x1c,0x00,0x70,0xe0,0x00,0xe0,0x00,0x00,0x06,
  0x60,0x00,0x03,0xe0,0x07,0x0e,0x00,0x00,0x00,0x3f,0xff,0x1c,0x00,0x70,0xff,0xfc,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x03,0xe0,0x07,0x0e,0x00,0x00,0x00,0x1f,0xfe,0x38,0x00,0x38,0xff,0xfc,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x01,0xc0,0x07,0x0e,0x00,0x00,0x00,0x07,0xf8,0x38,0x00,0x38,0xff,0xfc,0xff,0xfc,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_magam[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0xff,0xfc,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0xff,0xfc,0x0e,0x00,0x00,0x1f,0xe0,0x00,0x70,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x00,0x00,0x03,0x80,0xff,0xfc,0x0e,0x00,0x00,0x3f,0xf8,0x00,0xf8,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x00,0x1c,0x0e,0x00,0x00,0x7f,0xfc,0x00,0xf8,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x00,0x1c,0x0e,0x00,0x00,0xf0,0x3e,0x00,0xf8,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x00,0x38,0x0e,0x00,0x00,0xe0,0x0e,0x01,0xdc,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0x80,0x00,0x38,0x0f,0xe0,0x00,0xe0,0x06,0x01,0xdc,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0x80,0x00,0x70,0x0f,0xe0,0x00,0xe0,0x00,0x01,0xdc,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0x80,0x00,0xf0,0x0f,0xe0,0x00,0xf0,0x00,0x03,0x8e,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0x80,0x01,0xe0,0x0e,0x00,0x00,0x78,0x00,0x03,0x8e,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0xf8,0x07,0xc0,0x0e,0x00,0x00,0x7f,0x00,0x03,0x8e,0x01,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1c,0x03,0x83,0xf8,0x1f,0x00,0x0e,0x00,0x00,0x1f,0xf0,0x07,0x07,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x1c,0x03,0x83,0xf8,0x7c,0x00,0x0e,0x00,0x00,0x07,0xfc,0x07,0x07,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x1c,0x03,0x83,0x80,0xf8,0x00,0x0e,0x00,0x00,0x00,0x7e,0x07,0x07,0x01,0xc0,0x01,0xff,0xf8,0x06,
  0x60,0x1c,0x03,0x83,0x80,0xe0,0x00,0x00,0x00,0x00,0x00,0x0e,0x0f,0xff,0x81,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x0f,0xff,0xfe,0x00,0x01,0xc0,0x07,0x0f,0xff,0x81,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x0f,0xff,0xfe,0x00,0x01,0xc0,0x07,0x1f,0xff,0xc1,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x1f,0xff,0x83,0x80,0x0f,0xff,0xfe,0x00,0x01,0xe0,0x07,0x1c,0x01,0xc1,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0e,0x00,0x0e,0x00,0x00,0xe0,0x07,0x1c,0x01,0xc1,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0e,0x00,0x0e,0x00,0x00,0xf8,0x1e,0x38,0x00,0xe1,0xc0,0x01,0xc0,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0e,0x00,0x0e,0x00,0x00,0x7f,0xfe,0x38,0x00,0xe1,0xff,0xf9,0xff,0xf8,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0e,0x00,0x0e,0x00,0x00,0x3f,0xfc,0x70,0x00,0x71,0xff,0xf9,0xff,0xf8,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0f,0xff,0xfe,0x00,0x00,0x0f,0xf0,0x70,0x00,0x71,0xff,0xf9,0xff,0xf8,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x03,0x80,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_1plus1[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x00,0x00,0x03,0x80,0x00,0x01,0xfe,0x00,0x07,0x00,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x3c,0x00,0x00,0x00,0x07,0x80,0x00,0x03,0xff,0x80,0x0f,0x80,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x7c,0x00,0x0e,0x00,0x0f,0x80,0x00,0x07,0xff,0xc0,0x0f,0x80,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0xfc,0x00,0x0e,0x00,0x1f,0x80,0x00,0x0f,0x03,0xe0,0x0f,0x80,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x01,0xfc,0x00,0x0e,0x00,0x3f,0x80,0x00,0x0e,0x00,0xe0,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0xdc,0x00,0x0e,0x00,0x7b,0x80,0x00,0x0e,0x00,0x60,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0x9c,0x00,0x0e,0x00,0x73,0x80,0x00,0x0e,0x00,0x00,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x0f,0x00,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x07,0x80,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x07,0xff,0xfc,0x03,0x80,0x00,0x07,0xf0,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x07,0xff,0xfc,0x03,0x80,0x00,0x01,0xff,0x00,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x1c,0x07,0xff,0xfc,0x03,0x80,0x00,0x00,0x7f,0xc0,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x00,0x07,0xe0,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x00,0x00,0xe0,0xff,0xf8,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x1c,0x00,0x70,0xff,0xf8,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x1c,0x00,0x71,0xff,0xfc,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x1e,0x00,0x71,0xc0,0x1c,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x0e,0x00,0x71,0xc0,0x1c,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x0e,0x00,0x03,0x80,0x00,0x0f,0x81,0xe3,0x80,0x0e,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x1c,0x00,0x00,0x00,0x03,0x80,0x00,0x07,0xff,0xe3,0x80,0x0e,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x00,0x1c,0x00,0x00,0x00,0x03,0x80,0x00,0x03,0xff,0xc7,0x00,0x07,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x07,0x00,0x07,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char sale_2plus1[] PROGMEM =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x3f,0x80,0x00,0x00,0x00,0x00,0x00,0x01,0xfe,0x00,0x07,0x00,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x7f,0xe0,0x00,0x00,0x01,0xc0,0x00,0x03,0xff,0x80,0x0f,0x80,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0xf1,0xe0,0x00,0x00,0x03,0xc0,0x00,0x07,0xff,0xc0,0x0f,0x80,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x01,0xe0,0x70,0x00,0x00,0x07,0xc0,0x00,0x0f,0x03,0xe0,0x0f,0x80,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x01,0xc0,0x78,0x07,0x00,0x0f,0xc0,0x00,0x0e,0x00,0xe0,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0x80,0x38,0x07,0x00,0x1f,0xc0,0x00,0x0e,0x00,0x60,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0x80,0x38,0x07,0x00,0x3d,0xc0,0x00,0x0e,0x00,0x00,0x1d,0xc0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x00,0x38,0x07,0x00,0x39,0xc0,0x00,0x0f,0x00,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x00,0x70,0x07,0x00,0x01,0xc0,0x00,0x07,0x80,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x00,0x70,0x07,0x00,0x01,0xc0,0x00,0x07,0xf0,0x00,0x38,0xe0,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x01,0xe1,0xff,0xfc,0x01,0xc0,0x00,0x01,0xff,0x00,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x03,0xe1,0xff,0xfc,0x01,0xc0,0x00,0x00,0x7f,0xc0,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x0f,0x81,0xff,0xfc,0x01,0xc0,0x00,0x00,0x07,0xe0,0x70,0x70,0x1c,0x00,0x1f,0xff,0x80,0x06,
  0x60,0x00,0x1e,0x00,0x07,0x00,0x01,0xc0,0x00,0x00,0x00,0xe0,0xff,0xf8,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0x3c,0x00,0x07,0x00,0x01,0xc0,0x00,0x1c,0x00,0x70,0xff,0xf8,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x00,0xf8,0x00,0x07,0x00,0x01,0xc0,0x00,0x1c,0x00,0x71,0xff,0xfc,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x01,0xf0,0x00,0x07,0x00,0x01,0xc0,0x00,0x1e,0x00,0x71,0xc0,0x1c,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0xc0,0x00,0x07,0x00,0x01,0xc0,0x00,0x0e,0x00,0x71,0xc0,0x1c,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0x80,0x00,0x07,0x00,0x01,0xc0,0x00,0x0f,0x81,0xe3,0x80,0x0e,0x1c,0x00,0x1c,0x00,0x00,0x06,
  0x60,0x03,0xff,0xf8,0x00,0x00,0x01,0xc0,0x00,0x07,0xff,0xe3,0x80,0x0e,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x03,0xff,0xf8,0x00,0x00,0x01,0xc0,0x00,0x03,0xff,0xc7,0x00,0x07,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x03,0xff,0xf8,0x00,0x00,0x01,0xc0,0x00,0x00,0xff,0x07,0x00,0x07,0x1f,0xff,0x9f,0xff,0x80,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
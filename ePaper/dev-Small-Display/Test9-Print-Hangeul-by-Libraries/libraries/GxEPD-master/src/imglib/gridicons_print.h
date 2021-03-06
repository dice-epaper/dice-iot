#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_print
const unsigned char gridicons_print[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFC, 0x00, 0x3F, 0xF8, 0x00, 0x1F, 0xF9, 
0xFF, 0x9F, 0xF9, 0xFF, 0x9F, 0xE0, 0x00, 0x07, 
0xC0, 0x00, 0x03, 0xC4, 0x00, 0x03, 0xCE, 0x00, 
0x03, 0xC4, 0x00, 0x03, 0xC0, 0x00, 0x03, 0xC0, 
0x00, 0x03, 0xC1, 0xFF, 0x83, 0xC1, 0xFF, 0x83, 
0xC1, 0x81, 0x83, 0xF9, 0x81, 0x9F, 0xF9, 0xFF, 
0x9F, 0xF9, 0xFF, 0x9F, 0xF8, 0x00, 0x1F, 0xFC, 
0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

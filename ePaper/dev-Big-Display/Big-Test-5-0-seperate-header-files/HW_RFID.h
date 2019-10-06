/* RFID Setting */

#ifndef HW_RFID_h
#define HW_Display_h

#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

/* 등록된 RF CARD ID */

/* 4개 숫자 말고 첫 숫자로만 파악하기
#define PICC_0 0xD9 
#define PICC_1 0xAD
#define PICC_2 0xC8
#define PICC_3 0x55 */

/* UID의 첫 숫자로만 파악하기 */
int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
    {0xC9, 0xAA, 0x54, 0x47}, //member2 선미's token
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 민주's Card
    {0xA9, 0x30, 0x50, 0x47} //member4 민주's token
  };

#endif

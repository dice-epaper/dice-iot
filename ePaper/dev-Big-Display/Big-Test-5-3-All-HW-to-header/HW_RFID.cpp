#include "HW_RFID.h"

/* RFID Setting */
#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

/* 등록된 RF CARD ID */

/* UID의 첫 숫자로만 파악하기 */
int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card
    {0xC9, 0xAA, 0x54, 0x47}, //member2 선미's token
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 민주's Card
    {0xA9, 0x30, 0x50, 0x47} //member4 민주's token
  };

void call_rfid_PCD_Init(){
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작
}

int get_memberNum(){

}

int check_is_Read_RFID(){
  int memberNum = 0;
  
  // 카드가 인식 안 되었다면 더이상 진행하지 말고 빠져나감
  if ( ! rfid.PICC_IsNewCardPresent())
    return 0;

  //RF카드의 ID가 인식 안되었다면 더이상 진행하지 x말고 빠져나감
  if ( ! rfid.PICC_ReadCardSerial())
    return 0;
    
  Serial.print(F("PICC type: "));
  //PICC 타입 읽어오기
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));  
  
  //MIFARE 방식이 아니라면 더이상 진행하지 말고 빠져나감
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return 0;
  }

  for (int i = 0; i <= 3; i++) {
    if( rfid.uid.uidByte[0] == memberCards[i][0] ){
      memberNum = i+1;
      Serial.print("member is ");  
      Serial.println(memberNum); 
      return memberNum;
    }
  }
  
  //등록되지 않은 uid 이면
  return 0;
}

void stop_Read_RFID(){
  
  //종료 
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  Serial.println("RFID Read Stop");
  //다시 시작!
}

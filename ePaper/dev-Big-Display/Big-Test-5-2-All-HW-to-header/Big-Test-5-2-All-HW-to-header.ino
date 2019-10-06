// This is for Big Display format !!

#include "HW_Display.h"
#include "HW_DFPlayer.h"
#include "HW_RFID.h"


void setup()
{
  Serial.begin(9600); //Serial Monitor 시작
  
  call_DFPlayer_setup();
  call_display_init();
  
  SPI.begin(); // SPI 시작
  //rfid.PCD_Init(); // RF 모듈 시작
  call_rfid_PCD_Init();
  Serial.println("setup done");


  Serial.println(memberCards[0][0]);
  
  //setup_screen();
  //call_display_update();
}

void loop()
{
  /*
  // 카드가 인식 안 되었다면 더이상 진행하지 말고 빠져나감
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  //RF카드의 ID가 인식 안되었다면 더이상 진행하지 x말고 빠져나감
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  //PICC 타입 읽어오기
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));


  //MIFARE 방식이 아니라면 더이상 진행하지 말고 빠져나감
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  */

  
  // RFID 태그 인식 ok -> UID check -> 처음 숫자만 보기!
      /*
  int memberNum = get_memberNum();
  
  if(memberNum == NULL){
      Serial.println(F("This Card doesn't enroll."));   
  }

  // tagging Card ID가 1번, 4번이면
  else if (memberNum == 1 || memberNum == 3) {
    call_myDFPlayer_play(1);
    firstscreen_timesale();
    call_display_update();
  }
    
  // tagging Card ID가 2번, 4번이면
  else if(memberNum == 2 || memberNum == 4){
    call_myDFPlayer_play(2);
    secondscreen_discount();
    call_display_update();
  }
  

  //종료

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  //다시 시작!

  */
  
}

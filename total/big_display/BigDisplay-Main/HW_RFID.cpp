#include "HW_RFID.h"
#include "SW_Timer.h"
#include "HW_DFPlayer.h"
#include "HW_Display.h"

/* RFID Setting */
#include <SPI.h>    // RFID를 위한 SPI 라이브러
#include <MFRC522.h>// RFID 라이브러
#define SS_PIN 15   //RFID SS(SDA:ChipSelect) PIN
#define RST_PIN 2   //RFID Reset PIN
MFRC522 rfid(SS_PIN, RST_PIN); //RFID 라이브러리

/* 등록된 RF CARD ID */

/* UID의 첫 숫자로만 파악하기 */
int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 (Card)
    {0xC9, 0xAA, 0x54, 0x47}, //member2 (Token)
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 (Card)
    {0xA9, 0x30, 0x50, 0x47} //member4 (Token)
  };

/*RFID 장치 시작(Setup)*/
void call_rfid_PCD_Init(){
  SPI.begin(); // SPI 시작
  rfid.PCD_Init(); // RF 모듈 시작
}

/*RFID 태그 여부 확인*/
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

/*RFID 인식 종료*/
void call_rifd_PCD_StopCrypto1(){
  
  //종료 
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  Serial.println("RFID Read Stop");
  //다시 시작!
}

/* Tagging 으로 작동하는 함수 */
/* 멤버별 Sale 화면을 다르게 출력한다
 * (예시)
 * member 1, 3은 magam Sale 화면을 출력한다. 
 * member 2, 4는 와인 상품 화면을 출력한다.
 */
void activ_By_Member(int memberNum){
  if(memberNum == 0){
      Serial.println(F("This Card doesn't enroll."));   
  }
  
  /*(Start) memberNum 1 OR 3 */
  else if (memberNum == 1 || memberNum == 3) {
 
    withTimer();
  }
  /*(End) memberNum 1 OR 3 */
    
  /*(Start) memberNum 2 OR 4 */
  else if(memberNum == 2 || memberNum == 4){
    call_myDFPlayer_play(2);
    screen4_wine();
    call_display_update();
  }
  /*(Start) memberNum 2 OR 4 */
}

/*magam Sale 화면*/
void withTimer(){
  int memberNum;
  int remainMin = get_RemainMin();
  if(remainMin<=0){ // 마감 시간 Over 되었으면
    Serial.println("\n마감시간 Over");
    screen3_magam_Over();
    call_display_update();
    return;
  }
  for(int i= remainMin; i>0; i--){
    call_myDFPlayer_play(1);
    screen3_magam(String(i).c_str());
    call_display_update();
    boolean isTagging = false;
    for(int j= 46; j>=1; j--){ 
      memberNum = check_is_Read_RFID();
      Serial.print("I am in for(), memberNum is : ");
      Serial.println(memberNum);
      if(memberNum != 0){
        Serial.println("OUT this Timer for()");
        isTagging = true;
        break;
      }
      delay(1000);  
    }

    if(isTagging){ //중간 tagging 인 경우
      activ_By_Member(memberNum);
      return ; //바로 빠져나가기  
    }
    else{ //중간 Tagging 없이 Timer 0까지 갔으면 TIME OVER 
      screen3_magam_Over();
      call_display_update();
      return;
    }
    
  }
  return ;
}

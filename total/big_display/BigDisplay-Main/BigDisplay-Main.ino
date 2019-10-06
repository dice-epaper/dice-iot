/* This is for Big Display format !! */

/* 분리된 함수 모듈 사용을 위한 include 작업*/
#include "HW_Display.h"
#include "HW_DFPlayer.h"
#include "HW_RFID.h"
#include "SW_Timer.h"

void setup()
{
  Serial.begin(9600); //Serial Monitor 시작

  /*H/W 장치 ON(set up)*/
  call_DFPlayer_setup();
  call_display_init();
  call_rfid_PCD_Init();
  call_WIFI_setup("-", "-"); //ssid, password
  
  /* set thirdScreen_time sale
   * 받는 인수 : int year, int month, int day, int hour24, int min 
   * 마감시간은 Wifi가 연결되어 있고, 항상 현재 시간보다 커야 작동한다.
   * magam Sale에 작동 */
  
  //마감시간 : 2019년 9월 3일 23시 30분으로 지정
  set_magamTime(2019,9,3,23,30); 
  
  delay(5000);
  Serial.println("setup done");
  
  screen0_under();

  /* choose design among 5 design
  * screen1_default(); // 기본 화면
  * screen2_discount(); // 기본 Sale 화면
  * screen3_magam_Over(); // 마감 세일 (Time Over) 화면
  * screen3_magam(const char min[]); // 마감 세일 (작동) 화면
  * screen4_wine(); // 와인 상품 화면
  * screen5_cow(); //소고기 상품 화면
  */

  //아래는 screen1 ~ screen5 순차적으로 Print
  
  screen1_default();
  call_display_update();
  delay(2000);
  
  screen2_discount();
  call_display_update();
  delay(2000);

  screen3_magam("45");
  call_display_update();
  delay(2000);
  
  screen3_magam("9");
  call_display_update();
  delay(2000);
  
  screen4_wine();
  call_display_update();
  delay(2000);
  
  screen5_cow();  
  call_display_update();
  delay(2000);
 
}

void loop()
{

  // RFID 카드 태깅 멤버 확인
  int memberNum = check_is_Read_RFID();
  Serial.println(memberNum);
  
  // 멤버별 Sale 상이 적용
  activ_By_Member(memberNum);
  
  call_rifd_PCD_StopCrypto1();
  
  // Read 종료 후 재시작 (loop)
}

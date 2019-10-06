/* This is for Big Display format !! */

#include "HW_Display.h"
#include "HW_DFPlayer.h"
#include "HW_RFID.h"
#include "SW_Timer.h"

void setup()
{
  //Serial Monitor 시작
  Serial.begin(9600); 
  
  call_DFPlayer_setup();
  call_display_init();
  call_rfid_PCD_Init();
  call_WIFI_setup("Q9_9335", "a12345678"); //ssid, password
  
  /* set thirdScreen_time sale
   * 받는 인수 : int year, int month, int day, int hour24, int min 
   * 마감시간은 Wifi가 연결되어 있고, 항상 현재 시간보다 커야 작동한다.
   * Card Tagging으로 화면 확인 가능 */
  set_magamTime(2019,9,3,23,30); //마감시간 : 2019년 9월 3일 23시 30분으로 지정

  
  delay(5000);
  Serial.println("setup done");
  
  screen0_under();

  /*choose design among 5 design
  * screen1_default();
  * screen2_discount();
  * screen3_magam_Over();
  * screen3_magam(const char min[]);
  * screen4_wine();
  */
  screen1_default();
  call_display_update();
  delay(2000);
  
  screen2_discount();
  call_display_update();
  delay(2000);

  screen3_magam("9");
  call_display_update();
  delay(2000);
  
  screen4_wine();
  call_display_update();
  delay(2000);
  
}

void loop()
{
  //check_is_Read_RFID();
  int memberNum = check_is_Read_RFID();
  Serial.println(memberNum);
  activ_By_Member(memberNum);
  
  stop_Read_RFID();

}

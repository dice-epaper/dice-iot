// This is for Big Display format !!

#include "HW_Display.h"
#include "HW_DFPlayer.h"
#include "HW_RFID.h"
#include "SW_Timer.h"

void setup()
{
  Serial.begin(9600); //Serial Monitor 시작
  
  call_DFPlayer_setup();
  call_display_init();
  call_rfid_PCD_Init();
  call_WIFI_setup();
  
  /* set thirdScreen_time sale
   * 받는 인수
   * int year, int month, int day, int hour24, int min */
  set_magamTime(2019,9,3,22,5);
  delay(5000);
  Serial.println("setup done");
  
  setup_screen();
  call_display_update();
  
}

void loop()
{
  //check_is_Read_RFID();

  int memberNum = check_is_Read_RFID(); //get_memberNum();
  Serial.println(memberNum);
  
  if(memberNum == 0){
      Serial.println(F("This Card doesn't enroll."));   
  }

  // tagging Card ID가 1번, 3번이면
  else if (memberNum == 1 || memberNum == 3) {
    //call_myDFPlayer_play(1);
    //firstscreen_timesale();
    //call_display_update();


    int remainMin = get_RemainMin();
    delay(5000);
    for(int i= remainMin; i>0; i--){
      call_myDFPlayer_play(1);
      screen_magam(String(i).c_str());
      call_display_update();
      delay(46000); //46초 뒤에 다시 check

    } 
  }
    
  // tagging Card ID가 2번, 4번이면
  else if(memberNum == 2 || memberNum == 4){
    call_myDFPlayer_play(2);
    secondscreen_discount();
    call_display_update();
  }
  
  stop_Read_RFID();

}

// This is for Big Display format !!

#include "HW_Display.h"
#include "HW_DFPlayer.h"
#include "HW_RFID.h"

void setup()
{
  Serial.begin(9600); //Serial Monitor 시작
  
  call_DFPlayer_setup();
  call_display_init();
  
  call_rfid_PCD_Init();
  
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
  
  stop_Read_RFID();

}

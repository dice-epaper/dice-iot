#include "HW_DFPlayer.h"
#include "Arduino.h"

/* Speaker Setting */
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySoftwareSerial(10, 16); 
DFRobotDFPlayerMini myDFPlayer;

void call_DFPlayer_setup(){
  mySoftwareSerial.begin(9600); //DFPlayer 시작
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(8);
}

void call_myDFPlayer_play(int num){
  myDFPlayer.play(num);
}

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(5, 16); // RX, TX에 꽂아진 핀번호 반대로
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  Serial.begin(115200);
  Serial.println("START");
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(10);
  myDFPlayer.play(1);    
  Serial.println("END");                                         
}

void loop()
{
}

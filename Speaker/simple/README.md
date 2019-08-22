# [speaker 연결]
 
nodemcu 3V3 GND D2 D1  
DFplayer VCC GND RX TX

DFplayer VCC GND SPK_1  
LM386(Speaker module) VCC GND IN

![image](https://user-images.githubusercontent.com/53041002/63495089-21d53600-c4fa-11e9-8c86-9818a4cf1b4b.png)
![image](https://user-images.githubusercontent.com/53041002/63495106-2b5e9e00-c4fa-11e9-8090-775d171d3ca5.png)

## ★ 주의해야 할 점
##### 1. espSoftwareSerial 라이브러리 설치하기 -> 기본 SoftwareSerial는 esp8266 지원하지 않음
##### 2. DFRobotDFPlayerMini 라이브러리 설치하기 -> DFPlayer_Mini_Mp3는 더 이상 지원하지 않음
##### 3. SoftwareSerial mySoftwareSerial(5, 16); -> RX, TX 구분하기
##### 4. 위의 RX, TX는 Default가 아닌 전혀 사용하지 않는 Pinㅇ어야 한다.
##### 5. 오직 하나의 보드레이트에서만 모든 시리얼을 연결해야 한다.  (ex) 9600

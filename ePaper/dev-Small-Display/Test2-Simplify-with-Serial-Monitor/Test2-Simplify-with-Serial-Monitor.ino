
// ◆1. mapping suggestion from Waveshare SPI e-Paper to generic ESP8266
// BUSY -> GPIO4, RST -> GPIO2, DC -> GPIO0, CS -> GPIO15, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V


// ◆2. include Header files, located in Arduino/libraries/GxEPD-master/src 
// ◆2 ◇1 include library, include base class, make path known
#include <GxEPD.h>

// ◆2 ◇2 select the display class to use, "only" one 
// 아래 헤더파일 상단에 조건부 컴파일 지시자(#if A)의 조건(A)이 될 매크로 상수가 정의되어 있음
// 간단히 말해서, 사용할 디스플레이 모델 선택한 것임
// ex) <GxGDEW0213Z16/GxGDEW0213Z16.h> : #define _GxGDEW0213Z16_H_ //(빈 매크로 정의, 단순히 존재 여부만을 위함)
// ex) #if defined(_GxGDEW0213Z16_H_)

#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // (small) 2.13" b/w/r
//#include <GxGDEW042Z15/GxGDEW042Z15.h>    // (Big) 4.2" b/w/r


// ◆3. BitmapExampleN array를 생성하네.
// 위 array는 display.drawPicture등의 method에서 사용된다.
#include GxEPD_BitmapExamples

// ◆4. include Header files located in Arduino/libraries/Adafruit_GFX_Library
// Text출력을 위한 폰트이겠지?
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

// ◆5. Device Setting with ◆1. 
// for "display" keyword(instance from Class)
// GxEPD_Class is located in C:\Users\hello\Documents\Arduino\libraries\GxEPD-master\src\GxGDEW0213Z16\GxGDEW0213Z16.h 
// Class 내부에 정의된 method 들 또한 
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266) //넌 IDE Tool 설정으로 detect 된거임?? 어케 앎?ㅋㅋㅋ 우선 되니깐 pass
// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.4.2\variants\generic\common.h
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)
// Heltec E-Paper 1.54" b/w without RST, BUSY
//GxEPD_Class display(io, /*RST=D4*/ -1, /*BUSY=D2*/ -1); // no RST, no BUSY

#endif

// ◆6~7. input by Serial Monitor -> output in Display

// ◆6. Serial Monitor Setting

void setup()
{ 
  Serial.begin(115200); //Baud rate 를 115200으로 정합니다
  Serial.println();
  Serial.println("setup");
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");
}


// ◆7. (예제)그림 및 Text 반복 재생
int i = 0;
 
//inputString.reserve(200);  //문자열 공간 200byte를 확보합니다.
//boolean stringComplete = false;  //문자열 수신 완료 했는지 여부를 저장하는 변수

void loop()
{
  // 정의 in ◆8.
  String inputString = "";
  i++; 
   //문자열 클래스 하나를 준비하고 초기화 합니다.
  Serial.println(i);    delay(2000);
  Serial.println("-----loop 시작------");
  while ( Serial.available() ) {       //시리얼로 데이타가 입력된 것이 있으면
    delay(2000);
    char inChar = (char)Serial.read();    //문자 하나를 읽어서 inChar 변수에 저장
    inputString += inChar;            // 문자열변수 inputString 에 추가해 준다
    if (inChar == '\n') {              // 만약 inChar문자가 줄바꿈 문자이면
      Serial.println(inputString);
      delay(2000);
      showFont(inputString, &FreeMonoBold9pt7b);
      delay(2000);
      
    } 
  }
  Serial.println("-----loop 끝------");
}


// ◆8. showBitmapExample() 함수 정의
// ◆8 ◇1 (small dispaly model) 2.13'' 선택
// (위 에서 include한 헤더파일에 따라 조건부 컴파일 지시자 작동)
// defined in libraries\GxEPD-master\src\GxGDEW0213Z16\BitmapExamples.h
#if defined(_GxGDEW0213Z16_H_)

void showFont(String name, const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE); //필수(아래와 쌍으로)
  display.setTextColor(GxEPD_BLACK); //필수
  display.setFont(f);
  display.setCursor(0, 10);

  display.println(name);
  display.update(); //이게 필수인듯, 깜박임의 원인인듯...
}
#endif

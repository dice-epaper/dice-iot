
//★☆★☆★☆★☆★☆★☆ 여기 읽다 맘 ★☆★☆★☆★☆★☆★☆

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

// ◆6. Serial Monitor Number Matching
void setup()
{ 
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");
}


// ◆7. (예제)그림 및 Text 반복 재생
int i = 0;
void loop()
{
  // 정의 in ◆8.
  // showBitmapExample();
  delay(2000);
  i++;
  Serial.println(i);
  
  #if !defined(__AVR)//"소스코드를 컴파일하기 전에 만약 __AVR가 정의되어 있지 않다면" 의미
                      // AVR : 단일칩 마이크로컨트롤러
    // drawCornerTest();
    // ★☆★☆★☆★☆★☆★☆ 여기 하다 맘 ★☆★☆★☆
    // (7/23 목표) 오늘은 웹 대신, Serial 입력창으로 글자 받아서 Display에 출력하기
    showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
    showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
    //showFont("FreeMonoBold18pt7b", &FreeMonoBold18pt7b);
    //showFont("FreeMonoBold24pt7b", &FreeMonoBold24pt7b);
  #else
    display.drawCornerTest();
    delay(2000);
    display.drawPaged(showFontCallback);
  #endif
    delay(10000);

}

// ◆8. showBitmapExample() 함수 정의
// ◆8 ◇1 (small dispaly model) 2.13'' 선택
// (위 에서 include한 헤더파일에 따라 조건부 컴파일 지시자 작동)
// defined in libraries\GxEPD-master\src\GxGDEW0213Z16\BitmapExamples.h
#if defined(_GxGDEW0213Z16_H_)
#define HAS_RED_COLOR //? 왜 빨강이만
void showBitmapExample()
  {  // ◆8 ◇2 method 분석
    
    //★☆★☆★☆★☆★☆★☆ 여기 읽다 맘 ★☆★☆★☆ argument 형태 파악하자 ★☆★☆★☆
    // 이 함수 잠시 주석처리함
    // Text 출력부터
    // 1. drawPicture() 
    // 특징 적기 : 꽃 그림(꽃 부분만 색이 바뀜), 배경이 blck, 
    // 깜박이는 코드는 무엇일까?(없애고 싶음 ㅋ)
    display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
    delay(5000);
    /* method 한개씩 탐색중
    display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
    delay(5000);
    #if !defined(__AVR)
      display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
      delay(5000);
    #endif
    display.drawExampleBitmap(BitmapWaveshare_black, sizeof(BitmapWaveshare_black));
    delay(2000);
    // example bitmaps for b/w/r are normal on b/w, but inverted on red
    display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
    delay(2000);
    display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2), GxEPD::bm_invert);
    delay(2000);
    display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    */
    display.update();
  }
#endif

/* //우선 작은 아이부터 분석
// ★ 우리의 Big dispaly model
#if defined(_GxGDEW042Z15_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  #if defined(__AVR)
    display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
  #else
    // draw black and red bitmap
    display.drawPicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
    delay(5000);
    display.drawPicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
    delay(5000);
    display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
    delay(5000);
    display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
    delay(2000);
    display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    display.update();
  #endif
}
#endif
*/

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
  display.update();
  delay(5000);
}

void showFontCallback()
{
  const char* name = "FreeMonoBold9pt7b";
  const GFXfont* f = &FreeMonoBold9pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
}

void drawCornerTest()
{
  display.drawCornerTest();
  delay(5000);
  uint8_t rotation = display.getRotation();
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
    display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
    display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
    display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
    display.update();
    delay(5000);
  }
  display.setRotation(rotation); // restore
}

#if defined(_GxGDEP015OC1_H_) || defined(_GxGDE0213B1_H_) || defined(_GxGDEH0213B72_H_) || defined(_GxGDEH029A1_H_)
#include "IMG_0001.h"
void showBoat()
{
  // thanks to bytecrusher: http://forum.arduino.cc/index.php?topic=487007.msg3367378#msg3367378
  uint16_t x = (display.width() - 64) / 2;
  uint16_t y = 5;
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK);
  display.update();
  delay(500);
  uint16_t forward = GxEPD::bm_invert | GxEPD::bm_flip_x;
  uint16_t reverse = GxEPD::bm_invert | GxEPD::bm_flip_x | GxEPD::bm_flip_y;
  for (; y + 180 + 5 <= display.height(); y += 5)
  {
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, forward);
    display.updateWindow(0, 0, display.width(), display.height());
    delay(500);
  }
  delay(1000);
  for (; y >= 5; y -= 5)
  {
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, reverse);
    display.updateWindow(0, 0, display.width(), display.height());
    delay(1000);
  }
  display.update();
  delay(1000);
}
#endif

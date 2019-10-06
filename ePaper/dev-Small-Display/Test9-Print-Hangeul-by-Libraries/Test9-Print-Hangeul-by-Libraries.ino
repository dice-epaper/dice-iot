// --------------------
// Display Setting

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // (small) 2.13" b/w/r
#include <Fonts/FreeMono9pt7b.h>

// in C:\Users\hello\Documents\Arduino\libraries\Adafruit_GFX_Library\Fonts
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)
// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.4.2\variants\generic\common.h
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)
// Heltec E-Paper 1.54" b/w without RST, BUSY
//GxEPD_Class display(io, /*RST=D4*/ -1, /*BUSY=D2*/ -1); // no RST, no BUSY

#endif


// --------------------
// Start to print ePaper

void setup() {
  // Select to Srial Monitor 
  Serial.begin(115200);
  Serial.println("setup");
  String inputString = "Why?";
  for(int i=0; i<inputString.length(); i++){
      //Serial.println(inputString[i]);
      Serial.println(inputString);
  }
  
  display.init(115200);
  showFont(inputString, &FreeMono9pt7b);
}

void loop() {
  // put your main code here, to run repeatedly;

}

// --------------------
// showFont function

void showFont(String name, const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE); //필수(아래와 쌍으로)
  display.setTextColor(GxEPD_BLACK); //필수
  display.setFont(f);
  display.setCursor(0, 10);

  display.println(name);
  display.update(); //이게 필수인듯, 깜박임의 원인인듯...
}

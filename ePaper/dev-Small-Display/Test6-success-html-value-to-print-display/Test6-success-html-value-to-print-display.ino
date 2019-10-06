#include <ESP8266WiFi.h>

#define ssid "olleh_WiFi_5045"
#define password "0000005873"

const char* host = "http://www.google.co.kr";
const char* productcode="1";

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h> // 2.13 inch

#include GxEPD_BitmapExamples
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)

GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)

#endif


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");


  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  


  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");
}


int value = 0;

void loop()
{
  
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  String url = "/";
  //url += productcode;
  //url += "/";
  
  Serial.println(url);

  
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    
    int title_tag = line.indexOf("SDkEP");
    
    if(title_tag>0){
        String title_str = "<div class=\"SDkEP\">";
        int end_idx = line.indexOf("</div>");
        String title = line.substring(line.indexOf(title_str)+title_str.length(),end_idx);
        Serial.println(title); 
        showFont(title.c_str(), &FreeMonoBold24pt7b);
    }
  
  }
  delay(5000);
  Serial.println();
  Serial.println("closing connection");

  delay(5000);

}


void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_RED);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  
  display.update();
  delay(5000);
}

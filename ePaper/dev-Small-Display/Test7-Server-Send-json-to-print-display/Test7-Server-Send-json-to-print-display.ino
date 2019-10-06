
#include <ArduinoJson.h>

// Wifi Setting
#include <ESP8266WiFi.h>

#define ssid "Q9_9335"
#define password "a12345678"

const char* host = "15b77b08.ngrok.io"; // 앞에 http 쓰지 말것

// --------------------
// Display Setting

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>
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

//------------------------------------------------
// Display 출력 function 정의
void showFont(String name, const GFXfont* f){

  display.fillScreen(GxEPD_WHITE); //필수(아래와 쌍으로)
  display.setTextColor(GxEPD_BLACK); //필수
  display.setFont(f);
  display.setCursor(0, 10);
  //Serial.println(name);
  display.println(name);
  display.update(); //이게 필수인듯 but 깜박임의 원인
}
//------------------------------------------------
void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Wifi Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  display.init(115200); // 설마? with update() 랑 같이 세트네
}

//------------------------------------------------
int value = 0;

void loop()
{
  Serial.println();
  Serial.println("Display Start Test");
  showFont("Display Start Test",&FreeMonoBold9pt7b);
  delay(5000);
  ++value;
 
  Serial.print("connecting to (host) ");
  Serial.println(host);
   
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) //이거 말고 HTTPClinet http 깔꼼함? -> Sticky Note
  {
    Serial.println("connection failed");
    return;
  }
   
  // We now create a URI for the request
  String url = "/";
//  url += streamId;
//  url += "?private_key=";
//  url += privateKey;
//  url += "&value=";
//  url += value;
   
  Serial.print("Requesting URL: ");
  Serial.println(url);
   
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0)
  {
    if (timeout - millis() < 0)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
   
  // Read all the lines of the reply from server and print them to Serial
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.println();
    Serial.println("line is => ");
    Serial.print(line); //HTTP data res data 1줄씩.. -> (과제)jsondata만 읽어오기
    Serial.println();
    showFont(line, &FreeMonoBold9pt7b);
    delay(4000);

  }
   
  Serial.println();
  Serial.println("closing connection");
}

// ESP8266 & Display Setting
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

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
// WiFi Setting

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif

#define ssid "Q9_9335"
#define password "a12345678"
ESP8266WebServer server(80);

//------------------------------------------------
// html Source Code1

static const char PROGMEM INDEX_HTML[] = R"rawliteral(  
<!DOCTYPE html>
  <html>
    <head>
      <title>Single Line Input</title>
        <script>
        console.log("hello");
        let inputString;
        function inputPush(){
          inputString= document.getElementsByClassName("str-input")[0].value;
          console.log(inputString)
        }
      </script>
    </head>

    <body>
      <br><br>
      <input class="str-input" placeholder="Fill Me in"/>
      <button onclick="inputPush();";> button </button>

    </body>
  </html>
)rawliteral";

//------------------------------------------------
// URL , HTTP 호출 function() 정의
void HomeRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void TestRoot() {
  showFont("Hello", &FreeMonoBold9pt7b);
  server.send(200, "text/plain", "This is Display Test!");
}

void TestOfHtml() {
  server.send(200, "text/html",INDEX_HTML );
}

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

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", HomeRoot);
  server.on("/test/function", []() {
    // Test of 함수 바로 정의
    server.send(200, "text/plain", "this works as well");
  });
  server.on("/test", TestRoot);
  server.on("/test/basicHtml", HTTP_GET, TestOfHtml); //HTTP_POST 안되는 이유는?

  server.begin();
  Serial.println("HTTP server started");
}

//------------------------------------------------

void loop(void) {
  
  server.handleClient();
  MDNS.update();
}

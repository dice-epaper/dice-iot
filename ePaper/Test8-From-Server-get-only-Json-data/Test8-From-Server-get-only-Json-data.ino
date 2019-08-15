// json for data

#include <ArduinoJson.h>

// --------------------
// Wifi Setting

#include <ESP8266WiFi.h>
#define ssid "Q9_9335"
#define password "a12345678"
const char* host = "15b77b08.ngrok.io"; // 앞에 http 쓰지 말것 //서버 주소

// --------------------
// Display Setting

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)
GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4); // default selection of D4(=2), D2(=4)
#endif

//------------------------------------------------
void setup()
{
  // Select to Srial Monitor 
  Serial.begin(115200);
  Serial.println();
  
  // Connect to Wifi
  Serial.printf("Wifi Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  // Start Display (essential code)
  display.init(115200);

  // Connect to HTTP
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
  // GET Method
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

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }

  // Allocate the JSON document
  // Use arduinojson.org/v6/assistant to compute the capacity.
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonDocument doc(capacity);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  // Extract values
  Serial.println(F("Response:"));
  Serial.println(doc["product"].as<char*>());
  Serial.println(doc["price"].as<long>());
  Serial.println(doc["data"][0].as<char*>());
  Serial.println(doc["data"][1].as<char*>());
  showFont(doc["data"][1].as<char*>(), &FreeMonoBold9pt7b);
  //숫자인 경우 Serial.println(doc["data"][1].as<float>(), 6);

  // Disconnect
  client.stop();
}



void loop() {
  // not used in this example
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

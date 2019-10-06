#include <ESP8266WiFi.h>
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

//const char* ssid = "olleh_WiFi_5045";

//const char* password = "0000005873";

#define ssid "olleh_WiFi_5045"
#define password "0000005873"

// Create an instance of the server

// specify the port to listen on as an argument

WiFiServer server(80);

//HTTP 통신은 80번 포트를 사용합니다.



void setup() {

  Serial.begin(115200);

  delay(10);

  

  // Connect to WiFi network

  Serial.println();

  Serial.println();

  Serial.print("Connecting to ");

  Serial.println(ssid);

  

  WiFi.begin(ssid, password);

  

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

  

  // Start the server

  server.begin();

  Serial.println("Server started");



  // Print the IP address

  Serial.println(WiFi.localIP());

}



void loop() {

  // Check if a client has connected

  // 클라이언트(사용자)가 접속을 했을때

  WiFiClient client = server.available();

  if (!client) {

    return;

  }

  

  // Wait until the client sends some data

  Serial.println("new client");

  while(!client.available()){

    delay(1);

  }

  

  // Read the first line of the request

  // 사용자가 전송한 리퀘스트 헤더를 읽습니다.

  String req = client.readStringUntil('\r');

  Serial.println(req);

  //GET /gpio/1 HTTP/1.1 과 같은 값이 출력 됩니다.

  client.flush();

  

  // Match the request

  // 리퀘스트 헤더에 저희가 필요로 하는 요청이 들어있는지 확인합니다.

  int val;

  if (req.indexOf("/gpio/0") != -1)

    val = 0;

  else if (req.indexOf("/gpio/1") != -1)

    val = 1;

  else {

    Serial.println("invalid request");

    client.stop();

    return;

  }



  // Set GPIO2 according to the request

  digitalWrite(2, val);// 요청한 내용대로 해당 디지털 핀을 제어합니다.

  

  client.flush();



  // Prepare the response
  String inputString;
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\Please input Here";
  s += "<input value=\'inputString\'/>";
  s += "<button onclick=\"showFont(inputString, &FreeMonoBold9pt7b);  Serial.println(inputString);\">button </button>";


  s += "</html>\n"; // 결과 출력



  // Send the response to the client

  client.print(s);

  delay(1);

  Serial.println("Client disonnected");


  
}

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

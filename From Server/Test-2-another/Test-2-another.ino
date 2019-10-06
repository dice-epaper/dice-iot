#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Q9_9335";
const char* password = "a12345678";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http; //Object of class HTTPClient
    http.begin("https://aw7pbnicx2.execute-api.ap-northeast-2.amazonaws.com/default/Hello_Lambda");
    int httpCode = http.GET();

    if (httpCode > 0) 
    {
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonDocument doc(bufferSize);//DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
 
      const char* brand = doc["brand"].as<char*>(); 
      //const char* name = root["name"]; 
      //const char* username = root["username"]; 
      //const char* email = root["email"]; 

      Serial.print("Brand:");
      Serial.println(brand);
    }
    http.end(); //Close connection
  }
  delay(60000);
}

// json for data

#include <ArduinoJson.h>

// --------------------
// Wifi Setting

#include <ESP8266WiFi.h>
#define ssid "FROM HEARTS 02"
#define password "from8877"
const char* host = "b5tm1uqqug.execute-api.ap-northeast-2.amazonaws.com/test/epaper"; 
// 앞에 http 쓰지 말것

// setup
void setup()
{
  // Select to Srial Monitor 
  Serial.begin(115200);
  Serial.println();
  
  // Connect to Wifi
  Serial.printf("Wifi Connecting to %s \n", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("Wifi connected\n");

  // Connect to HTTP
  WiFiClientSecure client; //WiFiClient client;
  const int httpPort = 443;
  if (!client.connect(host, httpPort)) //이거 말고 HTTPClinet http 깔꼼함? -> Sticky Note
  {
    Serial.println("\n connection failed");
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
  Serial.println(doc["body"].as<char*>());
  //Serial.println(doc["price"].as<long>());
  //Serial.println(doc["data"][0].as<char*>());
  //Serial.println(doc["data"][1].as<char*>());
  //showFont(doc["data"][1].as<char*>(), &FreeMonoBold9pt7b);

  // Disconnect
  client.stop();
}



void loop() {
  // not used in this example
}

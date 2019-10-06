#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "***";
const char* password = "***";

int timezone = 3;
int dst = 0;

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  configTime(9 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");

  /*마감시간 설정*/
  
}

void loop() {
  /*get 현재 시간*/
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  //getTextTime(now);
  struct tm * timeinfo;
  timeinfo = localtime(&now);
  Serial.println(timeinfo->tm_hour);
  Serial.println(timeinfo->tm_min);
  Serial.println(timeinfo->tm_wday); //요일
  String text = String(timeinfo->tm_hour)+String(timeinfo->tm_min)+String(timeinfo->tm_wday);
  Serial.println(text);


  delay(1000);
}

String getTextTime(time_t now){
  struct tm * timeinfo;
  timeinfo = localtime(&now);
  Serial.println(timeinfo->tm_hour);
  Serial.println(timeinfo->tm_min);
  Serial.println(timeinfo->tm_wday);
  String text = String(timeinfo->tm_hour)+String(timeinfo->tm_min)+String(timeinfo->tm_wday);
  Serial.println(text);
}

#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "AndroidHotspot8114";
const char* password = "a4q7c689dwx1";

int timezone = 3;
int dst = 0;
double     d_diff;
time_t     tm_st;
time_t     tm_nd;
int        tm_day, tm_hour, tm_min, tm_sec;
struct tm  user_stime;
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
 
  user_stime.tm_year   = 2019   -1900;   // 주의 :년도는 1900년부터 시작
  user_stime.tm_mon    = 8      -1;      // 주의 :월은 0부터 시작
  user_stime.tm_mday   = 25;
  user_stime.tm_hour   = 19;
  user_stime.tm_min    = 0;
  user_stime.tm_sec    = 0;
  user_stime.tm_isdst  = 0;              // 썸머 타임 사용 안함
  
  Serial.println("");
  tm_st = mktime(&user_stime); 
  Serial.println("마감 시간 is");
  //Serial.println(tm_st);
  Serial.println(ctime(&tm_st));
}

void loop() {
  /*get 현재 시간*/
  Serial.println("");
  Serial.println("현재 시간 is");
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

  /*시차 계산*/
  d_diff   = difftime( tm_st,now );
  
  tm_day   = d_diff / ( 60 *60 * 24);
  d_diff   = d_diff - ( tm_day *60 *60 *24);
  
  tm_hour  = d_diff / ( 60 *60);
  d_diff   = d_diff - ( tm_hour *60 *60);
  
  tm_min   = d_diff / 60;
  d_diff   = d_diff - ( tm_min *60);
  
  tm_sec   = d_diff;
  String Text = String("지금부터 2019년 08월 25일 19시까지는")+
              String(tm_day)+"일 "+String(tm_hour)+"시 "+String(tm_min)+"분 "+String(tm_sec)+"초 남았음";
  Serial.println(Text);
  
}



 

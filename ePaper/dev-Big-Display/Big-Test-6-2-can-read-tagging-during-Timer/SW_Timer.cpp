/* 
 *  for thirdScreen_time sale
 *  1. must set Wifi
 */
 
#include <ESP8266WiFi.h>
#include <time.h>
#include "SW_Timer.h"

//#define ssid "Q9_9335"
//#define password "a12345678"

int timezone = 3;
int dst = 0;
double     d_diff;
time_t     tm_st;
time_t     tm_nd;
int        tm_day, tm_hour, tm_min, tm_sec;
struct tm  user_stime;

void call_WIFI_setup(const char ssid[], const char password[]){
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
}



/*마감시간 설정*/
void set_magamTime(int year, int month, int day, int hour24, int min){ 
  user_stime.tm_year   = year  -1900; //2019  ;   // 주의 :년도는 1900년부터 시작
  user_stime.tm_mon    = month -1; //9      ;      // 주의 :월은 0부터 시작
  user_stime.tm_mday   = day; //3;
  user_stime.tm_hour   = hour24; //20;
  user_stime.tm_min    = min; //30;
  user_stime.tm_sec    = 0;
  user_stime.tm_isdst  = 0;              // 썸머 타임 사용 안함
  
  Serial.println("");
  tm_st = mktime(&user_stime); 
  Serial.println("마감 시간 is");
  Serial.println(ctime(&tm_st));
}

int get_RemainMin(){
  Serial.println("");
  Serial.println("마감 시간 is");
  Serial.println(ctime(&tm_st));
  Serial.println("-----------");
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
  String Text = String("지금부터 2019년 09월 3일 21시까지는")+
              String(tm_day)+"일 "+String(tm_hour)+"시 "+String(tm_min)+"분 "+String(tm_sec)+"초 남았음";
  Serial.println(Text);
  return tm_min;
}

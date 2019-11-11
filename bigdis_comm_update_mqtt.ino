#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include "awskey.h"


#include "jsonparser.h"

#include "IMG_QR.h"
#include "IMG_ARROW.h"
#include "IMG_SALE.h"
#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>



#include <Fonts/Open_Sans_ExtraBold_100.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/Org_01.h>

#if defined (ESP8266)
GxEPD2_3C<GxEPD2_420c, GxEPD2_420c::HEIGHT / 32> display(GxEPD2_420c(/*CS=15*/ SS, /*DC=*/ 0, /*RST=*/ 4, /*BUSY=*/ 5));
#endif



struct proInfo
{
  String bnc;
  String unit;
  String price;
  int capacity;
};



const char* ssid="KT_GiGA_2G_NAMU";
const char* pass="2muchkitkat";
const char *thingId = "nodemcu-device";          // 사물 이름 (thing ID) mac address로 자동 생성
const char *host = "a3fo3s5g3sbs17-ats.iot.ap-northeast-2.amazonaws.com"; // AWS IoT Core 주소
 
const char* inTopic = "no2";

String sChipID; // mac address를 문자로 기기를 구분하는 기호로 사용
char cChipID[40];

proInfo product;


X509List ca(ca_str);
X509List cert(cert_str);
PrivateKey key(key_str);
WiFiClientSecure wifiClient;



void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");


  

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.print("\n");

  String str = String((char*)payload);


  
  if (json_parser(str,"bnc").compareTo("none") != 0){
    product.bnc = json_parser(str,"bnc");
    product.unit = json_parser(str,"unit");
    product.price = json_parser(str,"price");
    product.capacity = json_parser(str,"ca").toInt();
    showProInfo();
  }

  if(json_parser(str,"isSale") == "0"){
    drawqrcode();
    showProInfo();
  }
  
  else if(json_parser(str,"eventType").compareTo("none") != 0){
    drawSale(json_parser(str,"eventType"),json_parser(str,"p").c_str(), json_parser(str,"d").c_str());
  }


  
  str = "";
  
  
 
}

PubSubClient client(host, 8883, callback, wifiClient);




void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection..");
    Serial.println("start");
    if (client.connect(thingId)) {
      Serial.println("connected");
      client.subscribe(inTopic);
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      char buf[256];
      wifiClient.getLastSSLError(buf,256);      
      delay(5000);
    }
  }
}


void setClock() {
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");

  Serial.println("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(500);
    now = time(nullptr);
  }
 
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
}





void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  display.init();
  display.setFullWindow();
  
  uint8_t chipid[6]="";
  WiFi.macAddress(chipid);
  sprintf(cChipID,"%02x%02x%02x%02x%02x%02x%c",chipid[5], chipid[4], chipid[3], chipid[2], chipid[1], chipid[0],0);
  sChipID=String(cChipID);
  thingId=cChipID;

  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  

  wifiClient.setTrustAnchors(&ca);
  wifiClient.setClientRSACert(&cert, &key);
  Serial.println("Certifications and key are set");

  setClock();
  client.setCallback(callback);
  Serial.println("setup done");
  
 
  drawqrcode();
  reconnect();
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); 
}




void showFont(const char bnc[], const char price[], const char unit[],const GFXfont* f)
{
  
  display.setPartialWindow(0, 150, 400, 150);
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.firstPage();
  do
  {    
    display.setCursor(20, 190);
    display.println(bnc);
    display.setCursor(20, 220);
    display.println(unit);
    display.setCursor(280,193);
    display.println(price);
    display.setCursor(20,193);
    display.println(product.bnc);
    
    
  }
  while (display.nextPage());
  
}

void showProInfo()
{
  
  display.setPartialWindow(0, 150, 400, 150);
  display.fillScreen(GxEPD_WHITE);
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK); 
  display.firstPage();
  do
  {    
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(20, 190);
    display.println(product.bnc);
    display.setCursor(20, 220);
    display.println(product.unit);
    
    display.setFont(&FreeSansBold24pt7b);
    display.setCursor(250,250);
    display.println(product.price);
  }
  while (display.nextPage());
  
}



void drawSale(String eventType,const char percent[], const char date[])
{
      display.setPartialWindow(0, 150, 400, 150);

      display.firstPage();
      do
      {        
        display.setTextColor(GxEPD_BLACK);
        display.setFont(&Org_01);
        display.setCursor(255,290);
        display.println(date);
        
        if( eventType.equals("per")){
          display.drawInvertedBitmap(20, 240,sale_super, 160, 40, GxEPD_RED);
          
          display.setFont(&FreeMonoBold9pt7b);
          display.setCursor(20, 190);
          display.println(product.bnc);

          
          display.setCursor(300, 195);
          display.println(product.price);
          display.drawInvertedBitmap(268, 190, arrow, 120, 40, GxEPD_RED);

          display.setFont(&FreeMonoBold9pt7b);
          display.setCursor(20, 220);
          int unit = 0;
          int salePrice = (1 - (atoi(percent) * 0.01)) * product.price.toInt();
          if ( product.capacity > 100 ){
            unit = salePrice / product.capacity * 100;
            String printunit = "100g " + String(unit);
            display.println(printunit); 
          }
          else {
            unit = salePrice / product.capacity * 10;
            String printunit = "10g " + String(unit);
            display.println(printunit);
          }
            

          display.setFont(&FreeSansBold24pt7b);
          display.setCursor(250, 240);
          display.println(salePrice);          
        }      
        else {

          display.setFont(&FreeMonoBold9pt7b);
          display.setCursor(20, 190);
          display.println(product.bnc);
             
          display.setFont(&FreeSansBold24pt7b);
          display.setCursor(250,250);
          display.println(product.price);

          display.setFont(&FreeMonoBold9pt7b);
          display.setCursor(20, 220);
          if( eventType.equals("B1G1")){
            display.drawInvertedBitmap(20, 240,sale_1plus1, 160, 40, GxEPD_RED);
            int unit = 0;
            if ( product.capacity > 100 ){
              unit = product.price.toInt() / (product.capacity * 2) * 100;
              String printunit = "100g " + String(unit);
              display.println(printunit);
            }
            else {
              unit = product.price.toInt() / (product.capacity * 2) * 10;
              String printunit = "10g " + String(unit);
              display.println(printunit);
            }
            
          }
          else if( eventType.equals("B2G1")){
            display.drawInvertedBitmap(20, 240,sale_2plus1, 160, 40, GxEPD_RED);
          }
        }         
      }     
      while (display.nextPage());

      
      delay(1000);
      
      if( eventType.equals("per")){
        showSalePercent(percent);
      }
    
  
}


void showSalePercent(const char percent[])
{
  display.setPartialWindow(0, 0, 270, 150);
  display.setRotation(0);
  display.setTextColor(GxEPD_WHITE);
  display.firstPage();
  do
  {    
    display.fillScreen(GxEPD_RED);
    display.setCursor(20, 100);
    display.setFont(&Open_Sans_ExtraBold_100);
    display.println(percent);
    display.fillRect(150, 25, 90, 100, GxEPD_WHITE);
    display.drawInvertedBitmap(150, 25, discount_arrow, 90, 100, GxEPD_RED);
    
  }
  while (display.nextPage());

}


void drawqrcode()
{



  display.firstPage();
      do
      {
        
        display.fillRect(0, 0, 400, 150, GxEPD_RED);
        display.drawInvertedBitmap(263, 13, qrcode_deco, 124, 124, GxEPD_WHITE);
        display.drawInvertedBitmap(275, 25, qrcode, 100, 100, GxEPD_BLACK);
        display.fillRect(0, 0, 270, 150, GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bigqr, 270, 150, GxEPD_RED);
      }
      while (display.nextPage());
      delay(3000);
    
  
}

// Example of the different modes of the X.509 validation options
// in the WiFiClientBearSSL object
//
// Jul 2019 by Taejun Kim at www.kist.ac.kr
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>

const char *ssid = "FROM HEARTS 02";  // 와이파이 이름
const char *pass = "from8877";      // 와이파이 비밀번호
const char *thingId = "abc";          // 사물 이름 (thing ID) 
const char *host = "a2vf2y5uvhhdt9-ats.iot.ap-northeast-2.amazonaws.com"; // AWS IoT Core 주소

// 사물 인증서 (파일 이름: xxxxxxxxxx-certificate.pem.crt)
const char cert_str[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUJsE1dlrBBNjinUfooc5fqSwWq1swDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE5MDkxMDA2MTMx
OVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMT/jzMVje27kEMr096o
XnSDxdI7Ey4YHOJYgD9NKIw+zDaKoQsjqGAAcyWI2f+RLA8RcBZ+OY0KChgPsj76
qKTU47s5dWPDYJ4H1CToFpPlClRvgcGCkm9Pkf/omfxfhaKSrSLd2j6cZvAl5Tsa
eZlkBobacXr5oyrMkXRFVFKLejOgQiWFRDoBFMe/wNyLH7w/dw/0Jz8VfMu7pHUb
t7Dmh9ZMaEBWL34LaQ01rAXpO8qt5qE7LR9/5cn5t9Xj1G8K8/8D6OZOyojhaQQj
+cEMv2xHlEAyz9uRsUh25m3vDcvTncJxypQsJRqmfwmL5MHpPln3qfrbw7449s7R
LO0CAwEAAaNgMF4wHwYDVR0jBBgwFoAUsUJjvIrnrDYZfSidfhNReGkVdpYwHQYD
VR0OBBYEFGPzC0TP48MBpHhfV74CeXe2qlKwMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAZAbMh5lBnYoodLkeJEnYfWFZn
IrVRr3WWnaCipqL1LO8lWznE/yLE8BeqP4KGhIb3CJ2AMfVQOP4CGd4VkcWsThzZ
C/JqO4WeQC76TYfRLpVNiG/mpr4krl5TYZf1xNfaNEeIMN1GOiUhdqxOGHAME93i
ddb3VaSP/yd3tTYqNangEUXDG3ern5bukaVMxdZxiSl4KCtoqnCil6OMsBthtq0f
XIv2BdgAXKIPb/tNBd91jm6wFa014OSVvm5z44dvw9nIi0LHuvxncLN7Z8mRyJ4I
MLyx82/65uDrjI853jQhgqf1uRp6deGeYCr0FaBbjHwfF9d797NZssNJtqzH
-----END CERTIFICATE-----
)EOF";
// 사물 인증서 프라이빗 키 (파일 이름: xxxxxxxxxx-private.pem.key)
const char key_str[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAxP+PMxWN7buQQyvT3qhedIPF0jsTLhgc4liAP00ojD7MNoqh
CyOoYABzJYjZ/5EsDxFwFn45jQoKGA+yPvqopNTjuzl1Y8NgngfUJOgWk+UKVG+B
wYKSb0+R/+iZ/F+FopKtIt3aPpxm8CXlOxp5mWQGhtpxevmjKsyRdEVUUot6M6BC
JYVEOgEUx7/A3IsfvD93D/QnPxV8y7ukdRu3sOaH1kxoQFYvfgtpDTWsBek7yq3m
oTstH3/lyfm31ePUbwrz/wPo5k7KiOFpBCP5wQy/bEeUQDLP25GxSHbmbe8Ny9Od
wnHKlCwlGqZ/CYvkwek+Wfep+tvDvjj2ztEs7QIDAQABAoIBABG6lh6Yz/8XJDKH
XTfqmyWNPl5fJqi9Tswn/tKzlPSaKjK2Yyvnd528LKCyIjxXyklI3neHwJIq1yG3
N+lnEYpUBnKxBxmFWcqfFb6EjJOex0E2D81kfN07of4P5tvJlPM+lApRQPTlinYO
UwTwqwTc9aFpQ1E36jFN28FFBAOxlSfD+czQ8EuV/htvG4MLIskv/jMToTe8WLzS
i2RtMtMX573tOqDfW4RphcaQBkIBI0GmKVhR+sabHOeRFwZBbI0w6j1+vbbv7NrV
0eSJGC/5/QKNit7Ji1eD+Z8LYGNHWXNqPbtl6FOCj5SCnK5HdW8JA3htZFPqHRd+
bUaD8AECgYEA9UlVKEWyqesLFYJvqyZ/NW+GYYXFfPBlEbb7GZB+HfqO0qpLKNcS
aXcutapsxplcOvZr0MAx2T4H5G/MsBU+48dy03IjmUbuCL3OcFoEBLoLr39JMPTF
TR9H06gZ1hAlOKY180m94R1CVPJDRsewbMhPRMsWVeisCsLW/gMTMgECgYEAzZpL
CHplyGGcxU6ir5346VSs9R0SF6Cn4/STvV+vbcYybita5bulrWINpyRgsI5YhAzi
CA4027Yn5tiR9q31/BY2UWfwlCD/4xhODoZnSGeHOer5HhfulxbyZk51kZi+QV1c
Ve9i7lnhbp/qVG54mwZBlMwLDQEnFbYLCuXn4u0CgYEA49hrtw4PKVGBKUjRjA0l
izB+hmZpjWYMrEjptNSIojZVpxCy4kvt+XPROsUFZ/GbP9YZTn7Jjz/UuvizDTmf
Ap0JZ6qVsNK3V/1gHvMu2mkrY6j8BvLHt5z/7ncvEK5MtPOIF+b+73ZrYFbt8Xia
xGHJaGCx7blE3nYgmTGoCgECgYEAyJOwhYnax/yqUzZesdL8JK1NuiZtIw3BHDra
8pFpdD85rY6wM5S3kYkp5pgvl66WneRvkgpB+OIg1S0MYMnfQtlsjkhHREtZN3Pb
moH2OoV9P7yC4Z/ZTB6/xZzfR3XqjZwF23QZYIvgx+pMUaggEqSsz/urADnSpnSd
Gzmk2hUCgYEA5oWBFL1HFrufDVOikeuynGn5eoPJqYASKS85T0NLfTBX3exVL/hf
1WThDXHI0AOkr6Wz/jgj6Tdk2wRRMaquPw5ULv5pW2xw5QKUUFDAf68diVp3tZfr
fBQVdwRUJ71JMcPaYa2G/AQH1XIr2Ove2ZdY3bkIO+S2gJhkJVK9ciA=
-----END RSA PRIVATE KEY-----
)EOF";
// Amazon Trust Services(ATS) 엔드포인트 CA 인증서 (서버인증 > "RSA 2048비트 키: Amazon Root CA 1" 다운로드)
const char ca_str[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

}

X509List ca(ca_str);
X509List cert(cert_str);
PrivateKey key(key_str);
WiFiClientSecure wifiClient;
PubSubClient client(host, 8883, callback, wifiClient); //set  MQTT port number to 8883 as per //standard

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(thingId)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      char buf[256];
      wifiClient.getLastSSLError(buf,256);
      Serial.print("WiFiClientSecure SSL error: ");
      Serial.println(buf);

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// Set time via NTP, as required for x.509 validation
void setClock() {
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");

  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  Serial.println();

  // We start by connecting to a WiFi network
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  wifiClient.setTrustAnchors(&ca);
  wifiClient.setClientRSACert(&cert, &key);
  Serial.println("Certifications and key are set");

  setClock();
  //client.setServer(host, 8883);
  client.setCallback(callback);
}

long lastMsg = 0;
char msg[50];
int value = 0;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 75, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
    Serial.print("Heap: "); Serial.println(ESP.getFreeHeap()); //Low heap can cause problems
  }
}

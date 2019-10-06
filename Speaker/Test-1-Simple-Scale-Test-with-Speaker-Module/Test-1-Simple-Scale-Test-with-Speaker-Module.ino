int speaker = 4;//D2

void setup(){
  Serial.begin(115200);
  pinMode(speaker, OUTPUT);
  Serial.println("setup Done");
}

void loop(){
  tone(speaker,262,1000);
  delay(1000);
  noTone(speaker);
  tone(speaker,294,1000);
  delay(1000);
  noTone(speaker);
  tone(speaker,330,1000);
  delay(1000);
  noTone(speaker);
  }

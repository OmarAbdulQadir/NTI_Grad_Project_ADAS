#include <SoftwareSerial.h>

SoftwareSerial BtMaster(10, 9);
char x= 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BtMaster.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  BtMaster.print(x++);
  delay(100);
  if(Serial.available())
  {
    Serial.println(Serial.read());
  }
}

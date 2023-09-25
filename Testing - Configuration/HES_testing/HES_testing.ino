void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 1)
  {
    Serial.println(1);
  }
  else
  {
    Serial.println(0);
  }
  delay(500);
}

int i= 0;
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 1)
  {
    Serial.print("Cycle: ");
    Serial.println(i++);
  }
}

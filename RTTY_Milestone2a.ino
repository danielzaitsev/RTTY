void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(9, HIGH);
  mark();
  space();
}
void mark(){
  for(int x = 0; x < 51; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(218);
    digitalWrite(9, LOW);
    delayMicroseconds(218);
  }
}
void space(){
  for(int x = 0; x < 47; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(235);
    digitalWrite(9, LOW);
    delayMicroseconds(235);
  }
}
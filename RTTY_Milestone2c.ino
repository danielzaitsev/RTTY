
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration = 0;
  float frequency = 0.0;
  duration = pulseIn(11, HIGH);
  frequency = 1 / (2000*duration);
  if(frequency > 2123 && frequency < 2127)
  {
    // mark
    Serial.println(frequency);
    Serial.println("1");
    // read in 1
  }
  if(frequency > 2293 && frequency < 2297)
  {
    // space
    serial.println(frequency);
    Serial.println("0");
    // read in 0
  }
  
}

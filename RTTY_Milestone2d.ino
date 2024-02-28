
// Global variables
char transmission[] = "Hello World!";
const int index = 12;
int data[index][8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,INPUT);
  pinMode(9, OUTPUT);
  for(int i = 0; i < index; i++)
  {
    int a = int(transmission[i]);
    for(int x = 7; x >= 0; x--)
    {
      data[i][x] = a % 2;
      a = a / 2;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long duration;
  float frequency;
  
  for(int j = 0; j < index; j++)
  {
    //Start bit
    space();
    for(int k = 0; k < 8; k++)
    {
      if(data[j][k] == 1)
      {
        mark();
        duration = pulseIn(11, LOW, 22);
        frequency = 1 / (2000*((float)(duration)));
        Serial.println(duration);
      }
      else
      {
        space();
        duration = pulseIn(11, LOW, 22);
        frequency = 1 / (2000*((float)(duration)));
        Serial.println(duration);
      }
    }
    // Stop bit
    mark();
  }
  //checkFrequency();

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
void checkFrequency()
{
  long duration;
  float frequency;
  duration = pulseInLong(11, HIGH);
  Serial.println(duration);
  frequency = 1 / (2000*duration);

  if(frequency > 2123 && frequency < 2127)
  {
    // mark
    Serial.println(frequency);
    Serial.println('1');
    delay(22);
    // read in 1
  }
  if(frequency > 2293 && frequency < 2297)
  {
    // space
    Serial.println(frequency);
    Serial.print('0');
    delay(22);
    // read in 0
  }
}
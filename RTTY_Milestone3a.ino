int inputPin = A1;
int Vin = -1;
int cutoff = 512;
int packet[23];
int dataFrame[8];
int dataIn = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sentenceCounter = 0;
  int calculateDelay = 0;
  char nextChar = '';
  int placeholder = 0;
  while(dataIn < 23)
  {
    Vin = analogRead(inputPin);
    if(Vin <= cutoff)
    {
      packet[dataIn] = 0;
    }
    else
    {
      packet[dataIn] = 1;
    }
    dataIn++;
    delay(22);
  }
  placeholder = checkRecieved(packet);
  
  //calculateDelay = 22;
  //Need to calculate when to start the next sequencing here.
  for(int d = 0; d < 8; d++)
  {

    dataFrame[d] = recieveData();
    if(d = 7)
    {
      nextChar = convertToChar(dataFrame);
      serial.print(nextChar);
      d = 0;
      sentenceCounter++;
      
    }
    if(sentenceCounter = 11)
    {
      serial.println();
      sentenceCounter = 0;
    }
    delay(22);
  }
}
// Checks the recieved data to see where the data begins in our recieved sequence
int checkRecieved(int data[])
{
  int newFrame = 0;
  for(int x = 0; x <= 10; x++)
  {
    if(data[x] == 0 && data[x + 1] == 1 && data[x + 2] = 0 && data[x + 10] == 0 && data[x + 11] == 1 && data[x + 12] = 0)
    {
      newFrame = x + 12;
    }
  }
  return newFrame;
}
char convertToChar(int data[])
{
  int value = 0;
  char letter;
  value = (data[1] * 2^6) + (data[2] * 2^5) + (data[3] * 2^4) + (data[4] * 2^3) + (data[5] * 2^2) + (data[6] * 2^1) + (data[7] * 2^0);
  letter = char(value);
  return letter;
 }
 void samplePacket()
 {
  
 }
 int recieveData()
 {
  Vin = analogRead(inputPin);
  if(Vin > cutoff)
  {
    return 1;
  }
  else
  {
    return 0;
  }
 }

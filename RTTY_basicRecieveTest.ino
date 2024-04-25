  int dataFrame[8];
  int bitIn;
  int d;
  int sentenceCounter;
  char nextChar;
  int Vin;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  bitIn = 0;
  d=0;
  sentenceCounter=0;
  nextChar = '.';
  Vin = -1;
}

void loop() {
  // put your main code here, to run repeatedly:

while(d < 8)
  {
    
    bitIn = recieveData();
    dataFrame[d] = bitIn;
    d++;
    if(d = 7)
    {
      nextChar = convertToChar(dataFrame);
      if(!(  (nextChar == ' ') || (nextChar == 'H') || (nextChar == 'e') || (nextChar == 'l') || (nextChar == 'o') || (nextChar == 'W') || (nextChar == 'r') || (nextChar == 'd') || (nextChar == '!') )  )
      {
        delay(22);
      }
      Serial.print(nextChar);
      d = 0;
      sentenceCounter++;
      
    }
    if(sentenceCounter >= 11)
    {
      Serial.println();
      sentenceCounter = 0;
    }
    delay(22);
  }
}
char convertToChar(int data[])
{
  int value = 0;
  char letter;
  value = (data[1] * 2^6) + (data[2] * 2^5) + (data[3] * 2^4) + (data[4] * 2^3) + (data[5] * 2^2) + (data[6] * 2^1) + (data[7] * 2^0);
  letter = char(value);
  return letter;
 }
 int recieveData()
 {
  int cutoff = 512;
  Vin = analogRead(A1);
  if(Vin > cutoff)
  {
    return 1;
  }
  else
  {
    return 0;
  }
 }
  int dataFrame[8];
  int bitIn;
  int d;
  int sentenceCounter;
  char nextChar;
  int Vin;
  char previousChar;
  
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
      if((  (nextChar == ' ') || (nextChar == 'H') || (nextChar == 'e') || (nextChar == 'l') || (nextChar == 'o') || (nextChar == 'W') || (nextChar == 'r') || (nextChar == 'd') || (nextChar == '!') )  )
      {
        Serial.print(nextChar);
        d = 0;
        sentenceCounter = calculateSentenceCounter(nextChar, previousChar);
        delay(66);
      }
      else
      {
        delay(22);
        d = 0;
        sentenceCounter = 0;
      }
    }
    if(sentenceCounter >= 12)
    {
      Serial.println();
      sentenceCounter = 0;
    }
    previousChar = nextChar;
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
 int calculateSentenceCounter(char current, char former)
 {
  if(current == 'H')
  {
    sentenceCounter = 1;
  }
  if(current == 'e')
  {
    sentenceCounter = 2;
  }
  if((current == 'l') && (former == 'e'))
  {
    sentenceCounter = 3;
  }
  if((current == 'l') && (former == 'l'))
  {
    sentenceCounter = 4;
  }
  if(current == 'o')
  {
    sentenceCounter = 5;
  }
  if(current == ' ')
  {
    sentenceCounter = 6;
  }
  if(current == 'W')
  {
    sentenceCounter = 7;
  }
  if((current == 'o') && (former == 'W'))
  {
    sentenceCounter = 8;
  }
  if(current == 'r')
  {
    sentenceCounter = 9;
  }
  if((current == 'l') && (former == 'r'))
  {
    sentenceCounter = 10;
  }
  if(current == 'd')
  {
    sentenceCounter = 11;
  }
  if(current == '!')
  {
    sentenceCounter = 12;
  }
 }
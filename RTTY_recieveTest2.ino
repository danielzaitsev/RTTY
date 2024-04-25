  int packet[10];
  int bitIn;
  int d;
  int sentenceCounter;
  char nextChar;
  int Vin;
  char previousChar = 'P';
  
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

while(d < 10)
  {
    bitIn = recieveData();
    packet[d] = bitIn;
    
    if(d = 9)
    {
      nextChar = convertToChar(packet[2], packet[3], packet[4], packet[5], packet[6], packet[7], packet[8]);
      if((  (nextChar == ' ') || (nextChar == 'H') || (nextChar == 'e') || (nextChar == 'l') || (nextChar == 'o') || (nextChar == 'W') || (nextChar == 'r') || (nextChar == 'd') || (nextChar == '!') )  )
      {
        Serial.print(nextChar);
        d = 0;
        sentenceCounter = calculateSentenceCounter(nextChar, previousChar);
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
    d++;
    delay(22);
  }
}
char convertToChar(int bit1, int bit2, int bit3, int bit4, int bit5, int bit6, int bit7)
{
  int value = 0;
  char letter;
  value = (bit1 * 2^6) + (bit2 * 2^5) + (bit3 * 2^4) + (bit4 * 2^3) + (bit5 * 2^2) + (bit6 * 2^1) + (bit7 * 2^0);
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
  else if(current == 'e')
  {
    sentenceCounter = 2;
  }
  else if((current == 'l') && (former == 'e'))
  {
    sentenceCounter = 3;
  }
  else if((current == 'l') && (former == 'l'))
  {
    sentenceCounter = 4;
  }
  else if(current == 'o')
  {
    sentenceCounter = 5;
  }
  else if(current == ' ')
  {
    sentenceCounter = 6;
  }
  else if(current == 'W')
  {
    sentenceCounter = 7;
  }
  else if((current == 'o') && (former == 'W'))
  {
    sentenceCounter = 8;
  }
  else if(current == 'r')
  {
    sentenceCounter = 9;
  }
  else if((current == 'l') && (former == 'r'))
  {
    sentenceCounter = 10;
  }
  else if(current == 'd')
  {
    sentenceCounter = 11;
  }
  else if(current == '!')
  {
    sentenceCounter = 12;
  }
 }
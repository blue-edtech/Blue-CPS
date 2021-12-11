int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;

int time = 100;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop()
{
 PiscaLed1(time);
 PiscaLed2(time);
 PiscaLed3(time);
 PiscaLed4(time);
 PiscaLed5(time);
 PiscaLed6(time);
 PiscaLed7(time);
 PiscaLed8(time);
 PiscaLed9(time);
 PiscaLed10(time);
 PiscaLed10(time);
 PiscaLed9(time);
 PiscaLed8(time);
 PiscaLed7(time);
 PiscaLed6(time);
 PiscaLed5(time);
 PiscaLed4(time);
 PiscaLed3(time);
 PiscaLed2(time);
 PiscaLed1(time);
}

void PiscaLed1(int tempo)
{
  digitalWrite(led1,HIGH);
  delay(tempo);
  digitalWrite(led1,LOW);
  delay(tempo);
}

void PiscaLed2(int tempo)
{
  digitalWrite(led2,HIGH);
  delay(tempo);
  digitalWrite(led2,LOW);
  delay(tempo);
}

void PiscaLed3(int tempo)
{
  digitalWrite(led3, HIGH);
  delay(tempo);
  digitalWrite(led3,LOW);
  delay(tempo);
}

void PiscaLed4(int tempo)
{
  digitalWrite(led4, HIGH);
  delay(tempo);
  digitalWrite(led4, LOW);
  delay(tempo);
}

void PiscaLed5(int tempo)
{
  digitalWrite(led5, HIGH);
  delay(tempo);
  digitalWrite(led5, LOW);
  delay(tempo);
}

void PiscaLed6(int tempo)
{
  digitalWrite(led6, HIGH);
  delay(tempo);
  digitalWrite(led6, LOW);
  delay(tempo);
}

void PiscaLed7(int tempo)
{
  digitalWrite(led7,HIGH);
  delay(tempo);
  digitalWrite(led7, LOW);
  delay(tempo);
}

void PiscaLed8(int tempo)
{
  digitalWrite(led8, HIGH);
  delay(tempo);
  digitalWrite(led8, LOW);
  delay(tempo);
}

void PiscaLed9(int tempo)
{
  digitalWrite(led9,HIGH);
  delay(tempo);
  digitalWrite(led9, LOW);
  delay(tempo);
}

void PiscaLed10(int tempo)
{
  digitalWrite(led10, HIGH);
  delay(tempo);
  digitalWrite(led10, LOW);
  delay(tempo);
}
void setup()
{
  for(int porta = 14; porta >=4;porta--)
  {
  pinMode(porta, OUTPUT);
  }
}
void loop()
{
  int led = 14;
  for(led;led >=4;led--)
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  for(led; led <=13; led++)
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
}
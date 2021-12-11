int C1_Led_Vermelho = 13;
int C1_Led_Amarelo = 11;
int C1_Led_Verde = 7;
int C2_Led_Vermelho = 5;
int C2_Led_Amarelo = 4;
int C2_Led_Verde = 3;

void setup()
{
  pinMode(C1_Led_Vermelho, OUTPUT);
  pinMode(C1_Led_Amarelo, OUTPUT);
  pinMode(C1_Led_Verde, OUTPUT);
  pinMode(C2_Led_Vermelho, OUTPUT);
  pinMode(C2_Led_Amarelo, OUTPUT);
  pinMode(C2_Led_Verde, OUTPUT);
}

void loop()
{
  //Conjunto1
  Conjunto1(10000);
  //Desliga Verde C1
  digitalWrite(C1_Led_Verde, LOW);
  delay(1000);
  //Ligar Amarelo C1
  digitalWrite(C1_Led_Amarelo, HIGH);
  delay(3000);
  //Desligar Amarelo C1
  digitalWrite(C1_Led_Amarelo,LOW);
  delay(1000);
  //Conjunto2
  Conjunto2(10000);
  //Desligar Verde C2
  digitalWrite(C2_Led_Verde, LOW);
  delay(1000);
  //Ligar Amarelo C2
  digitalWrite(C2_Led_Amarelo, HIGH);
  delay(3000);
  //Desligar Amarelo C2
  digitalWrite(C2_Led_Amarelo, LOW);
  delay(1000);
  //Desligar Vermelho C1
  digitalWrite(C1_Led_Vermelho, LOW);
}

void Conjunto1(int temp)
{
  digitalWrite(C1_Led_Verde, HIGH);
  digitalWrite(C2_Led_Vermelho, HIGH);
  delay(temp);
}

void Conjunto2(int temp)
{
  digitalWrite(C1_Led_Vermelho, HIGH);
  digitalWrite(C2_Led_Vermelho, LOW);
  digitalWrite(C2_Led_Verde, HIGH);
  delay(temp);
}
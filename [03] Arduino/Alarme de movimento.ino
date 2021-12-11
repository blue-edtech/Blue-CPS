int sensor_pin = 13;
int sensor_state = 0;
int led = 12;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensor_state = digitalRead(sensor_pin);
  
  
  if(sensor_state == HIGH)
  {
    digitalWrite(led,HIGH);
    Serial.println("Sensor Ativado!!");
  }else
  {
  digitalWrite(led, LOW);
  }
}
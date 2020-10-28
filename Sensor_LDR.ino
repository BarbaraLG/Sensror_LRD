float Van;
float LDR;
float Rl;
float R;
float Il;

void setup() 
{
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  LDR = analogRead(A0);
  Van = LDR*5/1023;
  Rl = 615*((5/Van)-1);
  Il = pow((Rl/128432),-1.1655);
  if(Il < 2000)
  {
    digitalWrite(13,HIGH);  
  }
  else
  {
    digitalWrite(13,LOW);  
  }

  Serial.println("");
  Serial.print("El voltaje analogico es:");
  Serial.print(LDR);
  Serial.println(" V");
  Serial.print("La resistencia es:");
  Serial.print(Rl);
  Serial.println(" Ohms");
  Serial.print("La intensidad luninosa es:");
  Serial.print(Il);
  Serial.println(" Lux");
  delay(1000);
}

#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
int Pir = 4;
int led = 13;




void setup() {
  Serial.begin(9600);
  pinMode(Pir, INPUT);
  pinMode(led, OUTPUT);
  
  
  digitalWrite(Pir, LOW);
  digitalWrite(led, LOW);
  
  
  Serial.println("Calibration du capteur de mouvement.");
  Serial.println(" CAPTEUR ACTIVE ");
  delay(50);
  
  SIM900.begin(9600);
  Serial.begin(9600);
  Serial.println("OK");
  delay(1000);
  
  SIM900.println("AT+CPIN=\"0000\"");
  delay(25000);
}
void envoi_sms()
{
  Serial.println("ENVOI DU SMS..");
  SIM900.print("AT+CMGF=1\r");
  delay(1000);
  SIM900.println("AT+CMGS=\"0662794601\"");  
  delay(1000);
  SIM900.println("INTRUSION DETECTEE");
  delay(100);
  SIM900.println((char)26);
  delay(100);
  SIM900.println();
  delay(50000);
  SIM900.println("SMS envoyé");
}


void loop()
{
  

  if (digitalRead(Pir) == HIGH)
  { digitalWrite(led, HIGH);
   char Buzz= 7;

  for(int note=700;note<2000;note++) {
  tone(Buzz, note, 125);
  delay(1);
  }
  for(int note=2000;note>=700;note--)
  { tone(Buzz, note, 125);
  delay(1);
  }
  
  Serial.println(" MOUVEMENT DETECTE ");
  Serial.println("");
  delay(1000);
  
  envoi_sms();
  
}
else {
  digitalWrite(led, LOW);
 
  }
}



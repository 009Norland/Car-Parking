// C++ code
//
#include<SoftwareSerial.h>
SoftwareSerial BTserial(0,1);
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  BTserial.begin(9600);
}

void loop()
{
  digitalWrite(4, LOW);
  delay(2);
  digitalWrite(4, HIGH);
  delay(10); 
  digitalWrite(4,LOW);
  int timetaken=pulseIn(3,HIGH);
  int distance=timetaken*0.034/2;
  Serial.print("distance=");
  Serial.println(distance);
  BTserial.print("distance=");
  BTserial.println(distance);
  if(distance<=25){
    tone(5,400);
    delay(distance*20);
    noTone(5);
    delay(distance*20);  
  }
  else{
    noTone(5);
   
  }
}
/*Slave*/

#include <FlexiTimer2.h>
#include <Wire.h>
#include <SerialCommand.h>

SerialCommand SCmd;

int trigPin = 8;
int echoPin = 9;

void setup() {
  Wire.begin(8);
  Serial.begin(9600);
  Serial.println("Measuring unit initialization");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  int duration, distance;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); 

  distance = duration / 58;

  Serial.print(distance); 
  Serial.println(" cm"); 
  delay(100);

}

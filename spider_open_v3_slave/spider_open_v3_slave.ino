/*Slave*/

#include <FlexiTimer2.h>
#include <Wire.h>
#include <SerialCommand.h>

SerialCommand SCmd;

#define MQ9_PIN A0
#define MQ135_PIN A1

int trigPin = 8;
int echoPin = 9;
int mq9pin = 7;
float mq9value;
float mq9percents;
float mq135value;
float mq135percents;

void setup() {
  Wire.begin(8);
  Serial.begin(9600);
  Serial.println("Measuring unit initialization");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(mq9pin, INPUT);

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
  delay(1000);
  mq9value = analogRead(MQ9_PIN);
  mq135value = analogRead(MQ135_PIN);
  Serial.print("Значение mq9 ");
  Serial.println(mq9value);
  Serial.print("Значение mq135 ");
  Serial.println(mq135value);  
  delay(1000);
}

/*Slave*/

#include <FlexiTimer2.h>
#include <Wire.h>
#include <SerialCommand.h>
#include <iarduino_I2C_connect.h>


#define MQ9_PIN A0
#define MQ135_PIN A1

iarduino_I2C_connect I2C2;

SerialCommand SCmd;

byte REG_ARRAY[3];



int trigPin = 8;
int echoPin = 9;
int mq9pin = 7;
int distance, duration;
float mq9value;
float mq9percents;
float mq135value;
float mq135percents;

void setup() {
  Wire.setClock(400000);
  Wire.begin(8);
  Serial.begin(9600);
  I2C2.begin(REG_ARRAY);
  Serial.println("Measuring unit initialization");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {

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
 
  Serial.print("Значение mq9 на слэйве ");
  Serial.println(mq9value);
  Serial.print("Значение mq135 на слэйве ");
  Serial.println(mq135value);
  REG_ARRAY[0] = mq9value;
  REG_ARRAY[1] = mq135value;
  REG_ARRAY[2] = distance;

}

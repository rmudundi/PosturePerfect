#include "SR04.h"

//specify pins
int trig_pin1 = 12;
int echo_pin1 = 13;
int trig_pin2 = 4;
int echo_pin2 = 3;
int passive_buzzer_pin = 8;

SR04 sensor1 = SR04(echo_pin1, trig_pin1);
SR04 sensor2 = SR04(echo_pin2, trig_pin2);

long distance1, distance2;
int bad_count = 0;
int good_count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(passive_buzzer_pin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = sensor1.Distance();
  distance2 = sensor2.Distance();
  Serial.print("Distance 1: ");
  Serial.println(distance1);
  Serial.print("Distance 2: ");
  Serial.println(distance2);


  if (bad_count > 5) {
    tone(passive_buzzer_pin, 90);
    if (distance1 < distance2) {
      good_count += 1;
    }
    if (good_count > 5) {
      bad_count = 0;
      pinMode(passive_buzzer_pin, LOW);
      good_count = 0;
    }
  } else {
    pinMode(passive_buzzer_pin, LOW);
  }

  if (distance1 > distance2 or distance1 > distance2) {
    bad_count += 1; 
  } 

  // tone(passive_pin, 90); // turn passive buzzer on
  delay(800);

  Serial.print("Bad Count: ");
  Serial.println(bad_count);
  Serial.print("Good Count: ");
  Serial.println(good_count);
}

//right side goes to shoulder
//left side goes to neck
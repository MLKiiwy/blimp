#include <Wire.h>

#define AIN1 0 // GPIO0 D03
#define AIN2 2 // GPIO2 D04

#define BIN1 3 // GPIO3 - D09
#define BIN2 1 // GPIO1 - D10

#define HIN1 13 // GPIO13 - D7
#define HIN2 12 // GPIO12 - D6

#define PWM_F 15 // GPIO14 - D5
#define PWM_H 14 // GPIO15 - D8

#define STBY 16  // GPIO16 - D0 

#define SPEED_LOW 100
#define SPEED_HIGH 3000

#define TEN_SECONDS 10000

#define LEFT 1
#define RIGHT 2
#define TOP 3

#define FORWARD 1
#define BACKWARD 0

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 1023 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == RIGHT){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWM_F, speed);
  }else if (motor == LEFT) {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWM_F, speed);
  } else {
    digitalWrite(HIN1, inPin1);
    digitalWrite(HIN2, inPin2);
    analogWrite(PWM_H, speed);
  }
}

void stop(int motor) {
  move(motor, 0, 0);
}

void setup() {
  Serial.begin(115200);
    
  pinMode(PWM_F, OUTPUT);
  pinMode(PWM_H, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(HIN1, OUTPUT);
  pinMode(HIN2, OUTPUT);
}

void loop()
{
    Serial.println("GO FORWARD LEFT LOW SPEED");
    move(LEFT, SPEED_LOW, FORWARD);
    delay(TEN_SECONDS);
    stop(LEFT);

    Serial.println("GO FORWARD RIGHT LOW SPEED");
    move(RIGHT, SPEED_LOW, FORWARD);
    delay(TEN_SECONDS);
    stop(RIGHT);

    Serial.println("GO FORWARD UP LOW SPEED");
    move(TOP, SPEED_LOW, FORWARD);
    delay(TEN_SECONDS);
    stop(TOP);

    Serial.println("GO FORWARD LEFT HIGH SPEED");
    move(LEFT, SPEED_HIGH, FORWARD);
    delay(TEN_SECONDS);
    stop(LEFT);

    Serial.println("GO BACKWARD RIGHT LOW SPEED");
    move(RIGHT, SPEED_LOW, BACKWARD);
    delay(TEN_SECONDS);
    stop(RIGHT);

    Serial.println("GO BACKWARD LEFT LOW SPEED");
    move(LEFT, SPEED_LOW, BACKWARD);
    delay(TEN_SECONDS);
    stop(LEFT);

    Serial.println("GO BACKWARD TOP LOW SPEED");
    move(TOP, SPEED_LOW, BACKWARD);
    delay(TEN_SECONDS);
    stop(TOP);
}


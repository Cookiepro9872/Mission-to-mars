// C++ code
#define LEFT_REV 12
#define LEFT_FWD 11
#define LEFT_ENABLE 10
#define RIGHT_ENABLE 9
#define RIGHT_FWD 8
#define RIGHT_REV 7

const int RIGHT_FEEDBACK = 2;
const int LEFT_FEEDBACK = 3;

volatile int leftcounter = 0; 
volatile int rightcounter = 0; 

#include <NewPing.h>

#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void forward(int delaytime, int left_speed, int right_speed) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_REV, LOW);
  analogWrite(LEFT_ENABLE, left_speed);
  analogWrite(RIGHT_ENABLE, right_speed);
  delay(delaytime);
}  

void rev(int delaytime, int left_speed, int right_speed) {
  digitalWrite(LEFT_REV, HIGH);
  digitalWrite(RIGHT_REV, HIGH);
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  analogWrite(LEFT_ENABLE, left_speed);
  analogWrite(RIGHT_ENABLE, right_speed);
  delay(delaytime);
}

void left(int delaytime) {
  digitalWrite(LEFT_REV, HIGH);
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  delay(delaytime);
}

void right(int delaytime) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_REV, HIGH);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  delay(delaytime);
}

void stop() {
  digitalWrite(LEFT_ENABLE, LOW);
  digitalWrite(RIGHT_ENABLE, LOW);
}

void forward_count(int count, int speed) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_REV, LOW);
  while(leftcounter < count) {
    analogWrite(LEFT_ENABLE, speed);
    analogWrite(RIGHT_ENABLE,  speed);
  }
  digitalWrite(LEFT_ENABLE, LOW);
  digitalWrite(RIGHT_ENABLE, LOW);
}

void setup()
{
  pinMode(LEFT_REV, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);

  Serial.begin(115200);
  int distance = sonar.ping_cm();
}

void story4() {
  forward(5000, 255, 255);

  stop();
  delay(1000);

  rev(2000, 255, 255);
}

void LeftMotorISR(){
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}

void story5() {
  forward(2000, 255, 255);

  forward(2000, 100, 200);

  forward(2000, 200, 100);

  forward(2000, 100, 200);

  forward(2000, 200, 100);
}

void story6() {
  forward_count(870, 255);
}

void story7() {
  forward(2000, 255, 255);

  left(850);

  forward(2000, 255, 255);

  left(850);

  forward(2000, 255, 255);

  left(850);

  forward(2000, 255, 255);

  left(850);

  forward(2000, 255, 255);

  right(850);

  forward(2000, 255, 255);

  right(850);

  forward(2000, 255, 255);

  right(850);

  forward(2000, 255, 255);

  right(850);

  stop();

  exit(0);

}
void loop()
{
  int distance = sonar.ping_cm();

  if distance < 13 and distance > 0 {
    stop();

    delay(500);

    left(850);

    stop();
  } else {
    forward(50,255,255);
  }
}

// C++ code
#define LEFT_REV 12
#define LEFT_FWD 11
#define LEFT_ENABLE 10
#define RIGHT_ENABLE 9
#define RIGHT_FWD 8
#define RIGHT_REV 7

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
}

void stop() {
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
}

void story4() {
  forward(5000, 255, 255);

  stop();
  delay(1000);

  rev(2000, 255, 255);
}

void loop()
{
  forward(2000, 255, 255);

  forward(2000, 100, 200);

  forward(2000, 200, 100);

  forward(2000, 100, 200);

  forward(2000, 200, 100);
}

// C++ code
#define LEFT_REV 12
#define LEFT_FWD 11
#define LEFT_ENABLE 10
#define RIGHT_ENABLE 9
#define RIGHT_FWD 7
#define RIGHT_REV 8

void forward(int delaytime) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_REV, LOW);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  delay(delaytime);
}  

void rev(int delaytime) {
  digitalWrite(LEFT_REV, HIGH);
  digitalWrite(RIGHT_REV, HIGH);
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
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

void loop()
{
  forward(5000);
  
  stop();
  delay(1000);
  
  rev(2000);
}

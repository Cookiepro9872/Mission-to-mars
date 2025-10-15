// C++ code
#define LED_PIN1 12
#define LED_PIN2 11
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}

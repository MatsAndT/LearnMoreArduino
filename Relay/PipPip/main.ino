const int relayPin1 = 2;
const int relayPin2 = 3;
const int relayPin3 = 4;
const int relayPin4 = 5;

void setup() {
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);

}

void loop() {
  digitalWrite(relayPin1, HIGH);
  delay(300);
  digitalWrite(relayPin1, LOW);
  delay(100);
  digitalWrite(relayPin2, HIGH);
  delay(300);
  digitalWrite(relayPin2, LOW);
  delay(100);
  digitalWrite(relayPin3, HIGH);
  delay(300);
  digitalWrite(relayPin3, LOW);
  delay(100);
  digitalWrite(relayPin4, HIGH);
  delay(300);
  digitalWrite(relayPin4, LOW);
  delay(100);
}
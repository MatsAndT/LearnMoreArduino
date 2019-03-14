//Sender Code

int state = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
    Serial.write(state);
    state = !state;
    delay(1000);
}

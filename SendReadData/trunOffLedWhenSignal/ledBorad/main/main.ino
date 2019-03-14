//Receiver Code

int state = 0;
int led = 9;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
    state = Serial.read();
    
    digitalWrite(led, state);
  }  
}

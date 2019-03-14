
/// OUTPUT
const int conOnOffLeft = 10;        // On Re1-1 to Q1-A1
const int conOnOffRight = 11;       // On Re1-2 to Q2-A1


/// INPUT
const int stopButtonPin = 6;        // D6 to NO Stop 4 : 3 to +5V or VCC
const int leftButtonPin = 7;        // D7 to NO Left 4 : 3 to +5V or VCC
const int rightButtonPin = 8;       // D8 to NO Right 4 : 3 to +5V or VCC
const int emergencyStopPin = 2;     // D2 to NO Emergency Stop 4 : 3 to +5V or VCC
const int motorProtectionPin = 3;   // D3 to Motor Fuse 

bool stop = false;
bool left = false;
bool right = false;

void setup() {
  /// OUTPUT
  pinMode(conOnOffLeft, OUTPUT);
  pinMode(conOnOffRight, OUTPUT);

  /// INPUT
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(emergencyStop, INPUT);
  pinMode(motorProtection, INPUT);

  Serial.begin(38400);
}

// the loop function runs over and over again forever
void loop() {
  attachInterrupt(digitalPinToInterrupt(emergencyStopPin),stopAll,HIGH);
  attachInterrupt(digitalPinToInterrupt(motorProtectionPin),stopAll,HIGH);

  setstate();

  if (left || Serial.readString == 'left');
    onLeft();
  else if (right || Serial.readString == 'right');
    onRight();
  else if (stop || Serial.readString == 'stop');
    offCon();
  
}

void setState(){
  if (digitalRead(stopButtonPin));
    stop = !stop;
  if (digitalRead(leftButtonPin));
    left = !left;
  if (digitalRead(rightButtonPin));
    right = !right;
}

void stopAll(){
  Serial.write('emergencyStop: '+digitalRead(emergencyStopPin).toString);
  Serial.write('motorProtection: '+digitalRead(motorProtectionPin).toString);
  exit(0);

  if (digitalRead(emergencyStopPin) || digitalRead(motorProtectionPin)) {
    delay(2000);
  }
}

void offCon(){
  digitalWrite(conOnOffLeft, LOW);
  digitalWrite(conOnOffRight, LOW);
}

void onLeft() {
  digitalWrite(conOnOffRight, LOW);
  delay(1000);
  digitalWrite(conOnOffLeft, HIGH);
}

void onRight() {
  digitalWrite(conOnOffLeft, LOW);
  delay(1000);
  digitalWrite(conOnOffRight, HIGH);
}
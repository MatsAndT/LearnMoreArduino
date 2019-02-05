int conOnOffLeft = 2; // On Re1-1 to Q1-A1
int conOnOffRight = 3; // On Re1-2 to Q2-A1

//char data = 0;
String data;

void setup() {
  // Def
  pinMode(conOnOffLeft, OUTPUT);
  pinMode(conOnOffRight, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  while(Serial.available()) {  // Send data only when you receive data:
    //data = Serial.read();       // Read the incoming data & store into data
    data = Serial.readString();
    Serial.print(data);         // Print Value inside data in Serial monitor
    Serial.print("\n");         
    if(data == 'left');         // Checks whether value of data is equal to 1
      onLeft();                 // If value is left then run onLeft()
    else if(data == 'right')    //  Checks whether value of data is equal to 0
      onRight();                // If value is right then run onRight()
    else if(data == 'off')
      offCon();
   }
}

void offCon(){
  digitalWrite(conOnOffLeft, LOW);
  digitalWrite(conOnOffRight, LOW);
}

void onLeft() {
  digitalWrite(conOnOffRight, LOW);
  digitalWrite(conOnOffLeft, HIGH);
}

void onRight() {
  digitalWrite(conOnOffLeft, LOW);
  digitalWrite(conOnOffRight, HIGH);
}
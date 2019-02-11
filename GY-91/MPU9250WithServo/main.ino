#include "MPU9250.h"
#include "Servo.h"

int servoPin = 3;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

MPU9250 mpu = MPU9250();

void setup(void) {
  Serial.begin(9600);  
  uint8_t temp = mpu.begin();
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //Gyro
  mpu.set_gyro_range(RANGE_GYRO_250);
  mpu.get_gyro();
  Serial.print("GX: ");  Serial.print(mpu.gx); 
  Serial.print(" GY: "); Serial.print(mpu.gy); 
  Serial.print(" GZ: "); Serial.print(mpu.gz);
    myservo.write(mpu.gy/100);
  mpu.get_gyro_d();
  Serial.print(" GX_g: "); Serial.print(mpu.gx_d,2); 
  Serial.print(" GY_g: "); Serial.print(mpu.gy_d,2); 
  Serial.print(" GZ_g: "); Serial.print(mpu.gz_d,2); Serial.println(" º/s");

    
  // Temp     
  Serial.print("Temperature is ");  Serial.print((((float) mpu.get_temp()) / 333.87 + 21.0), 1);  Serial.println(" degrees C");
  
  delay(500);
}
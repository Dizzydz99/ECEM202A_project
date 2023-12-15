#include <Arduino_BMI270_BMM150.h>

float deltat;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // print the header
  Serial.println("aX,aY,aZ,mX,mY,mZ,gX,gY,gZ");
}

void loop() {
  float aX, aY, aZ, mX, mY, mZ, gX, gY, gZ;
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable() && IMU.magneticFieldAvailable()) {
    // read the acceleration and gyroscope data
    IMU.readAcceleration(aX, aY, aZ);
    IMU.readMagneticField(mX, mY, mZ);
    IMU.readGyroscope(gX, gY, gZ);

    // print the data in CSV format
    Serial.print(aX, 3);
    Serial.print(',');
    Serial.print(aY, 3);
    Serial.print(',');
    Serial.print(aZ, 3);
    Serial.print(',');
    Serial.print(mX, 3);
    Serial.print(',');
    Serial.print(mY, 3);
    Serial.print(',');
    Serial.print(mZ, 3);
    Serial.print(',');
    Serial.print(gX, 3);
    Serial.print(',');
    Serial.print(gY, 3);
    Serial.print(',');
    Serial.print(gZ, 3);
    Serial.println();
  }
}
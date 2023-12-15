#include <Arduino_BMI270_BMM150.h>
#include "MadgwickAHRS.h"

// initialize a Madgwick filter:
Madgwick filter;
// sensor's sample rate is fixed at 104 Hz:
const float sensorRate = 104.00;

void setup() {
  Serial.begin(9600);
  // attempt to start the IMU:
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    // stop here if you can't access the IMU:
    while (true);
  }
  // start the filter to run at the sample rate:
  filter.begin(sensorRate);
}

void loop() {
  // values for acceleration and rotation:
  float xAcc, yAcc, zAcc;
  float xGyro, yGyro, zGyro;
  float xMag, yMag, zMag;

  // values for orientation:
  float roll, pitch, yaw;
  // check if the IMU is ready to read:
  if (IMU.accelerationAvailable() &&
      IMU.gyroscopeAvailable()) {
    // read accelerometer &and gyrometer:
    IMU.readAcceleration(xAcc, yAcc, zAcc);
    IMU.readGyroscope(xGyro, yGyro, zGyro);
    IMU.readMagneticField(xMag, yMag, zMag);

    // update the filter, which computes orientation:
    filter.updateIMU(xGyro, yGyro, zGyro, xAcc, yAcc, zAcc);

    // print the heading, pitch and roll
    roll = filter.getRollRadians();
    pitch = filter.getPitchRadians();
    yaw = filter.getYawRadians();
  Serial.print(xAcc, 3);
  Serial.print(',');
  Serial.print(yAcc, 3);
  Serial.print(',');
  Serial.print(zAcc, 3);
  Serial.print(',');
  Serial.print(xMag, 3);
  Serial.print(',');
  Serial.print(yMag, 3);
  Serial.print(',');
  Serial.print(zMag, 3);
  Serial.print(',');
  Serial.print(xGyro, 3);
  Serial.print(',');
  Serial.print(yGyro, 3);
  Serial.print(',');
  Serial.print(zGyro, 3);
  Serial.print(',');
  Serial.print(pitch); 
  Serial.print(',');
  Serial.print(roll); 
  Serial.print(',');
  Serial.println(yaw);
  }
} 
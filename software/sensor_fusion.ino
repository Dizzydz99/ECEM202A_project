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
  // float xAcc_offset, yAcc_offset, zAcc_offset;
  // float xGyro_offset, yGyro_offset, zGyro_offset;
  // xAcc_offset = 0.007995863034623218;
  // yAcc_offset = -0.02568018075356416;
  // zAcc_offset = 0.004997963340122136;
  // xGyro_offset = -0.0246725432790224;
  // yGyro_offset = -0.11380040733197554;
  // zGyro_offset = 0.039732306517311605;

  // values for orientation:
  float roll, pitch, yaw;
  // check if the IMU is ready to read:
  if (IMU.accelerationAvailable() &&
      IMU.gyroscopeAvailable()) {
    // read accelerometer &and gyrometer:
    IMU.readAcceleration(xAcc, yAcc, zAcc);
    IMU.readGyroscope(xGyro, yGyro, zGyro);

    // update the filter, which computes orientation:
    // filter.updateIMU(xGyro - xGyro_offset, yGyro - yGyro_offset, zGyro - zGyro_offset, xAcc - xAcc_offset, yAcc - yAcc_offset, zAcc - zAcc_offset);

    // print the heading, pitch and roll
    roll = filter.getRollRadians();
    pitch = filter.getPitchRadians();
    yaw = filter.getYawRadians();
    Serial.print(pitch); 
    Serial.print(":");
    Serial.print(roll); 
    Serial.print(":");
    Serial.println(yaw);
  }
}
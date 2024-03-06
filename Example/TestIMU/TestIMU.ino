#include "RMRC_Breakout.h"

RMRC_IMU imu;

void setup() {
  Serial.begin(115200);

  imu.begin();
  delay(300);
}

void loop() {
  imu.update();
  Serial.print(imu.yaw); Serial.print("\t");
  Serial.print(imu.pitch); Serial.print("\t");
  Serial.println(imu.roll);
}
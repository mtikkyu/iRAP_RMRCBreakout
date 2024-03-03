#include "RMRC_Breakout.h"

#define GEAR_RATIO 34.0f //34:1
#define MAXIMUM_OUTPUT_SPEED 294.0f //RPM

RMRC_Base base(MAXIMUM_OUTPUT_SPEED * GEAR_RATIO, MAXIMUM_OUTPUT_SPEED * GEAR_RATIO);

void setup() {
  delay(400);
  Serial.begin(115200);

  base.begin();
  base.setDuty(0, 0);
}

void loop() {
  testSetDuty();
  // testSetRpm();
  // testSetPID();
}

void testSetDuty() {
  base.setDuty(MAXIMUM_DUTY, MAXIMUM_DUTY);

  Serial.print("RPM_L = "); Serial.print(base.ml.rpm); Serial.print("\t");
  Serial.print("RPM_R = "); Serial.println(base.mr.rpm);
}

void testSetRpm() {
  base.setRpm(base.ml.maximum_rpm, base.mr.maximum_rpm);

  Serial.print("RPM_L = "); Serial.print(base.ml.rpm); Serial.print("\t");
  Serial.print("RPM_R = "); Serial.println(base.mr.rpm);
}

void testPID() {
  Serial.print("MotorL : ");
  Serial.print("KP = "); Serial.print(base.ml.kp); Serial.print("\t");
  Serial.print("KI = "); Serial.print(base.ml.kp); Serial.print("\t");
  Serial.print("KD = "); Serial.println(base.ml.kp);

  Serial.print("MotorR : ");
  Serial.print("KP = "); Serial.print(base.ml.kp); Serial.print("\t");
  Serial.print("KI = "); Serial.print(base.ml.kp); Serial.print("\t");
  Serial.print("KD = "); Serial.println(base.ml.kp);

  base.setKp(0.0f, 0.0f);
  base.setKi(0.0f, 0.0f);
  base.setKd(0.0f, 0.0f);

  base.setRpm(150.0f * GEAR_RATIO, 150.0f * GEAR_RATIO);  
}
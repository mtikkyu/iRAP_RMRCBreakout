#include "RMRC_Breakout.h"

// Instructions for setting up the flipper:
// 1. Rotate the flipper to be parallel with the floor.
// 2. Read the offset value of the current position of the flipper by printing the value of "flipper.getOffset();".
//    Then, set this value as the first parameter of the function "flipper.setOffset();", ensuring the value falls between 1300 and 2700.
// 3. Rotate the flipper upwards by 180 degrees, then print the value of "getKAngle();"
//    and set this value as the second parameter of the function "flipper.setOffset();".
// 4. Rotate the flipper downwards by 360 degrees, then print the value of "getKAngle();"
//    and set this value as the final parameter of the function "flipper.setOffset();".

RMRC_Flipper flipper;

void setup() {
  delay(400);
  Serial.begin(115200);

  flipper.begin();
  flipper.setDuty(0);
  flipper.setOffset(0, 0, 0);
}

void loop() {
  flipper.setDuty(MAXIMUM_DUTY);
  
  Serial.print("Offset = ");  Serial.print(flipper.getOffset()); Serial.print("\t");
  Serial.print("k_angle = "); Serial.print(flipper.getKAngle()); Serial.print("\t");
  Serial.print("POSITION = "); Serial.println(flipper.position);
  delay(10);
}
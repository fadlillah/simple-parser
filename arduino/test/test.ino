#include "event_io.h"

void setup()
{
  Serial.begin(19200);
  Serial.println("Hallo start");
  delay(1000);
  insertEventIO(71, 1, 1);
  // insertEventIO(72, 1, 1);
  // insertEventIO(73, 2, 2);
  // insertEventIO(74, 2, 2);
  Serial.println("Hallo stop");
}

void loop()
{
  String hexString = toHexString();
  Serial.println("Hallo Word!!");
  Serial.print("TEST DATA =>>");
  Serial.println(hexString);
  delay(1000);
}

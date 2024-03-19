#include "event_io.h"

void setup()
{
  Serial.begin(19200);
  insertEventIO(71, 1, 1);
  insertEventIO(72, 1, 1);
  insertEventIO(73, 2, 2);
  insertEventIO(74, 2, 2);
}

void loop()
{
  String hexString = toHexString();
  Serial.print("TEST DATA =>>");
  Serial.println(hexString);
  delay(1000);
}

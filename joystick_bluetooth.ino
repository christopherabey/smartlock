#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,12);

void setup() {
  Serial.begin(38400);
  Serial.print("checking connection");
  mySerial.begin(38400);
}

int xValue = 0;

void loop() {
  xValue = analogRead(A0);
  Serial.println(xValue);
  delay(2000);

  if(xValue < 200) {
    Serial.print("unlocking: ");
    Serial.println(xValue);
    mySerial.write('0');
    delay(2000);
  } else if (xValue > 400) {
    Serial.print("locking: ");
    Serial.println(xValue);
    mySerial.write('1');
    delay(2000);
  }
}


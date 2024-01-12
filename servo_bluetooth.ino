#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,12);
Servo myservo;

void setup() {
  Serial.begin(38400);
  Serial.println("connection on line 38400");
  mySerial.begin(38400);
  myservo.attach(8);
}

int pos = 0;
int unlockDistance = 83;
int lockDistance = 150;
char command = 0; 

void loop() {

  if(mySerial.available()){
    Serial.println("caught something");
    command = mySerial.read();
    Serial.println(command);

    if(command == '0') {
      unlock();
    } else if (command == '1') {
      lock();
    }
  }

  if(Serial.available()){
    Serial.println("caught something");
    command = Serial.read();
    Serial.println(command);

    if(command == '0') {
      unlock();
    } else if (command == '1') {
      lock();
    }
  }
}

void lock() {
  for (pos = unlockDistance; pos < lockDistance; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15 ms for the servo to reach the position
  }
}

void unlock() {
  for (pos = lockDistance; pos > unlockDistance; pos -= 2) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15 ms for the servo to reach the position
  }
}

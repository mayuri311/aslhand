#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int pos = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
}

void fullFlex(Servo& s) {
  for (pos = 0; pos <= 360; pos += 1) {
    s.write(pos);
    delay(10);
  }
}

void fullFlexReturn(Servo& s) {
  for (pos = 360; pos >= 0; pos -= 1) {
    s.write(pos);
    delay(10);
  }
}

void halfFlex(Servo& s) {
  for (pos = 0; pos <= 90; pos += 1) {
    s.write(pos);
    delay(10);
  }
}

void halfFlexReturn(Servo& s) {
  for (pos = 90; pos >= 0; pos -= 1) {
    s.write(pos);
    delay(10);
  }
}

void loop() {
 
  fullFlex(servo1);
  fullFlexReturn(servo1);

  fullFlex(servo2);
  fullFlexReturn(servo2);

  fullFlex(servo3);
  fullFlexReturn(servo3);

  fullFlex(servo4);
  fullFlexReturn(servo4);

  fullFlex(servo5);
  fullFlexReturn(servo5);

  delay(1000);
  exit(0);
  // if (Serial.available()) {
  //   String input = Serial.readStringUntil('\n');
  //   input.trim();

  //   int thumbVal = input.charAt(0) - '0';
  //   if (thumbVal == 1) {
  //     fullFlex();
  //   } else {
  //     fullFlexReturn();
  //   }
  // }
}

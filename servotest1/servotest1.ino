#include <Servo.h>

Servo thumb;
Servo pinky;
Servo middle;
Servo ring;
Servo index;

int pos = 0;

void setup() {
  Serial.begin(9600);
  thumb.attach(2);
  pinky.attach(3);
  middle.attach(4);
  ring.attach(5);
  index.attach(6);

  thumb.write(180);
  pinky.write(180);
  middle.write(0);
  ring.write(0);
  index.write(0);
}

void fullFlex(Servo& s, int start) {
  for (pos = start; pos <= 180 + start; pos += 1) {
    s.write(pos);
    delay(10);
  }
}

void fullFlexReturn(Servo& s, int start) {
  for (pos = start + 180; pos >= start; pos -= 1) {
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

// perform the ASL gesture for 'i love you'
void ily() {
  fullFlex(middle, 0);
  fullFlex(ring, 0);
  fullFlexReturn(thumb, 0);
  delay(1000);
  fullFlexReturn(middle, 0);
  fullFlexReturn(ring, 0);
  fullFlex(thumb, 0);
}

// perform the ASL letter L
void letterL() {
  fullFlex(middle, 0);
  fullFlex(ring, 0);
  fullFlexReturn(pinky, 0);
  delay(1000);
  fullFlexReturn(middle, 0);
  fullFlexReturn(ring, 0);
  fullFlex(pinky, 0);
}

// perform the ASL letter V
void letterV() {
  fullFlex(ring, 0);
  fullFlexReturn(pinky, 0);
  fullFlexReturn(thumb, 0);
  delay(1000);
  fullFlexReturn(ring, 0);
  fullFlex(pinky, 0);
  fullFlex(thumb, 0);
}

// test all fingers' flexion one by one
void test() {
  fullFlexReturn(thumb, 0);
  fullFlex(thumb, 0);

  fullFlexReturn(pinky, 0);
  fullFlex(pinky, 0);

  fullFlex(middle, 0);
  fullFlexReturn(middle, 0);

  fullFlex(ring, 0);
  fullFlexReturn(ring, 0);

  fullFlex(index, 0);
  fullFlexReturn(index, 0);
}

void loop() {
  ily();
  delay(1000);
  letterL();
  delay(1000);
  letterV();
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

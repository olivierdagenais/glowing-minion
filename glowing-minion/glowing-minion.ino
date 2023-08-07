// Copyright (c) Olivier Dagenais. All rights reserved.
// Licensed under the MIT license. See LICENSE in the project root.

/*
 * A program to toggle LED lights
 */

const int buttonPin = 0;
const int ledPins[] = {
  3,
  6,
  9
};
const int ledPinCount = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  for (int o = 0; o < ledPinCount; o++) {
    int digitalPin = ledPins[o];
    pinMode(digitalPin, OUTPUT);
  }
}

int brightness = 0;
int buttonState = 0;
int lightState = 0;

void notify(String message) {
  Serial.print(message);
  Serial.println();
}

void loop() {

  int v = digitalRead(buttonPin);
  if (buttonState == 1) { // button was pressed
    if (v == 1) { // now it's released
      notify("Button released");
      buttonState = 0;
    }
  }
  else { // button wasn't pressed
    if (v == 0) { // now it's pressed
      notify("Button pressed");
      buttonState = 1;
      lightState = !lightState;
    }
  }

  if (!lightState) {
    brightness = 0;
  }
  else {
    brightness = 255;
  }

  for (int c = 0; c < ledPinCount; c++) {
    int digitalPin = ledPins[c];
    analogWrite(digitalPin, brightness);
  }

  delay(30);
}

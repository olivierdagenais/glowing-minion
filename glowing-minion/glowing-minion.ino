// Copyright (c) Olivier Dagenais. All rights reserved.
// Licensed under the MIT license. See LICENSE in the project root.

/*
 * A program to toggle pulsing LED lights
 */

const int buttonPin = 0;
const int ledPins[] = {
  3,
  6
};
const int ledPinCount = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  for (int o = 0; o < ledPinCount; o++) {
    int digitalPin = ledPins[o];
    pinMode(digitalPin, OUTPUT);
  }
}

int brightness = 0;
int fadeAmount = 5;

void loop() {

  int v = digitalRead(buttonPin);
  Serial.print(v == 0 ? 1 : 0);
  Serial.println();

  for (int c = 0; c < ledPinCount; c++) {
    int digitalPin = ledPins[c];
    analogWrite(digitalPin, brightness);
  }

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    brightness = brightness + fadeAmount;
  }

  delay(30);
}

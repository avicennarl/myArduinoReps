/*
Tested di Arduino Uno R3 ke Stepper Motor 42BYGHW811
Motor Driver: L298N
Urusan pinout 
-format: Arduino - L298N
-- 5v Ardu - 12v L298N
-- GND Ardu - GND L298N
-- pastikan jumper depan plug 12V pada L298N tersambung!!
-- ENA dan ENB pada L298N masing-masing terjumper depan belakang
-- Pin 8 Ardu - IN1 LN298N
-- Pin 9 Ardu - IN2 LN298N
-- Pin 10 Ardu - IN3 LN298N
-- Pin 11 Ardu -- IN4 LN298N
*/


// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation, sesuaikan dengan motor stepper 42BYGHW811
const int stepsPerRevolution = 200;

// Create an instance of the Stepper class
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed at 60 RPM
  myStepper.setSpeed(60);

  // Initialize the serial communication
  Serial.begin(9600);
  Serial.println("Ready to receive commands...");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read the command as a string
    String command = Serial.readStringUntil('\n');

    // Handle command for 45 degrees
    if (command == "45") {
      Serial.println("Moving 45 degrees clockwise...");
      myStepper.step(stepsPerRevolution / 8); // 45 degrees (1/8 of a full revolution)
      Serial.println("Done moving 45 degrees.");
    } 
    // Handle command for 90 degrees
    else if (command == "90") {
      Serial.println("Moving 90 degrees clockwise...");
      myStepper.step(stepsPerRevolution / 4); // 90 degrees (1/4 of a full revolution)
      Serial.println("Done moving 90 degrees.");
    }
  }
}

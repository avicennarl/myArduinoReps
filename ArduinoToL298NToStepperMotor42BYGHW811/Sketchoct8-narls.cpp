/*
08102024 
Tested di Arduino Uno R3 ke Stepper Motor 42BYGHW811
Motor Driver: L298N
URUSAN HUBUNGAN PIN
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

// Sertakan Library Stepper Arduino
#include <Stepper.h>

// Jumlah langkah per putaran output, sesuaikan dengan motor stepper 42BYGHW811
const int langkahPerPutaran = 200;

// Buat instance dari kelas Stepper
Stepper motorStepper(langkahPerPutaran, 8, 9, 10, 11);

void setup() {
  // Atur kecepatan pada 60 RPM
  motorStepper.setSpeed(60);

  // Inisialisasi komunikasi serial
  Serial.begin(9600);
  Serial.println("Siap menerima perintah...");
}

void loop() {
  // Periksa apakah data tersedia di port serial
  if (Serial.available() > 0) {
    // Baca perintah sebagai string
    String perintah = Serial.readStringUntil('\n');

    // Tangani perintah untuk 45 derajat
    if (perintah == "45") {
      Serial.println("Memindahkan 45 derajat searah jarum jam...");
      motorStepper.step(langkahPerPutaran / 8); // 45 derajat (1/8 dari satu putaran penuh)
      Serial.println("Selesai memindahkan 45 derajat.");
    } 
    // Tangani perintah untuk 90 derajat
    else if (perintah == "90") {
      Serial.println("Memindahkan 90 derajat searah jarum jam...");
      motorStepper.step(langkahPerPutaran / 4); // 90 derajat (1/4 dari satu putaran penuh)
      Serial.println("Selesai memindahkan 90 derajat.");
    }
  }
}

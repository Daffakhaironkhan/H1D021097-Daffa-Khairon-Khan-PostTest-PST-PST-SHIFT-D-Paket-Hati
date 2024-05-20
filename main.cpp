#include <Arduino.h>
#include <Servo.h>

// Deklarasi objek Servo
Servo myServo;

// Pin untuk LED hijau dan merah
int ledHijau = D1;
int ledMerah = D2;

void setup()
{
  // Mengatur pin LED sebagai OUTPUT
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  
  // Melampirkan servo ke pin D3
  myServo.attach(D3);
}

void loop() {
  // Menggerakkan servo ke posisi tengah (90 derajat)
  myServo.write(90);
  delay(5000); // Menunggu 5 detik
  
  // Menggerakkan servo dari posisi 0 ke 180 derajat
  for(int pos = 0; pos <= 180; pos += 1){
    myServo.write(pos); // Menggerakkan servo ke posisi saat ini
    digitalWrite(ledMerah, LOW); // Mematikan LED merah
    digitalWrite(ledHijau, HIGH); // Menyalakan LED hijau
    delay(50); // Memberikan delay untuk pergerakan servo
  }
  delay(5000); // Menunggu 5 detik
  
  // Menggerakkan servo dari posisi 180 ke 0 derajat
  for(int pos = 180; pos >= 0; pos -= 1){
    myServo.write(pos); // Menggerakkan servo ke posisi saat ini
    digitalWrite(ledHijau, LOW); // Mematikan LED hijau
    digitalWrite(ledMerah, HIGH); // Menyalakan LED merah
    delay(50); // Memberikan delay untuk pergerakan servo
  }
  delay(5000); // Menunggu 5 detik
}

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// RFID Pins
#define SS_PIN D4
#define RST_PIN D3

// I2C Pins
#define SDA_PIN D2
#define SCL_PIN D1

// Buzzer Pin
#define BUZZER_PIN D0

// LCD I2C Address and size
LiquidCrystal_I2C display(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600); // ✅ Must match Python script
  SPI.begin();
  rfid.PCD_Init();

  // LCD Init
  Wire.begin(SDA_PIN, SCL_PIN);
  display.init();
  display.backlight();
  display.setCursor(0, 0);
  display.print("Scan RFID Tag");

  // Buzzer Setup
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Read UID
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  // Serial Output (sent to Python)
  Serial.println(uid);

  // LCD Output
  display.clear();
  display.setCursor(0, 0);
  display.print("UID:");
  display.setCursor(0, 1);
  display.print(uid);

  // Buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);

  delay(2000); // Wait before next scan
  display.clear();
  display.setCursor(0, 0);
  display.print("Scan RFID Tag");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

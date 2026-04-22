# 🔐 Smart RFID-Based Access Control System

A **contactless access control system** built with **ESP8266 NodeMCU**, **RC522 RFID reader**, **16x2 LCD**, and **buzzer**.  
The project demonstrates how RFID technology combined with IoT-ready microcontrollers can provide **secure, scalable, and cost-effective authentication** for modern environments.

---

## ✨ Features
- RFID-based **authentication** using RC522 module & unique tag UIDs  
- **LCD feedback** → `Access Granted` / `Access Denied`  
- **Buzzer alerts** for instant audio feedback  
- **IoT-ready design** with ESP8266 Wi-Fi capability (future cloud integration possible)  
- **Modular and affordable** → built with widely available components  

---

## 🛠 Components Used
- ESP8266 NodeMCU  
- RC522 RFID Reader Module  
- RFID Cards/Tags  
- 16x2 LCD Display (with I2C adapter)  
- Buzzer  
- Breadboard, jumper wires, USB 5V power supply  

---

## 📐 Circuit Diagram


RC522 → ESP8266 NodeMCU (SPI)

* SDA  → D2 (GPIO4)
* SCK  → D5 (GPIO14)
* MOSI → D7 (GPIO13)
* MISO → D6 (GPIO12)
* RST  → D1 (GPIO5)
* 3.3V → 3.3V
* GND  → GND

LCD (I2C) → ESP8266

* SDA → D3 (GPIO0)
* SCL → D4 (GPIO2)
* VCC → 5V
* GND → GND

Buzzer → ESP8266

* Positive → D8 (GPIO15)
* Negative → GND


<img width="422" height="563" alt="image" src="https://github.com/user-attachments/assets/aec5867b-cbdd-48ef-938b-2b699605f77a" />


---

## ⚡ How It Works
1. Power on the system (5V USB supply).  
2. LCD prompts → `Scan RFID Card`.  
3. Place RFID tag near RC522 reader.  
   - If UID matches → LCD shows `Access Granted`, buzzer beeps once.  
   - If UID not found → LCD shows `Access Denied`, buzzer long beep.  
4. Optional: UID logging or cloud integration for future scalability.  

---

## 📦 Installation & Usage
1. Install [Arduino IDE](https://www.arduino.cc/en/software).  
2. Add **ESP8266 board package** in Arduino IDE.  
3. Install required libraries:  
   - `MFRC522` (for RFID)  
   - `LiquidCrystal_I2C` (for LCD)  
   - `SPI`, `Wire` (included by default)  
4. Connect the hardware as per circuit diagram.  
5. Upload the provided code (`rfid_access_control.ino`) to ESP8266 NodeMCU.  
6. Edit the code to add your **authorized UIDs** in the `authorizedUIDs[]` array.  

---

## 📌 Applications
- 🔑 Residential & hostel entry systems  
- 🏫 Institutional labs & exam halls  
- 💼 Office server rooms or restricted zones  
- 🖥 Data center security logging  
- 🏠 Smart homes with IoT integration  

---

## 🚀 Future Scope
- ✅ Cloud-based logging & analytics (Firebase/ThingsBoard)  
- ✅ Mobile app for remote monitoring & access control  
- ✅ Biometric integration (fingerprint/face recognition)  
- ✅ Encrypted RFID tags to prevent cloning attacks  

---

## 📸 Prototype Images
<img width="1112" height="925" alt="image" src="https://github.com/user-attachments/assets/46a36039-da08-4d04-b95a-8c190246904d" />

---

## 👨‍💻 Author
**Wrijoya Sen**  


---

## 📜 License
This project is licensed under the **MIT License** – feel free to use, modify, and expand.

import serial
import time
import os

# === Settings ===
PORT = 'COM9' 
BAUD = 9600     
FILENAME = "rfid_log.txt"

# === Setup Serial ===
try:
    ser = serial.Serial(PORT, BAUD, timeout=1)
    print(f"✅ Connected to {PORT}")
except Exception as e:
    print(f"❌ Failed to connect: {e}")
    exit()

log_path = os.path.join(os.path.dirname(__file__), FILENAME)
print(f"📂 Logging to: {log_path}\n")

# === Log Loop ===
try:
    with open(log_path, "a", encoding='utf-8') as logfile:
        print("🟢 Waiting for RFID scans...\n")
        while True:
            raw = ser.readline()

            try:
                uid = raw.decode('utf-8').strip()
            except UnicodeDecodeError:
                print("⚠️ Skipped unreadable line.")
                continue

            if uid:
                timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
                entry = f"{timestamp} | UID: {uid}"
                print(entry)

                logfile.write(entry + '\n')
                logfile.flush()
                os.fsync(logfile.fileno())

except KeyboardInterrupt:
    print("\n👋 Logging stopped.")
except Exception as e:
    print(f"❌ Error: {e}")

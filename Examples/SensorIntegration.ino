#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <BMx280I2C.h>
#include <BH1750.h>

// --- Configuration ---
#define SERIAL_BAUD 115200
#define LOOP_DELAY_MS 500

// --- Sensor Objects ---
// BNO055
// ID = -1, Address = 0x29 (default for Adafruit, check 0x28 if needed)
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x29, &Wire);

// BMX280
// Address = 0x76 (common) or 0x77
#define BMX280_ADDRESS 0x76
BMx280I2C bmx280(BMX280_ADDRESS);

// BH1750
// Address = 0x23 (default) or 0x5C
BH1750 lightMeter;

void setup() {
  Serial.begin(SERIAL_BAUD);
  while (!Serial) delay(10); // Wait for serial console

  Serial.println("Starting Sensor Integration...");
  
  // Initialize I2C once
  Wire.begin(); 

  // --- Initialize BNO055 ---
  if (!bno.begin()) {
    Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
  } else {
    Serial.println("BNO055 detected!");
    bno.setExtCrystalUse(true);
  }

  // --- Initialize BMX280 ---
  if (!bmx280.begin()) {
    Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
  } else {
    Serial.println("BMx280 detected!");
    bmx280.resetToDefaults();
    bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
    bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);
    if (bmx280.isBME280()) {
      bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);
    }
  }

  // --- Initialize BH1750 ---
  // BH1750 library calls Wire.begin() internally usually, but we called it above anyway.
  if (lightMeter.begin()) {
     Serial.println("BH1750 detected!");
  } else {
     Serial.println("Error initialising BH1750");
  }

  Serial.println("Setup Complete. Starting Loop...");
  Serial.println("--------------------------------");
}

void loop() {
  // Comment out functions to control output
  readBNO055();
  readBMX280();
  readBH1750();

  Serial.println("--------------------------------");
  delay(LOOP_DELAY_MS);
}

// --- Wrapper Functions ---

void readBNO055() {
  // Check if bno is initialized? The library doesn't strictly require check every time 
  // but if begin() failed it might return garbage or hang. 
  // For simplicity we assume it's there if wiring is correct.
  
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  Serial.print("[BNO055] ");
  Serial.print("X: "); Serial.print(euler.x());
  Serial.print(" Y: "); Serial.print(euler.y());
  Serial.print(" Z: "); Serial.print(euler.z());
  Serial.println();
}

void readBMX280() {
  // Start measurement
  if (!bmx280.measure()) {
    Serial.println("[BMX280] Measurement failed or busy");
    return;
  }

  // Wait for measurement
  do {
    delay(10); // Small delay checking status
  } while (!bmx280.hasValue());

  Serial.print("[BMX280] ");
  Serial.print("Pressure: "); Serial.print(bmx280.getPressure64());
  Serial.print(" Pa, Temp: "); Serial.print(bmx280.getTemperature());
  Serial.print(" C");

  if (bmx280.isBME280()) {
    Serial.print(", Humidity: "); Serial.print(bmx280.getHumidity());
    Serial.print(" %");
  }
  Serial.println();
}

void readBH1750() {
  float lux = lightMeter.readLightLevel();
  Serial.print("[BH1750] ");
  Serial.print("Light: "); Serial.print(lux);
  Serial.println(" lx");
}

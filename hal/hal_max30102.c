#include <Wire.h>
#include <MAX30102.h>

MAX30102 max30102;

void max30102_init() {
    Wire.begin(21, 22); // Initialize I2C (SDA, SCL)
    if (!max30102.begin()) {
        Serial.println("MAX30102 not detected!");
        while (1);
    }
    max30102.setup(); // Configure sensor settings
}

bool max30102_read(float *heartRate, float *spo2) {
    int irValue = max30102.getIR();  // Get infrared value
    if (irValue > 50000) {          // Detect a valid signal
        *heartRate = max30102.getHeartRate();
        *spo2 = max30102.getSpO2();
        return true;
    }
    return false; // No valid signal
}

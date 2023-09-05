#include "telaire_T9602.h"

// Constructor for the T9602 sensor class
T9602::T9602() : ADR(0), RH(0.0), Temp(0.0) {
}

// Begin communication with the T9602 sensor
void T9602::begin(uint8_t ADR_) {
    ADR = ADR_;
    Wire.begin();
}

// Measure relative humidity [%] and temperature [degrees Celsius]
void T9602::updateMeasurements() {
    uint8_t data[4] = {0}; // Array to store raw data from the sensor

    Wire.beginTransmission(ADR);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(ADR, 4);
    for (int i = 0; i < 4; i++) { // Read in raw data
        data[i] = Wire.read();
    }

    // Convert raw data to relative humidity [%]
    RH = static_cast<float>(((data[0] & 0x3F) << 8) + data[1]) / 16384.0 * 100.0;

    // Convert raw data to temperature [degrees Celsius]
    Temp = static_cast<float>((static_cast<unsigned>(data[2]) * 64 + (static_cast<unsigned>(data[3]) >> 2)) / 16384.0 * 165.0 - 40.0);
}

// Retrieve the stored relative humidity [%]
float T9602::getHumidity() {
    return RH;
}

// Retrieve the stored temperature [deg Celsius]
float T9602::getTemperature() {
    return Temp;
}

// Generate a comma-separated string with humidity and temperature data
String T9602::getString(bool takeNewReadings) {
    return String(RH) + "," + String(Temp) + ",";
}

// Return the header as a string
String T9602::getHeader() {
    return "Relative Humidity [%],Temp [C],";
}

// Example reading T9602 sensor data

#include "Arduino.h"
#include "String.h"
#include "Wire.h"

// Include our T9602 sensor library
#include "telaire_T9602.h"

// Declare some variables to store data
String header;
String data;

// Instantiate the T9602 sensor object
T9602 telairesensor;

void setup() {
    // Initialize serial communication with your computer at 38400 baud
    Serial.begin(38400);
    
    // Get the header information from the sensor (only once)
    header = telairesensor.getHeader();
    
    // Print the header to the serial monitor
    Serial.println(header);
}

void loop() {
    // Take a sensor reading every second and display it
    telairesensor.updateMeasurements();
    
    // Get the sensor data as a comma-separated string
    data = telairesensor.getString();
    
    // Print the sensor data to the serial monitor
    Serial.println(data);
    
    // Delay for one second before taking the next reading
    delay(1000);
}
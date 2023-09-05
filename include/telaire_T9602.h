#ifndef telaire_T9602
#define telaire_T9602

class T9602 {
public:
    /**
     * @brief Initializes an instance of the T9602 sensor class.
     */
    T9602();

    /**
     * @brief Begins communication with the T9602 sensor.
     * @param[in] ADR_: I2C address. Defaults to 0x28. This address is typically
     *                  unchanged, but this option exists for flexibility.
     */
    void begin(uint8_t ADR_ = 0x28);

    /**
     * @brief Measures relative humidity [%] and temperature [degrees Celsius].
     */
    void updateMeasurements();

    /**
     * @brief Retrieves the stored relative humidity [%].
     */
    float getHumidity();

    /**
     * @brief Retrieves the stored temperature [degrees Celsius].
     */
    float getTemperature();

    /**
     * @brief Returns data as a comma-separated string: "RH,T,".
     * @details This string format is: "RELATIVE_HUMIDITY,TEMPERATURE,".
     * @param[in] takeNewReadings: If `true`, runs `updateMeasurements` before returning values.
     * Otherwise, returns the stored values.
     */
    String getString(bool takeNewReadings = false);

    /**
     * @brief Returns the header as an Arduino string: "Relative Humidity [%],Temp Atmos [C],"
     */
    String getHeader();

private:
    uint8_t ADR = 0x28; // Default I2C sensor address
    float RH = -9999;
    float Temp = -9999;
};

#endif

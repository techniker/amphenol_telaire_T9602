# Arduino compatible library for communicating with the Amphenol Telaire T9602 i2c temperature and humidity sensor

[Amphenol Telaire T9602](https://www.amphenol-sensors.com/en/telaire/humidity/527-humidity-sensors/3224-t9602)

[T9602 Datasheet](https://www.farnell.com/datasheets/1872050.pdf)

##  Sensor specifications

  * IP67 rated sensor with two membranes
  * -20 to 70 °C temperature range
  * Accuracy: ±2% RH, 0-95% RH ±0.5°C
  * 14 bit ADC resolution

## Sensor cable pinout

| **Color** |   **Signal**   |
|-----------|----------------|
| Red       | V+             |
| Green     | GND            |
| White     | SDA            |
| Black     | SCL            |

![T9602 pinout](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS4IXIdSB64S-NKB0MQdY745BLXDTEJgOI-VA&usqp=CAU)

[Internally used ChipCap2 sensor module reference guide](https://www.amphenol-sensors.com/hubfs/Documents/AAS-916-127J-Telaire-ChipCap2-022118-web.pdf?Itemid=8487+%27)
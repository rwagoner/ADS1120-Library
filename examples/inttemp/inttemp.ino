#include <ADS1120.h>

/**
* Internal Temp Example for using the Arduino Library for the Texas Instruments ADS11120
*/

// Definition of the pins to be used
#define CS      17
#define DRDY    16

// Creating an ADS1120 object
ADS1120 ads1120;

void setup(){
    Serial.begin(115200);

    // Initialize the ADS1120
    ads1120.begin(CS, DRDY);
    ads1120.setGain(1);               // 1 (default)
    ads1120.setDataRate(0x00);        // 20 SPS
    ads1120.setOpMode(0x00);          // Normal mode (default)
    ads1120.setConversionMode(0x01);  // Single shot (default)
    ads1120.setVoltageRef(0);         // Internal 2.048 V (default)   
    ads1120.setTemperatureMode(1);    // Enables temperature sensor
}

void loop(){
    Serial.printf("Int Temp: %0.2f C\n", ads1120.readADC_SingleTemp());
    delay(500);
}

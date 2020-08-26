#include <ADS1120.h>

/**
* Singled Ended Example for using the Arduino Library for the Texas Instruments ADS11120
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
    ads1120.setTemperatureMode(0);    // Disables temperature sensor (default)
}

void loop(){
    int16_t adc0, adc1, adc2, adc3;
    
    ads1120.setMultiplexer(0x08); // AIN0 and AVSS
    adc0 = ads1120.readADC_Single();
    
    ads1120.setMultiplexer(0x09); // AIN1 and AVSS
    adc1 = ads1120.readADC_Single();
    
    ads1120.setMultiplexer(0x0A); // AIN2 and AVSS
    adc2 = ads1120.readADC_Single();
    
    ads1120.setMultiplexer(0x0B); // AIN3 and AVSS
    adc3 = ads1120.readADC_Single();
    
    Serial.printf("A0 Value:   %i\n", adc0);
    Serial.printf("A1 Value:   %i\n", adc1);
    Serial.printf("A2 Value:   %i\n", adc2);
    Serial.printf("A3 Value:   %i\n", adc3);

    delay(500);
}

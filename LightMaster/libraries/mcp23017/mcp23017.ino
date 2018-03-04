#include <Wire.h>

void setup() { Wire.begin(); //creates a Wire object

// set I/O pins to outputs
Wire.beginTransmission(0x20); //begins talking to the slave device
Wire.write(0x00); //selects the IODIRA register
Wire.write(0x00); //this sets all port A pins to outputs
Wire.endTransmission(); //stops talking to device
Wire.beginTransmission(0x20);//begins talking again to slave device
Wire.write(0x01); //selects the IODIRB register
Wire.write(0x00); // sets all port B pins to outputs
Wire.endTransmission(); //ends communication with slave device
}

void loop()
{
Wire.beginTransmission(0x20); //starts talking to slave device
Wire.write(0x12); //selects the GPIOA pins
Wire.write(00000011); // turns on pins 0 and 1 of GPIOA
Wire.endTransmission(); //ends communication with the device
Wire.beginTransmission(0x20); //starts talking to slave device
Wire.write(0x13); //selects the GPIOB pins
Wire.write(00000001); //turns on pin 0 of GPIOA
Wire.endTransmission();//ends communication with the device
}

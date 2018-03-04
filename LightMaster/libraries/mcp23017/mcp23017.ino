#include <Wire.h>
bool state = true;;
void DigitalWrite(unsigned char address, unsigned char val)
{

Wire.beginTransmission(0x20); //begins talking to the slave device
Wire.write(address); //selects the IODIRA register
Wire.write(val); //this sets all port A pins to outputs
Wire.endTransmission(); //stops talking to device
}


void setup() {
  Wire.begin(); //creates a Wire object
Serial.begin(9600); 
 DigitalWrite(0x00,0x00); //selects the IODIRA register and sets all port A pins to outputs


DigitalWrite(0x01,0x00);//selects the IODIRB register and sets all port B pins to outputs

}

void loop()
{
    if(state)
    {
        DigitalWrite(0x12,11111111 );//selects the GPIOA pins and turns on pins 0 and 1 of GPIOA
     // DigitalWrite(0x13,00100001 );//selects the GPIOB pins and //turns on pin 0 of GPIOB
     Serial.println("HIGH"); 
    }
    else
    {
      Serial.println("LOW"); 
      DigitalWrite(0x12,0 );//selects the GPIOA pins and turns on pins 0 and 1 of GPIOA
     // DigitalWrite(0x13,0 );//selects the GPIOB pins and //turns on pin 0 of GPIOB
    
    }
state = ! state;
delay(1000);
}

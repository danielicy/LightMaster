/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/
#define PINCNT 6

//int ledarray[]={2,3,4,5,6,7,8,9,10,11,12};
int ledarray[]={2,3,4,5,6,7};
int led = 15;     //5(5), 6(6),     // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void FadeIn(int pin)
{
  
}

void FadeOut(int pin)
{

  
}

void Fade(int led)
{

// set the brightness of pin 9:
  analogWrite(led, brightness);
Serial.print("fading");
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);

  for(int t=0;t<PINCNT;t++)
  {
    pinMode(ledarray[t], OUTPUT);
  }
   
}


void SingleFader()
{
  for(int led = 0;led<PINCNT;led++)
  {
    for(int i=0;i<51;i++)
    {
      Fade(ledarray[led]);
            delay(100);
    }
    analogWrite(ledarray[led], 0);  
    
  } 
}

void MultipleFader()
{
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  SingleFader();
  
}
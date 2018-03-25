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

#define PINCNT 11

#define RED1 2
#define RED2 3
#define GREEN1 4
#define GREEN2 5
#define WHITE1 6
#define WHITE 7





int ledarray[]={2,3,4,5,6,7,8,9,10,11,12};
//int ledarray[]={2,3,4,5,6,7};



//int ledarray[]={RED1,RED2,GREEN1.GREEN2,WHITE1,WHITE2};
int led = 15;     //5(5), 6(6),     // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void FadeIn(int pin)
{
  for(int brightness = 0;brightness <= 255;brightness++)
	{
		analogWrite(pin, brightness);
		delay(30);
	}
}

void FadeOut(int pin)
{
   for(int brightness = 255;brightness >= 0;brightness--)
	 {
		analogWrite(pin, brightness);
		 delay(30);
	 }
}


void Fade(int led)
{
   Serial.println("Fading");
    Serial.print(led);
		FadeIn(led);
		delay(1000);
		FadeOut(led);
}

// the setup routine runs once when you press reset:
void setup() {
  
   Serial.begin(9600);
   
  for(int t=0;t<PINCNT;t++)
  {
    pinMode(ledarray[t], OUTPUT);
  }
   
}


void SingleFader()
{
  for(int led = 0;led<PINCNT;led++)
  {
    Fade(ledarray[led]);        
    
  } 
}

void DoubleFader()
{
  for(int led = 0; led<PINCNT; led++)
  {Serial.println("IntermittentFader");
    Serial.print(led);
		FadeIn(ledarray[led]);
		FadeIn(ledarray[PINCNT-1-led]);
    FadeOut(ledarray[led]);
    FadeOut(ledarray[PINCNT-1-led]);
	}

}

void MultiFader()
{
  for(int led = 0; led<PINCNT; led++)
  {
    Serial.println("MultiFader");
    Serial.print(led);
    FadeIn(ledarray[led]);
    FadeIn(ledarray[PINCNT-1-led]);
     FadeIn(ledarray[led + 1]);
      FadeIn(ledarray[led + 2]);
    FadeOut(ledarray[led]);
    FadeOut(ledarray[PINCNT-1-led]);
     FadeOut(ledarray[led-1]);
    FadeOut(ledarray[led-2]);
  }

}

void Rattle()
{
  for(int t=0;t<PINCNT;t++)
  {
     analogWrite(ledarray[t], 255);
     delay(30);
  }

  for(int t=0;t<PINCNT;t++)
  {
     analogWrite(ledarray[t], 0);
      delay(30);
  }
  
}

void Dawn()
{
		//FadeIn()
}

void Evening()
{

}

// the loop routine runs over and over again forever:
void loop() {
  
	 	for(int i=0;i<2;i++)
     {
      SingleFader();
     }

		 for(int i=0;i<2;i++)
     {
       DoubleFader();
     }
 
    Rattle();
     Rattle();
      Rattle();
     Rattle();

     for(int i=0;i<2;i++)
     {
       MultiFader();
     }

		Dawn();

		Evening();
}

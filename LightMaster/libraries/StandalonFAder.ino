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

#define RED1 2
#define RED2 3
#define GREEN1 4
#define GREEN2 5
#define YWHITE1 6
#define YWHITE2 7
#define BWHITE1 8
#define BWHITE2 9
#define BLUE 10
#define PURPLE 11
#define YELLOW 12






//int ledarray[]={2,3,4,5,6,7,8,9,10,11,12};
//int ledarray[]={2,3,4,5,6,7};



int ledarray[]={RED1,RED2,GREEN1.GREEN2,YWHITE1,YWHITE2,BWHITE1,BWHITE2,BLUE,PURPLE,YELLOW};
int led = 15;     //5(5), 6(6),     // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void FadeIn(int pin)
{
  for(int brightness=0;brightness<255;brightness++)
	{
		analogWrite(pin, brightness);
		delay(30);
	}
}

void FadeOut(int pin)
{
   for(int brightness=255;brightness>0;brightness--)
	 {
		analogWrite(pin, brightness);
		 delay(30);
	 }
}


void Fade(int led)
{
		FadeIn(led);
		delay(1000);
		FadeOut(led);
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
    //for(int i=0;i<51;i++)
   // {
      Fade(ledarray[led]);
           // delay(100);
   // }     
    
  } 
}

void IntermittentFader()
{
  for(int led = 0;led<PINCNT;led++)
  {
		Fade(ledarray[led]);
		Fade(ledarray[PINCNT-1-led]);
	}

}

void Dawn()
{
		FadeIn()
}

void Evening()
{

}

void Rattle()
{

}

// the loop routine runs over and over again forever:
void loop() {
  
		 for(int i=0;i<10;i++)
     {
      SingleFader();
     }

		 for(int i=0;i<10;i++)
     {
       IntermittentFader();
     }
	   Rattle():

		Dawn();
		
		Forest();

		Evening();
}
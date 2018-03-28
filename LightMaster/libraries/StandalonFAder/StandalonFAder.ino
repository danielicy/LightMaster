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

#define RED 2
#define RED1 3
#define GREEN 4
#define GREEN1 5
#define YWHITE 6
#define YWHITE1 7
#define BWHITE 8
#define BWHITE1 9  
#define BLUE 10
#define PURPLE 11
#define YELLOW 12




int ledarray[]={RED,RED1,GREEN,GREEN1,YWHITE,YWHITE1,BWHITE,BWHITE1,BLUE,PURPLE,YELLOW};
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

void Dawn()
{
	
}

void Evening()
{
		FadeIn(RED);
		FadeIn(RED1);
		FadeIn(BWHITE);
		FadeIn(BWHITE1);
		FadeIn(PURPLE);
		FadeIn(BLUE);
		delay(300000);
		FadeOut(RED);
		FadeOut(RED1);
		FadeOut(BWHITE);
		FadeOut(BWHITE1);
		FadeOut(PURPLE);
		FadeOut(BLUE);
}

void Forest()
{

		FadeIn(GREEN);
		FadeIn(GREEN1);
		FadeIn(BWHITE);
		FadeIn(BWHITE1);
		FadeIn(YWHITE);
		FadeIn(YWHITE1);
		delay(300000);
		FadeOut(GREEN);
		FadeOut(GREEN1);
		FadeOut(BWHITE);
		FadeOut(BWHITE1);
		FadeOut(YWHITE);
		FadeOut(YWHITE1);
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

// the loop routine runs over and over again forever:
void loop() {
  
		 for(int i=0;i<10;i++)
     {
      SingleFader();
     }

		 for(int i=0;i<2;i++)
     {
       DoubleFader();
     }
	 
	 
	  for(int r = 0;r<20;r++)
	  {
		 Rattle();
	  }	

    for(int i=0;i<2;i++)
    {
       MultiFader();
    }	 
	   

		Dawn();
		
		Forest();

		Evening();
}

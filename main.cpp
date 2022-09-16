#include<Arduino.h>
#define RedLed 4
#define GreenLed 2
#define BlueLed 13

#define PWM_FREQUENCY 5000
#define PWM_CHANNEL 0
#define PWM_RESOLUTION 8

uint8_t ui8DutyCycle;


void setup() 
{
  ledcSetup(PWM_CHANNEL,PWM_FREQUENCY,PWM_RESOLUTION);
}
void loop()
 { 
  //red led fading
  ledcAttachPin(RedLed,PWM_CHANNEL);
 for(ui8DutyCycle=0;ui8DutyCycle<100;ui8DutyCycle+=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
  delay(1000);
 }
 for(ui8DutyCycle=100;ui8DutyCycle>0;ui8DutyCycle-=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
  delay(1000);
 } 
 ledcDetachPin(RedLed);
 //Green led fading
 ledcAttachPin(GreenLed,PWM_CHANNEL);
 for(ui8DutyCycle=0;ui8DutyCycle<100;ui8DutyCycle+=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
  delay(1000);
 }
 for(ui8DutyCycle=100;ui8DutyCycle>0;ui8DutyCycle-=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
  delay(1000);
 }
 ledcDetachPin(GreenLed);
 //blue led fading
  ledcAttachPin(BlueLed,PWM_CHANNEL);

 for(ui8DutyCycle=0;ui8DutyCycle<100;ui8DutyCycle+=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
  delay(1000);
 }
 for(ui8DutyCycle=255;ui8DutyCycle>0;ui8DutyCycle-=25)
 {
  ledcWrite(PWM_CHANNEL,ui8DutyCycle);
    delay(1000);
 }      
 ledcDetachPin(BlueLed);
 
}
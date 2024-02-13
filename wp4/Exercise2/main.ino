#include <Servo.h>
#define limit 61//limit got it from https://www.arduinoslovakia.eu/application/timer-calculator

int pos = 0;
int timer=0;
int increment_value=10;
Servo servo;
void setup()
{ //https://www.arduinoslovakia.eu/application/timer-calculator
  Serial.begin(9600);
  //servo attached to pin 2
  servo.attach(2);
  //to control timer we have 2 main registers TCCR1A and B
   TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  // 61.03515625 Hz (16000000/((255+1)*1024))
  OCR2A = 255;
  // CTC
  TCCR2A |= (1 << WGM21);
  // Prescaler 1024
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
  // Output Compare Match A Interrupt Enable
  TIMSK2 |= (1 << OCIE2A);
  sei(); //enable global interrupts
   
}
 
void loop()                    
{
}

ISR(TIMER2_COMPA_vect) {

  TCNT2=0;
  timer++;
  if(timer ==limit){
    timer=0;
    move_servo();
  }
  
  
}

void move_servo(){
  Serial.println(pos);
  pos +=increment_value;
  if(pos==180){
  increment_value=-10;
  }
  else if(pos ==0){
  increment_value=10;
  }
  servo.write(pos);
  }
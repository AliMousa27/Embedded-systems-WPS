#include <Adafruit_NeoPixel.h>
#define red_led 3
#define PIN 2	 // input pin Neopixel is attached to
#define temp A0
#define NUMPIXELS      24 // number of neopixels in strip

#define interval 10 //every 10c i in
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

float last_temp=0;
int i =0;
void setup()
{
  Serial.begin(9600);
  pinMode(temp,INPUT);
  pinMode(red_led,OUTPUT);
  last_temp=read_temp();
  ring.begin();
  //to control timer we have 2 main registers TCCR1A and B
  TCCR1A = 0;//set TCCR1A to 0 to disable pwm on pin 9 and 10
  TCCR1B = 0;// set TCCR1B to 0
  //first 3 bits define the prescalar value
  TCCR1B |= B00000100;//set cs12 to 1 to get prescalar 256
  TCNT1 = 0; // reset time 1 to be 0
  //set OCEIA1 to be in the TMSAK1 registyer
  TIMSK1 |= B00000010;//enable compare matcha node to set timer interrupts
  OCR1A = 62500;//formula to calcualte this to set the time for iterrupts is
  //clock freq/scalar * desierd delay
  
  sei(); //enable global interrupts
}

void loop()
{
}
ISR(TIMER1_COMPA_vect){

  TCNT1=0;//set timer back to 0 
  float temperature = read_temp();
  
  if(temperature > (last_temp+interval)){
    
    ring.setPixelColor(i, ring.Color(255, 0, 0));
    i = (i>=NUMPIXELS-1) ? NUMPIXELS-1 : i+1;
  } 
  else if(temperature <(last_temp - interval)){
    i = (i<=0) ? 0: i-1;
    ring.setPixelColor(i, ring.Color(0, 0, 0));
  }
  Serial.println(i);
  ring.show(); 
  last_temp=temperature; 
  
  if(i>=NUMPIXELS){
  	digitalWrite(red_led,HIGH);
  }
  else{
  digitalWrite(red_led,LOW);
  }

}

float read_temp() {
    int reading = analogRead(temp);
    // convert to the voltage. 5 is the voltage supplied by the arduion and
    //  1024 is the max digital value that can be read
    // https://arduino.stackexchange.com/questions/44639/how-to-calculate-voltage-from-a0-pin#:~:text=The%20formula%20to%20calculate%20voltage,sens%20*%20(%205.0%20%2F%201023.0)%3B
    float voltage = reading * (5.0 / 1023.0);
    // convert voltage to temp in C and return it
    // conversion factor is 1c/10mv which is 1/0.01v = 100 i think the formula provided is wrong
    return (voltage - 0.5) * 100; //-0.5 is offset value
}
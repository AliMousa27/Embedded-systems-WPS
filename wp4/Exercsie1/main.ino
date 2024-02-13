#define blue_led 2
#define yellow_led 3
#define orange_led 4
#define red_led 5
#define green_led 6

#define bound_one 0
#define bound_two 20
#define bound_three 40
#define bound_four 60
#define bound_five 80

//#define temp_sensor A0
int temp_sensor=A0;
void setup()
{
  Serial.begin(9600);
  pinMode(temp_sensor, INPUT);
  pinMode(blue_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
  pinMode(orange_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  
  //to control timer we have 2 main registers TCCR1A and B
  TCCR1A = 0;//set TCCR1A to 0 to disable pwm on pin 9 and 10
  TCCR1B = 0;// set TCCR1B to 0
  //first 3 bits define the prescalar value
  TCCR1B |= B00000100;//set cs12 to 1 to get prescalar 256
  TCNT1 = 0; // reset time 1 to be 0
  //set OCEIA1 to be in the TMSAK1 registyer
  TIMSK1 |= B00000010;//enable compare match node to set timer interrupts
  OCR1A = 31250;//formula to calcualte this to set the time for iterrupts is
  //clock freq/scalar * desierd delay
  
  sei(); //enable global interrupts
   
}
 
void loop()                    
{
}

ISR(TIMER1_COMPA_vect){

  TCNT1=0;//set timer back to 0 
  float temp = read_temp();

  
   if(temp > bound_one && temp < bound_two){
  switch_leds(HIGH,LOW,LOW,LOW,LOW);
  }
  else if(temp > bound_two && temp < bound_three){
  switch_leds(LOW,HIGH,LOW,LOW,LOW);
  }
  else if(temp > bound_three && temp < bound_four){
  switch_leds(LOW,LOW,HIGH,LOW,LOW);
  }
  else if(temp > bound_four && temp < bound_five){
  switch_leds(LOW,LOW,LOW,HIGH,LOW);
  }
  else if(temp > bound_five){
    switch_leds(LOW,LOW,LOW,LOW,HIGH);

  }
  
  else{
      switch_leds(LOW,LOW,LOW,LOW,LOW);

  }
  
}

void switch_leds(int blue, int yellow, int orange, int red, int green){
digitalWrite(blue_led, blue);
digitalWrite(yellow_led,yellow);
digitalWrite(orange_led,orange);
digitalWrite(red_led,red);
digitalWrite(green_led,green);

}

float read_temp() {
    int reading = analogRead(temp_sensor);
    // convert to the voltage. 5 is the voltage supplied by the arduion and
    //  1024 is the max digital value that can be read
    // https://arduino.stackexchange.com/questions/44639/how-to-calculate-voltage-from-a0-pin#:~:text=The%20formula%20to%20calculate%20voltage,sens%20*%20(%205.0%20%2F%201023.0)%3B
    float voltage = reading * (5.0 / 1023.0);
    // convert voltage to temp in C and return it
    // conversion factor is 1c/10mv which is 1/0.01v = 100 i think the formula provided is wrong
    return (voltage - 0.5) * 100; //-0.5 is offset value
}
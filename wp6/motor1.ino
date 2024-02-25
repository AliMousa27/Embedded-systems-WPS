// // (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// // Work package 6 
// // Exercise 1
// // Submission code: E9K8FPL (provided by your TA-s) 

// // C++ code

//Defining the pins
#define ENCODER_A 2
#define ENCODER_B 3
#define POWER_1 5
#define POWER_2 6

int a=0; // a-encoder signal
int b=0; // b-encoder signal

int pos = 0; // pistion counter in ticks
float degree = 0; // current degree on the dc motor
int degtarget = 0; // the desired degree entered by the user
int e = 0; //error
int kp = 15; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of the controller
int speed = 0;

void setup()
{  
  Serial.begin(9600);
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  
  /* 
  ATTACH INTERRUPT HERE. 
  */
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), ISR_encoder, RISING);

 
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(POWER_2, 10);
  delay(200);
  analogWrite(POWER_1, 10);
}

void loop()
{

 if(pos < -2299 || pos > 2299){
    pos = 0;
  }  
  Serial.print("\n");
  Serial.print("\nDegrees: ");
  
  //Check if the dc motor made a full rotation
  //degrees within 360 degrees instead of 400, 420 degrees etc
  if (degree > 359) {
    degree = degree - 360;
  }
  //print current position in degrees
  Serial.print(degree);
  Serial.print("\n");
  delay(200); 
  
 
  degtarget = getInput()+ degree ;
  Serial.print(degtarget);
  Serial.print("\n");
  
  
  // Calculate initial error
  e = degtarget - degree;
   
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    degree = map(pos,0,2299,0,360);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;
      analogWrite(POWER_2, 0);
      analogWrite(POWER_1, speed);
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; 
      	analogWrite(POWER_1, 0);
      	analogWrite(POWER_2, -speed); 
    }
	
    // Calculate new error
  	e = degtarget - degree;
  }
  if (e == 0) {
    //stop the motor from continously rotating
  	analogWrite(POWER_1, 10);
    delay(200);
    analogWrite(POWER_2, 10);	
  }
}


int getAction(int error){
  /* 
  Calculate u_out as function of the error and the kp (tuning parameter). 
  */
  u_out = kp*e;
  
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;
  }
  else if (u_out < -254){ //...or less than -254
    return -255;
  }  
  else
     return u_out;
}


int getInput() {
  Serial.println("Please enter the desired position: ");
  
  while (!Serial.available()) {
    // Wait for input
  }
  
  int input = Serial.parseInt();
  Serial.print("Input: ");
  Serial.println(input);

  // Clear the serial buffer
  while (Serial.available()) {
    Serial.read();
  }

  return input;
}

void ISR_encoder(){
  /*
  READ THE ENCODER SIGNAL HERE.
  Read the encoder signals and increase or decrease pos accordingly.
  */
  a = digitalRead(ENCODER_A);
  b = digitalRead(ENCODER_B);

  // if signal at encoder a is on increase the position counter
  if(a > b) {
    pos++;
  } else {
    //if signal at encoder b is on, decrease the position counter
    pos--;
  }
}
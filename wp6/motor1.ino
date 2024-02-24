#define motorA 5
#define motorB 6

int speed = 50;
int direction = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Type speed,direction at any time");
  Serial.print("speed = 0-255 direction = 1 or -1");
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
}

void loop() {
  // Check if there is serial input
  if (Serial.available() > 0) {
    // parse int reads until a comma
    speed = Serial.parseInt();

    // clear comma from buffer memory
    Serial.read();

    // Read direction
    direction = Serial.parseInt();

    // Ensure the speed is within the valid range (0-255)
    speed = constrain(speed, 0, 255);
    direction = constrain(direction, -1, 1);
    // Print the updated values to Serial Monitor
    Serial.print("Updated motor speed: ");
    Serial.println(speed);
    Serial.print("Updated direction: ");
    Serial.println(direction);
  }
  if(direction==1){
    // Motor control
  analogWrite(motorA, speed);
  digitalWrite(motorB, LOW);}
  else{
    analogWrite(motorB, speed);
  digitalWrite(motorA, LOW);}
  


  delay(100);
}

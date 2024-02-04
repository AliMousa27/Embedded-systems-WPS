// code meant for TinkerCad to test the LED and button
// define the first LED pin to be pin 8
int LED1_PIN = 8;
// define the button LED pin to be pin 4
int BUTTON_LED_PIN = 4;
// button connects to led 2
int BUTTON_PIN = 2;
// variable to store the state of the button
int isClicked = 0;
// setup the pins to the appropriate mode
void setup() {
    // set the LED pin to be an output
    pinMode(LED1_PIN, OUTPUT);
    // set the button LED pin to be an output
    pinMode(BUTTON_LED_PIN, OUTPUT);
    // set the button pin to be an input
    pinMode(BUTTON_PIN, INPUT);
}
// loop function
void loop() {
    // read the state of the button
    isClicked = digitalRead(BUTTON_PIN);
    // if clicked
    if (isClicked == HIGH) {
        // turn on the button LED
        digitalWrite(BUTTON_LED_PIN, HIGH);
        // otherwise it isnt clicked
    } else {
        // turn off the button LED
        digitalWrite(BUTTON_LED_PIN, LOW);
    }
    // turn on the LED
    digitalWrite(8, HIGH);
    // Wait for 1000 millisecond(s)
    delay(1000);
    // turn off the LED
    digitalWrite(8, LOW);
    // Wait for 1000 millisecond(s)
    delay(1000);
}
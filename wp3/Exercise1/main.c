// program is meant to be executed in tinkercad
//  defining the pins for the button and the LEDs
int button_led = 2;
// the LED that will blink every 2 seconds
int periodic_led = 8;
// the button pin
int button = 4;
// the variable that will hold the state of the button
int is_clicked = 0;
// the variable that will hold the previous time the LED blinked
int prev_millis = 0;
// the delay in milliseconds
int delay_in_ms = 2000;
// setup func
void setup() {
    // set the button LED as an output
    pinMode(button_led, OUTPUT);
    // set the periodic LED as an output
    pinMode(periodic_led, OUTPUT);
    // set the button as an input
    pinMode(button, INPUT);
}
// loop func
void loop() {
    // get the current milliseconds that have passed since the program started, i use millis instead of delay to not block the program
    int curr_millis = millis();
    // if the time that has passed since the last blink is greater than the delay
    if (curr_millis - prev_millis >= delay_in_ms) {
        // switch the led to its opposite state
        digitalWrite(periodic_led, !digitalRead(periodic_led));
        // set the previous time to the current time so that the calculation can be done again
        prev_millis = curr_millis;
    }
    // read the state of the button
    is_clicked = digitalRead(button);
    // if clicked
    if (is_clicked == HIGH) {
        // turn on the button LED
        digitalWrite(button_led, HIGH);
        // otherwise it isnt clicked
    } else {
        // turn off the button LED
        digitalWrite(button_led, LOW);
    }
}

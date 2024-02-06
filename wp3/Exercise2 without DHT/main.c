int temp_sensor = A0;

void setup() {
    Serial.begin(9600);
    pinMode(temp_sensor, INPUT);
}

void loop() {
    float temp = read_temp();
    Serial.println(temp);
    delay(600);
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
//global variables to be used
int temp_sensor = A0;
int light_sensor = A1;
int red_led = 7;
int green_led = 4;
int yellow_led = 8;
//function prototype
//define arrays where each entry is the max bound
int temp_array[] = { -12, 0, 20, 214744 };
int light_array[] = { 0, 20, 60, 100 };

void setup() {
    // sets communcation with serial monitor
    Serial.begin(9600);
    pinMode(red_led, OUTPUT);
    pinMode(green_led, OUTPUT);
    pinMode(yellow_led, OUTPUT);
}

void loop() {
    // get current reading,
    // calculations are from https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
    float temperatureC = read_temp();
    //read light intensity as percent
    float light_percent = measureLuminosity();
    //find the indicies of both to be compared
    int temp_index = find_temp_index(temp_array, temperatureC);
    int light_index = find_temp_index(light_array, light_percent);
    //print temp and intensity
    Serial.print("Temp: ");
    Serial.print(temperatureC);
    Serial.print(" | Light: ");
    Serial.print(light_percent);
    Serial.print(" | Temp Index: ");
    Serial.print(temp_index);
    Serial.print(" | Light Index: ");
    Serial.println(light_index);
    //if indices are euqal then its fine
    if (temp_index == light_index) {
        //light the green one and turn everything else off
        digitalWrite(green_led, HIGH);
        digitalWrite(yellow_led, LOW);
        digitalWrite(red_led, LOW);
        //if temp is higher then light the red and turn everything else off
    } else if (temp_index > light_index) {
        digitalWrite(green_led, LOW);
        digitalWrite(yellow_led, LOW);
        digitalWrite(red_led, HIGH);
        //if temp is lower then light yellow
    } else if (temp_index < light_index) {
        digitalWrite(green_led, LOW);
        digitalWrite(yellow_led, HIGH);
        digitalWrite(red_led, LOW);
    }
    delay(3000);
}

float read_temp() {
    int reading = analogRead(temp_sensor);
    // convert to the voltage. 5 is the voltage supplied by the arduion and
    //  1024 is the max digital value that can be read
    float voltage = reading * 5;
    voltage /= 1024.0;

    // convert voltage to temp in C and return it
    return (voltage - 0.5) * 100;
}

float measureLuminosity() {
    //read light
    int value_ldr = analogRead(light_sensor);
    //convert it to percent from 0 to 100
    float converted_ldr_val = map(value_ldr, 0, 1023, 0, 100);
    //return it
    return converted_ldr_val;
}
// function that take spoitner to first element array adn the current temp
int find_temp_index(int* array, float temp) {
    //define index to be returned
    int index = 0;
    //Serial.print("Temp is: ");
    //Serial.println(temp);

    //loop. I starts at 1 because i compare each entry to the one before it to find the bounds
    for (int i = 1; i < 4; i++) {
        // lower and upper bounds
        float lower_bound = array[i - 1];
        float upper_bound = array[i];
        //if temp falls in between them
        if (temp > lower_bound && temp < upper_bound) {
            //set index to i
            index = i;
            //return it
            break;
        }
    }

    return index;
}

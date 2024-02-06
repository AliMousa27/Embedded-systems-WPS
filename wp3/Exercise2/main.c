int temp_sensor = A0;
int light_sensor = A1;
int red_led = 7;
int green_led = 4;
int yellow_led = 8;
float read_temp();
int temp_array[] = { -12, 0, 20, 214744 };
int light_array[] = { 0, 20, 60, 100 };

void setup() {
    // sets communcation with serial monitor
    Serial.begin(9600);
    pinMode(1, OUTPUT);
}

void loop() {
    // get current reading,
    // calculations are from https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
    float temperatureC = read_temp();

    float light_percent = measureLuminosity();

    int temp_index = find_temp_index(temp_array, temperatureC);
    int light_index = find_temp_index(light_array, light_percent);
    Serial.print("Temp: ");
    Serial.print(temperatureC);
    Serial.print(" | Light: ");
    Serial.print(light_percent);
    Serial.print(" | Temp Index: ");
    Serial.print(temp_index);
    Serial.print(" | Light Index: ");
    Serial.println(light_index);
    if (temp_index == light_index) {
        digitalWrite(green_led, HIGH);
        digitalWrite(yellow_led, LOW);
        digitalWrite(red_led, LOW);
    } else if (temp_index > light_index) {
        digitalWrite(green_led, LOW);
        digitalWrite(yellow_led, LOW);
        digitalWrite(red_led, HIGH);
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
    int value_ldr = analogRead(light_sensor);
    float converted_ldr_val = map(value_ldr, 0, 1023, 0, 100);

    return converted_ldr_val;
}
int find_temp_index(int* array, float temp) {
    int index = 0;
    Serial.print("Temp is: ");
    Serial.println(temp);

    for (int i = 1; i < 4; i++) {
        float lower_bound = array[i - 1];
        float upper_bound = array[i];

        if (temp > lower_bound && temp < upper_bound) {
            index = i;
            break;
        }
    }

    return index;
}

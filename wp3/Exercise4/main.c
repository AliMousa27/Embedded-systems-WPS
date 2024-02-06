#include <Keypad.h>
byte pinRows[4] = { 11, 10, 9, 8 };
byte pinCols[4] = { 7, 6, 5, 4 };
const int rows = 4;
const int cols = 4;

char keys[4][4] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};
// https://arduinogetstarted.com/tutorials/arduino-keypad
Keypad keypad = Keypad(makeKeymap(keys), pinRows, pinCols, rows, cols);

void setup() {
    Serial.begin(9600);
}

void loop() {

    char key = keypad.getKey();
    if (key) {
        Serial.print("Key pressed: ");
        Serial.println(key);
    }

    delay(1000);
}

// #include <stdlib>

const int pinRows[4] = { 11, 10, 9, 8 };
const int pinCols[4] = { 7, 6, 5, 4 };

char key;

char keys[4][4] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < 4; i++) {
        pinMode(pinCols[i], OUTPUT);
        // basically makes all of the rows to high by default
        pinMode(pinRows[i], INPUT_PULLUP);
    }
}

void loop() {
    readKey();
    if (key != '\0') {
        Serial.print("Key pressed: ");
        Serial.println(key);
        key = '\0';
    }
    delay(100);
}

void readKey() {
    for (int i = 0; i < 4; i++) {
        // set current row to low. Only when a key is pressed will the correct row be low
        // otherwise it will always read high
        digitalWrite(pinCols[i], LOW);
        for (int j = 0; j < 4; j++) {
            if (digitalRead(pinRows[j]) == LOW) {
                delay(20);
                key = keys[j][i];
            }
        }
        digitalWrite(pinCols[i], HIGH);
    }
}
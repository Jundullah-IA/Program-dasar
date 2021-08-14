void setup() {
    Serial.begin(9600);

    pinMode(A3, INPUT);
    pinMode(A0, OUTPUT); pinMode(A1, OUTPUT); pinMode(A2, OUTPUT);
}

bool readPin(byte potition) {
    digitalWrite(A0, bitRead(potition, 2));
    digitalWrite(A1, bitRead(potition, 1));
    digitalWrite(A2, bitRead(potition, 0));
    return analogRead(A3) > 750 ? 1 : 0;
}

byte data() { byte data;
    bitWrite(data, 1, readPin(0));
    bitWrite(data, 2, readPin(1));
    bitWrite(data, 3, readPin(2));
    bitWrite(data, 0, readPin(3));
    bitWrite(data, 4, readPin(4));
    bitWrite(data, 7, readPin(5));
    bitWrite(data, 5, readPin(6));
    return bitWrite(data, 6, readPin(7));
}

void loop() {
    int start = millis();
    Serial.print(data(), BIN); Serial.print("   ");
    Serial.println(millis() - start);
}

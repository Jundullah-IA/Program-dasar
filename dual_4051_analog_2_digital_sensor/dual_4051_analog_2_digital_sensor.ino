void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT); pinMode(A4, INPUT);
  pinMode(A1, OUTPUT); pinMode(A2, OUTPUT); pinMode(A3, OUTPUT);
}

bool readPin(byte pin, byte potition) {
  digitalWrite(A1, bitRead(potition, 2));
  digitalWrite(A2, bitRead(potition, 1));
  digitalWrite(A3, bitRead(potition, 0));
  return analogRead(pin) > 750 ? 1 : 0;
}

unsigned int data() { unsigned int data;
/*0*/ bitWrite(data, 9, readPin(A4, 0));
  bitWrite(data, 1, readPin(A0, 0));
/*1*/ bitWrite(data, 10, readPin(A4, 1));
  bitWrite(data, 2, readPin(A0, 1));
/*2*/ bitWrite(data, 11, readPin(A4, 2));
  bitWrite(data, 3, readPin(A0, 2));
/*3*/ bitWrite(data, 8, readPin(A4, 3));
  bitWrite(data, 0, readPin(A0, 3));
/*4*/ bitWrite(data, 12, readPin(A4, 4));
  bitWrite(data, 4, readPin(A0, 4));
/*5*/ bitWrite(data, 15, readPin(A4, 5));
  bitWrite(data, 7, readPin(A0, 5));
/*6*/ bitWrite(data, 13, readPin(A4, 6));
  bitWrite(data, 5, readPin(A0, 6));
/*7*/ bitWrite(data, 14, readPin(A4, 7));
  return bitWrite(data, 6, readPin(A0, 7));
}

void loop() {
  int start = millis();
  Serial.print(data(), BIN); Serial.print("   ");
  Serial.println(millis() - start);
}

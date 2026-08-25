
int LED = 3;
int POT = A1;
int valorPot = 0;
int BRILLO = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorPot = analogRead(POT);
  Serial.println(valorPot);
  BRILLO = map(valorPot, 0, 1023, 0, 255);
  analogWrite(LED, BRILLO);
}

// Pins are setup for Arduino Nano
const int relayPin = 10;
const int inputPin = 12;
const int delayms = 3000;

void setup()
{
    Serial.begin(9600);
    Serial.write("Starting...\n");
    pinMode(relayPin, OUTPUT);
    pinMode(inputPin, INPUT);
    digitalWrite(relayPin, HIGH);
    Serial.write("Setup ended\n");
}

void loop()
{
    if (digitalRead(inputPin) == HIGH)
    {
        Serial.write("Starting loop\n");
        digitalWrite(relayPin, LOW);
        delay(delayms);
        digitalWrite(relayPin, HIGH);
        Serial.write("Loop ended\n\n");
    }
}

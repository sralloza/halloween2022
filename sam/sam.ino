// Pins are setup for Arduino Nano
const int relayPin = 10;
const int inputPin = 12;
const int delayms = 60000;

const bool RELAY_ACTIVATION_HIGH = true;

void setRelayON(int relayPin)
{
    if (RELAY_ACTIVATION_HIGH == true)
    {
        digitalWrite(relayPin, HIGH);
    }
    else
    {
        digitalWrite(relayPin, LOW);
    }
}

void setRelayOFF(int relayPin)
{
    if (RELAY_ACTIVATION_HIGH == true)
    {
        digitalWrite(relayPin, LOW);
    }
    else
    {
        digitalWrite(relayPin, HIGH);
    }
}


void setup()
{
    Serial.begin(9600);
    Serial.write("Starting...\n");
    pinMode(relayPin, OUTPUT);
    pinMode(inputPin, INPUT_PULLUP);
    setRelayOFF(relayPin);
    Serial.write("Setup ended\n");
}

void loop()
{
    Serial.write(digitalRead(inputPin));
    if (digitalRead(inputPin) == HIGH)
    {
        Serial.write("Starting loop\n");
        setRelayON(relayPin);
        delay(delayms);
        setRelayOFF(relayPin);
        Serial.write("Stopping relay\n");
        delay(delayms);
        Serial.write("Loop ended\n\n");
    }
}

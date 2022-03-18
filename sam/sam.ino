// Pins are setup for Arduino Nano
const int RELAY_PIN = 10;
const int INPUT_PIN = 12;
const int DELAY_MS = 60000;

const bool RELAY_ACTIVATION_HIGH = true;

void setRelayON(int RELAY_PIN)
{
    if (RELAY_ACTIVATION_HIGH == true)
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
    }
}

void setRelayOFF(int RELAY_PIN)
{
    if (RELAY_ACTIVATION_HIGH == true)
    {
        digitalWrite(RELAY_PIN, LOW);
    }
    else
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
}


void setup()
{
    Serial.begin(9600);
    Serial.write("Starting...\n");
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(INPUT_PIN, INPUT_PULLUP);
    setRelayOFF(RELAY_PIN);
    Serial.write("Setup ended\n");
}

void loop()
{
    Serial.write(digitalRead(INPUT_PIN));
    if (digitalRead(INPUT_PIN) == HIGH)
    {
        Serial.write("Starting loop\n");
        setRelayON(RELAY_PIN);
        delay(DELAY_MS);
        setRelayOFF(RELAY_PIN);
        Serial.write("Stopping relay\n");
        delay(DELAY_MS);
        Serial.write("Loop ended\n\n");
    }
}

const int RELAY_1_PIN = 8;
const int RELAY_2_PIN = 10;
const int INPUT_PIN = 12;

const int DELAY_PISTON_UP_MS = 3000;
const int DELAY_PISTON_DOWN_MS = 3000;
const int DELAY_PISTON_KEEP_UP_MS = 5000;

const bool RELAY_ACTIVATION_HIGH = false;

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
    Serial.println("Starting...");

    pinMode(RELAY_1_PIN, OUTPUT);
    pinMode(RELAY_2_PIN, OUTPUT);
    pinMode(INPUT_PIN, INPUT);

    setRelayOFF(RELAY_1_PIN);
    setRelayOFF(RELAY_2_PIN);

    Serial.println("Setup ended");
}

void loop()
{
    if (digitalRead(INPUT_PIN) == HIGH)
    {
        Serial.println("Starting loop");

        Serial.println("Piston moving UP");
        setRelayON(RELAY_2_PIN);
        delay(DELAY_PISTON_UP_MS);
        setRelayOFF(RELAY_2_PIN);
        Serial.println("Piston UP");

        Serial.println("Waiting");
        delay(DELAY_PISTON_KEEP_UP_MS);

        Serial.println("Piston moving Down");
        setRelayON(RELAY_1_PIN);
        delay(DELAY_PISTON_DOWN_MS);
        setRelayOFF(RELAY_1_PIN);
        Serial.println("Piston Down");

        Serial.println("Loop ended\n");
    }
}

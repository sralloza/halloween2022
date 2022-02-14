const int relay1 = 30;
const int relay2 = 31;
const int input = 8;

const int delayPistonUpMS = 3000;
const int delayPistonDownMS = 3000;
const int delayPistonKeepUpMS = 5000;

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

    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(input, INPUT);

    setRelayOFF(relay1);
    setRelayOFF(relay2);

    Serial.println("Setup ended");
}

void loop()
{
    if (digitalRead(input) == HIGH)
    {
        Serial.println("Starting loop");

        Serial.println("Piston moving UP");
        setRelayON(relay2);
        delay(delayPistonUpMS);
        setRelayOFF(relay2);
        Serial.println("Piston UP");

        Serial.println("Waiting");
        delay(delayPistonKeepUpMS);

        Serial.println("Piston moving Down");
        setRelayON(relay1);
        delay(delayPistonDownMS);
        setRelayOFF(relay1);
        Serial.println("Piston Down");

        Serial.println("Loop ended\n");
    }
}

const int RELAY_1_PIN = 7;
const int RELAY_2_PIN = 8;
const int LED_1_PIN = 4;
const int LED_2_PIN = 5;

const int DELAY_PISTON_UP_MS = 2250;
const int DELAY_PISTON_DOWN_MS = DELAY_PISTON_UP_MS + 500;
const int DELAY_PISTON_KEEP_UP_MS = 10000;
const int DELAY_PISTON_KEEP_DOWN_MS = 10000;

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
    Serial.println("Starting...");

    pinMode(RELAY_1_PIN, OUTPUT);
    setRelayOFF(RELAY_1_PIN);
    pinMode(RELAY_2_PIN, OUTPUT);
    setRelayOFF(RELAY_2_PIN);

    pinMode(LED_1_PIN, OUTPUT);
    digitalWrite(LED_1_PIN, LOW);
    pinMode(LED_2_PIN, OUTPUT);
    digitalWrite(LED_2_PIN, LOW);

    Serial.println("Setup ended");
}

void loop()
{
    Serial.println("Starting loop");
    Serial.println("Waiting DOWN");
    delay(DELAY_PISTON_KEEP_DOWN_MS);

    Serial.println("Piston moving UP");
    setRelayON(RELAY_2_PIN);
    delay(DELAY_PISTON_UP_MS);
    setRelayOFF(RELAY_2_PIN);
    Serial.println("Piston UP");

    Serial.println("Waiting UP");
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, HIGH);
    delay(DELAY_PISTON_KEEP_UP_MS);

    Serial.println("Piston moving Down");
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    setRelayON(RELAY_1_PIN);
    delay(DELAY_PISTON_DOWN_MS);
    setRelayOFF(RELAY_1_PIN);

    Serial.println("Piston Down");

    Serial.println("Loop ended\n");
}

// void printDetail()
// {
//     uint8_t type = myDFPlayer.readType();
//     int value = myDFPlayer.read();
//     switch (type)
//     {
//     case TimeOut:
//         Serial.println(F("Time Out!"));
//         break;
//     case WrongStack:
//         Serial.println(F("Stack Wrong!"));
//         break;
//     case DFPlayerCardInserted:
//         Serial.println(F("Card Inserted!"));
//         break;
//     case DFPlayerCardRemoved:
//         Serial.println(F("Card Removed!"));
//         break;
//     case DFPlayerCardOnline:
//         Serial.println(F("Card Online!"));
//         break;
//     case DFPlayerPlayFinished:
//         Serial.print(F("Number:"));
//         Serial.print(value);
//         Serial.println(F(" Play Finished!"));
//         break;
//     case DFPlayerError:
//         Serial.print(F("DFPlayerError:"));
//         switch (value)
//         {
//         case Busy:
//             Serial.println(F("Card not found"));
//             break;
//         case Sleeping:
//             Serial.println(F("Sleeping"));
//             break;
//         case SerialWrongStack:
//             Serial.println(F("Get Wrong Stack"));
//             break;
//         case CheckSumNotMatch:
//             Serial.println(F("Check Sum Not Match"));
//             break;
//         case FileIndexOut:
//             Serial.println(F("File Index Out of Bound"));
//             break;
//         case FileMismatch:
//             Serial.println(F("Cannot Find File"));
//             break;
//         case Advertise:
//             Serial.println(F("In Advertise"));
//             break;
//         default:
//             break;
//         }
//         break;
//     default:
//         break;
//     }
// }

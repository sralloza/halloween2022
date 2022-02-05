const int relay = 14;  // D5
const int input = 12;  // D6
const int delayms = 3000;

void setup()
{
    Serial.begin(9600);
    Serial.write("Starting...\n");
    pinMode(relay, OUTPUT); //initialize the relay pin as an output
    pinMode(input, INPUT);
    digitalWrite(relay, HIGH);
    Serial.write("Setup ended\n");
}

void loop()
{
    // String msg = sprintf("data: %s", digitalRead(input));
    // Serial.write("Hi there\n");
    // delay(1000);
    if (digitalRead(input) == HIGH){
        Serial.write("Starting loop\n");
        digitalWrite(relay, LOW);
        delay(delayms); //wait for 2s
        digitalWrite(relay, HIGH);
        Serial.write("Loop ended\n\n");
    }
}

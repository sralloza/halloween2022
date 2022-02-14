#include <SoftwareSerial.h>

SoftwareSerial ExtSerial(0, 0);

void setup()
{
    Serial.begin(9600);
    ExtSerial.begin(115200);
}

void loop()
{
    ExtSerial.println("Hi there!");
    if (Serial.available() > 0)
    {
        String incomingString = Serial.readStringUntil('\n');

        Serial.print("[MEGA] Received '");
        Serial.print(incomingString);
        Serial.print("' from serial port\n");
        Serial.print("Hello from MEGA");
        delay(5000);
    }
}

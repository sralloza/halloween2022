#include <SoftwareSerial.h>

SoftwareSerial ExtSerial(3, 1);


void setup()
{
  Serial.begin(9600);
  ExtSerial.begin(115200);
}

void loop() {
    Serial.println("[ESP8266] Sending hello throw serial port");
    Serial.write("Hello from ESP8266");
    delay(5000);
}

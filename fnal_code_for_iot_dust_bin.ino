#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "kqvb8X4-acjJDmGS2rbtJjOfqRq6xNGJ";

char ssid[] = "iotdustbin";
char pass[] = "iotdustbin";

#define trig D5   
#define echo D4

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  long level = 20 - cm;
  if (level < 0)
    level = 0;
  Blynk.virtualWrite(V1, level);
  if (cm < 7)
    Blynk.notify("Alert dustbin  Full");
  Blynk.run();
}



/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID   "TMPLuVTIzP36"

/เพิ่ม library
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

DHT dht;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cBAi7DVoSqkV7D6QvguZkY0ApA7O5r8h";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wittaya1108_2.4GHz";
char pass[] = "0895478887";

int Temperature;
int Humidity;

void setup()
{
  // Debug console
  Serial.begin(9600);

  dht.setup(D1); // data pin D1

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  Temperature = dht.getTemperature();
  Humidity = dht.getHumidity();

  // Print serial messages
  Serial.print("Humidity: " + String(Humidity) + " %");
  Serial.print("\t");
  Serial.println("Temperature: " + String(Temperature) + " C");

  // Update Blynk data
  Blynk.virtualWrite(V0, Temperature);
  Blynk.virtualWrite(V1, Humidity);
  
  delay(1000);  
}

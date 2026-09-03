```cpp
/*
 * ============================================================
 * Project: Manhole Monitoring System
 * Board: ESP8266
 * IoT Platform: Blynk
 * ============================================================
 *
 * Description:
 * This project monitors a manhole using multiple sensors
 * connected to an ESP8266. Sensor readings are sent to the
 * Blynk IoT platform for remote monitoring.
 *
 * Sensors:
 * 1. Gas Sensor       -> A0
 * 2. Water Sensor     -> D5
 * 3. BMP180 Pressure  -> I2C
 *
 * Blynk Virtual Pins:
 * V0 -> Gas Sensor Value
 * V2 -> Atmospheric Pressure
 * V4 -> Water Detection Status
 *
 * Data update interval:
 * Every 2 seconds
 *
 * NOTE:
 * Wi-Fi credentials and Blynk authentication details are
 * intentionally replaced with placeholders for security.
 * Add your actual credentials only in your local Arduino IDE.
 * ============================================================
 */


// ------------------------------------------------------------
// Blynk Configuration
// ------------------------------------------------------------

#define BLYNK_TEMPLATE_ID   "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "manhole4"
#define BLYNK_AUTH_TOKEN    "YOUR_BLYNK_AUTH_TOKEN"


// ------------------------------------------------------------
// Required Libraries
// ------------------------------------------------------------

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>


// ------------------------------------------------------------
// Wi-Fi Credentials
// ------------------------------------------------------------
// Replace these values only in your local Arduino IDE.
// Do NOT upload real credentials to a public repository.
// ------------------------------------------------------------

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";


// ------------------------------------------------------------
// Objects
// ------------------------------------------------------------

BlynkTimer timer;
Adafruit_BMP085 bmp;


// ------------------------------------------------------------
// Send Sensor Data to Blynk
// ------------------------------------------------------------

void sendSensorData()
{

  // ----------------------------------------------------------
  // Gas Sensor
  // Connected to ESP8266 Analog Pin A0
  // ----------------------------------------------------------

  int gasValue = analogRead(A0);

  // Send gas sensor value to Blynk
  Blynk.virtualWrite(V0, gasValue);

  // Display gas value in Serial Monitor
  Serial.print("Gas: ");
  Serial.println(gasValue);


  // ----------------------------------------------------------
  // Water Sensor
  // Connected to Digital Pin D5
  // ----------------------------------------------------------

  int waterValue = digitalRead(D5);

  if (waterValue == LOW)
  {

    // Water detected
    Blynk.virtualWrite(V4, 1);

    Serial.println("Water: DETECTED!");

  }
  else
  {

    // No water detected
    Blynk.virtualWrite(V4, 0);

    Serial.println("Water: No water");
  }


  // ----------------------------------------------------------
  // BMP180 Pressure Sensor
  // Connected using I2C
  // ----------------------------------------------------------

  float pressure = bmp.readPressure() / 100.0;

  // Send pressure value to Blynk
  Blynk.virtualWrite(V2, pressure);

  // Display pressure in Serial Monitor
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");


  // ----------------------------------------------------------
  // Separator for Serial Monitor
  // ----------------------------------------------------------

  Serial.println("----------------------------");
}


// ------------------------------------------------------------
// Setup
// ------------------------------------------------------------

void setup()
{

  // Start Serial Communication
  Serial.begin(9600);

  Serial.println();
  Serial.println("=================================");
  Serial.println("   Manhole Monitoring System");
  Serial.println("=================================");


  // ----------------------------------------------------------
  // Configure Water Sensor
  // ----------------------------------------------------------

  pinMode(D5, INPUT_PULLUP);


  // ----------------------------------------------------------
  // Initialize BMP180
  // ----------------------------------------------------------

  if (!bmp.begin())
  {

    Serial.println("ERROR: BMP180 not found!");

  }
  else
  {

    Serial.println("BMP180 initialized successfully.");
  }


  // ----------------------------------------------------------
  // Connect to Wi-Fi and Blynk
  // ----------------------------------------------------------

  Serial.println("Connecting to Wi-Fi and Blynk...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);


  // ----------------------------------------------------------
  // Set Sensor Reading Interval
  // ----------------------------------------------------------
  // Sensor data is sent every 2 seconds.
  // ----------------------------------------------------------

  timer.setInterval(2000L, sendSensorData);

  Serial.println("System initialized successfully.");
}


// ------------------------------------------------------------
// Main Loop
// ------------------------------------------------------------

void loop()
{

  // Run Blynk
  Blynk.run();

  // Run timer
  timer.run();
}
```

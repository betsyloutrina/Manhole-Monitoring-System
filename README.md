# 🚧 Manhole Monitoring System

An IoT-based manhole monitoring system using ESP8266, gas sensing, water detection, BMP180 pressure sensing, and Blynk IoT for remote monitoring.

## 📌 Project Overview

The system is designed to monitor hazardous conditions inside a manhole and provide real-time sensor information through the Blynk IoT platform.

The ESP8266 collects sensor data and sends it to the Blynk dashboard over Wi-Fi.

## 🔧 Hardware Used

- ESP8266 NodeMCU
- Gas Sensor
- Water Detection Sensor
- BMP180 Pressure Sensor
- Breadboard
- Jumper Wires
- USB Cable / Power Supply

## 💻 Software & Technologies

- Arduino IDE
- Embedded C/C++
- ESP8266
- Blynk IoT
- I2C Communication

## 📊 Sensors and Connections

| Component | ESP8266 Pin | Purpose |
|---|---|---|
| Gas Sensor | A0 | Gas level monitoring |
| Water Sensor | D5 | Water detection |
| BMP180 SCL | D1 | I2C clock |
| BMP180 SDA | D2 | I2C data |

## 📱 Blynk Dashboard

| Virtual Pin | Data |
|---|---|
| V0 | Gas Sensor Value |
| V2 | Pressure |
| V4 | Water Detection |

## ⚙️ Working

1. ESP8266 connects to Wi-Fi.
2. Gas sensor measures the gas level.
3. Water sensor detects the presence of water.
4. BMP180 measures atmospheric pressure.
5. Sensor data is sent to Blynk.
6. Data is updated every 2 seconds.
7. The user can monitor the system remotely.

## 📷 Prototype

![Manhole Monitoring System Prototype](images/prototype.png)

## 🔌 Circuit Diagram

![Manhole Monitoring System Circuit Diagram](images/circuit.png)

## 🔐 Security

Sensitive credentials such as Wi-Fi passwords and Blynk authentication tokens are not included in this repository.

Replace the following placeholders in your local Arduino code:

```text
YOUR_BLYNK_TEMPLATE_ID
YOUR_BLYNK_AUTH_TOKEN
YOUR_WIFI_NAME
YOUR_WIFI_PASSWORD
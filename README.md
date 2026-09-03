# 🚧 Manhole Monitoring System

An IoT-based smart manhole monitoring system designed to monitor hazardous conditions inside manholes using **ESP8266**, sensors, and **Blynk IoT**.

---

## 📌 Project Overview

The Manhole Monitoring System continuously monitors environmental conditions inside a manhole and sends sensor readings to a remote **Blynk dashboard** through Wi-Fi.

The system is designed to help identify potentially dangerous conditions such as:

- Gas accumulation
- Water presence
- Changes in atmospheric pressure

The ESP8266 acts as the main controller and communicates with the sensors while transmitting the collected data to Blynk.

---

## 🎯 Objectives

- Monitor gas levels inside a manhole.
- Detect the presence of water.
- Measure atmospheric pressure.
- Send sensor readings remotely using Wi-Fi.
- Display real-time sensor information on a Blynk dashboard.
- Provide a foundation for future automated warning and safety systems.

---

## 🔧 Hardware Components

| Component | Purpose |
|---|---|
| ESP8266 NodeMCU | Main microcontroller and Wi-Fi communication |
| Gas Sensor | Detects gas concentration |
| Water Detection Sensor | Detects water presence |
| BMP180 Pressure Sensor | Measures atmospheric pressure |
| Breadboard | Circuit prototyping |
| Jumper Wires | Electrical connections |
| USB Cable / Power Supply | Provides power to the system |

---

## 💻 Software & Technologies

- **Arduino IDE**
- **Embedded C/C++**
- **ESP8266**
- **Blynk IoT**
- **I2C Communication**
- **Wi-Fi**

---

## 🔌 Pin Connections

| Component | ESP8266 Pin | Function |
|---|---|---|
| Gas Sensor | A0 | Analog gas reading |
| Water Sensor | D5 | Digital water detection |
| BMP180 SCL | D1 | I2C Clock |
| BMP180 SDA | D2 | I2C Data |
| Sensors VCC | 3.3V | Power |
| Sensors GND | GND | Ground |

> **Note:** Sensor modules should be powered according to their individual voltage specifications.

---

## 📊 Blynk Virtual Pins

| Virtual Pin | Sensor | Data |
|---|---|---|
| V0 | Gas Sensor | Gas sensor reading |
| V2 | BMP180 | Pressure in hPa |
| V4 | Water Sensor | Water detection status |

### Water Detection

```text
V4 = 1 → Water Detected
V4 = 0 → No Water
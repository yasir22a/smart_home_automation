📘 Smart Home Security System — README.md
📌 Overview

This project is an IoT-based Smart Home Security System using ESP32, PIR sensor, Flame sensor (Potentiometer in simulation), DHT22, Relay-controlled LED, Buzzer, and Blynk IoT Dashboard.

It detects:

🔹 Motion

🔥 Flame/Smoke (Potentiometer used in Wokwi)

🌡️ Temperature & Humidity

And responds by:

Turning ON relay-controlled room light

Turning ON output LED

Activating Buzzer

Updating Blynk widgets

🧩 Features

✔ PIR Motion Detection
✔ Flame/Smoke Detection
✔ Temperature & Humidity Monitoring
✔ Relay-controlled room light
✔ Buzzer Alarm
✔ Real-time Dashboard using Blynk IoT
✔ Wokwi Simulation Supported

🛠 Components Used
Component	Purpose
ESP32 WROVER/WROOM	Main controller
PIR Sensor	Motion detection
Potentiometer	Flame simulation
DHT22	Temperature & humidity
Relay Module	Controls room light
LED	Room light indicator
Buzzer	Alarm
Wokwi	Online simulation
Blynk IoT	Dashboard + monitoring


🌐 Blynk Setup Guide (Simple & Clear)
⭐ 1. Create Blynk Account

Go to: https://blynk.cloud

Login with Google/email.

⭐ 2. Enable Developer Mode

Profile → Enable Developer Mode.

⭐ 3. Create Template

Templates → New Template

Name: Smart Home Security

Hardware: ESP32

Connection: WiFi

Save.

⭐ 4. Add Datastreams

Go to Datastreams → New Datastream → Virtual Pin

Add the following:

Datastream	Pin	Type
Temperature	V0	Double
Humidity	V1	Double
PIR	V2	Integer
Flame	V4	Integer
Room Light	V5	Integer
Alarm	V10	Integer
⭐ 5. Create Device

Devices → New Device → From Template → Select your template.
Copy your Auth Token.

⭐ 6. Add Widgets (Web Dashboard)

Value → V0 (Temperature)

Value → V1 (Humidity)

LED → V2 (PIR)

LED → V4 (Flame)

LED → V5 (Room Light)

LED → V10 (Alarm)

Done!

🔌 Connections

(Use your Wokwi diagram)

PIR OUT → GPIO 13

DHT DATA → GPIO 4

Potentiometer → GPIO 34

Relay IN → GPIO 26

Buzzer → GPIO 27

LED (via Relay) → 5V through NO/COM

🧾 Code

Use your final working code.

▶️ How to Run in Wokwi

Open https://wokwi.com

Create ESP32 project

Add components (PIR, DHT22, Relay, LED, Buzzer, Pot)

Replace diagram.json and code with your files

Click Run

# ??? Arduino Web Serial Radar

A retro-styled, browser-based radar dashboard that connects directly to an Arduino using the **Web Serial API**. No backend servers, Python scripts, or Node.js required—just pure HTML, CSS, JavaScript, and an Arduino!

![Radar UI Preview](https://via.placeholder.com/800x400.png?text=Arduino+Web+Radar+UI) ## ? Features
* **Direct Browser Connection:** Uses the Web Serial API to read data straight from the USB port.
* **No Backend Required:** Works entirely client-side.
* **Retro UI:** CRT monitor flicker, scanlines, and fading sonar blips using HTML5 Canvas and Tailwind CSS.
* **Plug & Play:** Easily adjustable baud rates and distance limits right from the UI.

## ??? Hardware Requirements
* 1x Arduino (Uno, Nano, Mega, etc.)
* 1x HC-SR04 Ultrasonic Sensor
* 1x SG90 Micro Servo Motor
* Jumper wires & Breadboard

## ?? Wiring Guide

| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V |
| | GND | GND |
| | TRIG | D9 |
| | ECHO | D10 |
| **SG90 Servo** | Power (Red) | 5V |
| | Ground (Black/Brown)| GND |
| | Signal (Yellow/Orange)| D11 |

## ?? Setup & Usage

### 1. Arduino Setup
1. Open `radar_sensor.ino` in the Arduino IDE.
2. Install the standard `Servo.h` library if you haven't already.
3. Upload the code to your Arduino.
4. **Important:** Close the Arduino IDE Serial Monitor so the browser can access the COM port!

### 2. Web App Setup
Because of browser security rules regarding the Web Serial API, the HTML file must be served over `https://` or `http://localhost`.

**Quick Local Server (Python):**
1. Open your terminal/command prompt in this project folder.
2. Run: `python -m http.server`
3. Open Chrome or Edge and go to `http://localhost:8000/radar.html`.

**Alternative:** Use VS Code's "Live Server" extension.

### 3. Connect
1. Click the **CONNECT ARDUINO** button on the web page.
2. Select your Arduino's COM port from the browser popup.
3. Watch the radar sweep and detect obstacles in real-time!

## ?? Browser Compatibility
This project relies on the **Web Serial API**, which is currently supported on desktop versions of:
* Google Chrome
* Microsoft Edge
* Opera
*(Note: Mobile browsers and Safari currently do not support Web Serial API).*

## ?? License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
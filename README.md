# Arduino Web Serial Radar

A browser-based radar dashboard that connects to an Arduino via the Web Serial API. It operates entirely client-side without requiring a backend server.

![Radar UI Preview](https://via.placeholder.com/800x400.png?text=Arduino+Web+Radar+UI)

## Features
* **Direct Connection:** Uses the Web Serial API to read data from the USB port.
* **Client-Side Only:** No Python or Node.js backend required.
* **Radar UI:** Visual interface using HTML5 Canvas and Tailwind CSS.
* **Adjustable Parameters:** Configurable baud rates and distance limits within the UI.

## Hardware Requirements
* 1x Arduino (Uno, Nano, Mega, etc.)
* 1x HC-SR04 Ultrasonic Sensor
* 1x SG90 Micro Servo Motor
* Jumper wires and a breadboard

## Wiring Guide

| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V |
| | GND | GND |
| | TRIG | D9 |
| | ECHO | D10 |
| **SG90 Servo** | Power | 5V |
| | Ground | GND |
| | Signal | D11 |

## Setup and Usage

### 1. Arduino Setup
1. Open `radar_sensor.ino` in the Arduino IDE.
2. Install the `Servo.h` library if it is not already installed.
3. Upload the code to your Arduino.
4. Close the Arduino IDE Serial Monitor to release the COM port.

### 2. Web App Setup
Due to browser security policies for the Web Serial API, the HTML file must be served over `https://` or `http://localhost`.

**Using Python's HTTP Server:**
1. Open a terminal in the project directory.
2. Run: `python -m http.server`
3. Navigate to `http://localhost:8000/radar.html` in your browser.

### 3. Connect
1. Click the **Connect Arduino** button on the web page.
2. Select the Arduino's COM port from the browser prompt.
3. The radar interface will begin displaying sensor data.

## Browser Compatibility
This project requires the Web Serial API, which is supported on desktop versions of:
* Google Chrome
* Microsoft Edge
* Opera

*Note: Mobile browsers and Safari do not currently support the Web Serial API.*

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

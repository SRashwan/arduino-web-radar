# Arduino Web Serial Radar

A browser-based radar dashboard that connects directly to an Arduino via the Web Serial API. It operates entirely client-side without requiring a backend server, Python scripts, or Node.js bridging.

![Radar UI Preview](https://raw.githubusercontent.com/SRashwan/arduino-web-radar/refs/heads/main/Screenshot_30-6-2026_32621_.jpeg)

## 📖 How It Works

This project bridges the gap between hardware and the web using the modern **Web Serial API**. 
1. **The Hardware:** An Arduino sweeps a servo motor back and forth from 0° to 180°. Attached to this servo is an ultrasonic sensor (HC-SR04) that measures the distance to the nearest obstacle at each degree.
2. **The Data Stream:** The Arduino formats this data into a simple comma-separated string (`Angle,Distance\n`) and sends it over the USB serial connection.
3. **The Interface:** The web browser reads this serial stream directly, parses the incoming text, and uses HTML5 Canvas to draw a retro-style radar sweep, plotting obstacles in real-time.

---

## ✨ Features
* **Direct Browser Connection:** Uses the Web Serial API to read data straight from the USB port.
* **Zero Backend:** Pure HTML, CSS (Tailwind), and JavaScript. No local servers or middleware required to parse data.
* **Dynamic Radar UI:** Visual interface featuring CRT monitor flicker, scanlines, and fading sonar blips.
* **Adjustable Parameters:** Configurable baud rates and maximum distance thresholds directly within the UI.

---

## 🛠️ Hardware Requirements
* 1x Arduino (Uno, Nano, Mega, etc.)
* 1x HC-SR04 Ultrasonic Sensor
* 1x SG90 Micro Servo Motor
* Jumper wires and a breadboard
* USB cable to connect the Arduino to your computer

---

## 🔌 Wiring Guide

To ensure accurate readings, power both the servo and the ultrasonic sensor from the Arduino's 5V pin. You may want to use a breadboard to split the 5V and GND lines.

| Component | Pin Name | Arduino Pin | Description |
| :--- | :--- | :--- | :--- |
| **HC-SR04** | VCC | 5V | Powers the ultrasonic sensor. |
| | GND | GND | Completes the circuit. |
| | TRIG | D9 | Sends the trigger pulse to emit sound waves. |
| | ECHO | D10 | Receives the bouncing sound wave to calculate time/distance. |
| **SG90 Servo** | Power (Red) | 5V | Powers the motor. |
| | Ground (Brown/Black)| GND | Completes the circuit. |
| | Signal (Yellow/Orange)| D11 | PWM signal to control the sweeping angle. |

---

## 💻 Arduino Logic & Code

For the web interface to understand the hardware, the Arduino must send data in a very specific format: `Angle,Distance\n`. 

Here is the core logic from the `radar_sensor.ino` file. It sweeps the servo and formats the serial output so the browser can parse it:

```cpp
void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);       // Move servo
    delay(30);                  // Wait for servo to reach position
    
    int distance = calculateDistance(); // Ping the ultrasonic sensor
    
    // CRITICAL: Send data to Serial exactly as the Web App expects
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
  
  // Sweep back from 180 down to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(30);
    
    int distance = calculateDistance();
    
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}

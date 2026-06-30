#include <Servo.h>

// --- Pin Definitions ---
// HC-SR04 Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;
// Servo Motor Pin
const int servoPin = 11;

// Variables for distance calculation
long duration;
int distance;

Servo myServo; // Create a servo object to control the motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  
  // Attach the servo to the specified pin
  myServo.attach(servoPin);
  
  // Start serial communication at 9600 baud rate (Must match the web app)
  Serial.begin(9600);
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);       // Command servo to go to the current angle
    delay(30);                  // Wait 30ms for the servo to reach the position
    
    distance = calculateDistance(); // Measure the distance
    
    // Send data to Serial exactly as the Web App expects: "Angle,Distance\n"
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
  
  // Sweep from 180 down to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);       // Command servo to go to the current angle
    delay(30);                  // Wait 30ms for the servo to reach the position
    
    distance = calculateDistance(); // Measure the distance
    
    // Send data to Serial exactly as the Web App expects: "Angle,Distance\n"
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}

// --- Helper function to calculate distance ---
int calculateDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds to send out a pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (Speed of sound is 340 m/s or 0.034 cm/microsecond)
  // Divide by 2 because the wave travels out and reflects back
  distance = duration * 0.034 / 2;
  
  // Optional: Cap the distance to avoid messy readings if it's too far
  // if (distance > 200) distance = 200; 
  
  return distance;
}

Laser Alarm System - Step-by-Step Guide

Components Required:
- Arduino Uno (or compatible board)
- Laser Diode (or laser pointer)
- LDR (Light-Dependent Resistor) or Phototransistor
- 10kΩ Resistor (for LDR)
- Buzzer or LED (for alarm)
- Breadboard and Jumper Wires
- Power source (USB cable or external battery pack)
  
Step 1: Set Up Your Circuit
1. **Laser Diode Connection**:
   - Laser Diode Positive Pin (+) → Connect to 5V pin on the Arduino.
   - Laser Diode Negative Pin (-) → Connect to GND on the Arduino.
2. **LDR (Light-Dependent Resistor) Connection**:
   - LDR Pin 1 → Connect to 5V on the Arduino.
   - LDR Pin 2 → Connect to Analog Pin A0 and also to one end of a 10kΩ resistor.
   - Connect the other end of the 10kΩ resistor to GND.
3. **Buzzer or LED Connection**:
   - Buzzer/LED Positive Pin → Connect to Digital Pin 8 on the Arduino.
   - Buzzer/LED Negative Pin → Connect to GND on the Arduino.
     
Step 2: Upload the Code
1. Open the Arduino IDE on your computer.
2. Copy the Arduino code provided below.
3. Upload the code to your Arduino.
4. Connect the Arduino via USB and press the 'Upload' button in the Arduino IDE.
   
Step 3: Monitor and Adjust
1. Open the Serial Monitor in the Arduino IDE.
2. Observe the LDR values and adjust the laser alignment so it falls on the LDR.
3. If the beam is interrupted, the alarm (buzzer or LED) will be triggered.
4. Adjust the threshold value in the code to change the sensitivity.
   
Arduino Code:
const int ldrPin = A0;  // LDR connected to analog pin A0
const int alarmPin = 8; // Buzzer or LED connected to digital pin 8
int threshold = 500;    // Set a threshold value for detecting the laser

void setup() {
  pinMode(alarmPin, OUTPUT);  // Set the alarm pin as an output
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read the value from the LDR
  Serial.println(ldrValue);           // Print the value for debugging

  // If the LDR value drops below the threshold, trigger the alarm
  if (ldrValue < threshold) {
    digitalWrite(alarmPin, HIGH);  // Turn on the buzzer or LED
  } else {
    digitalWrite(alarmPin, LOW);   // Turn off the buzzer or LED
  }

  delay(100);  // Short delay to stabilize readings
}


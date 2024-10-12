
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

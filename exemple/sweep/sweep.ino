#include <viscalib.h>           // Include the ViscaLib library for controlling VISCA-compatible devices.
#include <SoftwareSerial.h>     // Include the SoftwareSerial library for creating a software serial port.

SoftwareSerial mySerial(2, 3); // Create a SoftwareSerial object named 'mySerial' using pins 2 (TX) and 3 (RX).

ViscaLib myVisca(mySerial);     // Create a ViscaLib object named 'myVisca' using the 'mySerial' serial port.

void setup() {
  mySerial.begin(38400);       // Initialize the 'mySerial' serial port at a baud rate of 38400 (adjust to match your camera's serial port speed).
}

void loop() {
  myVisca.PAN_TILT_LEFT(5);   // Send a PAN_TILT_LEFT command with a speed of 5 (adjust speed as needed).
  delay(1000);                // Wait 1 second.

  myVisca.PAN_TILT_RIGHT(5);  // Send a PAN_TILT_RIGHT command with a speed of 5 (adjust speed as needed).
  delay(1000);                 // Wait 1 second.
}

# ViscaLib

ViscaLib is an Arduino library that allows you to control Visca-compatible PTZ cameras.
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)


## How it work ?

This library generates [Visca](https://en.wikipedia.org/wiki/VISCA_Protocol) commands from predefined functions. For example, if you call PAN_TILT_UP(5);

It will send the following command to the chosen serial interface:

```
0x81 0x01, 0x06, 0x01, 0x05, 0x05, 0x03, 0x01, 0xFF
```

⚠️ **I only tested it on Sony Ipela SNC-RX550** ⚠️

## Installation

Simply clone or download and extract the zipped library into your Arduino/libraries folder.
## Usage/Examples

```c++
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
```

## API Reference

#### This are all the command that Viscalib support:


| Function | Parameter |
| :-------- | :------- |
| `PAN_TILT_UP(s)` | `s = speed value 1 to 18` | 
| `PAN_TILT_DOWN(s)` | `s = speed value 1 to 18` | 
| `PAN_TILT_LEFT(s)` | `s = speed value 1 to 18` | 
| `PAN_TILT_RIGHT(s)` | `s = speed value 1 to 18` | 
| `PAN_TILT_UP_LEFT(s1, s2)` | `s1 = pan speed ; s2 = tilt speed 1 to 18` |
| `PAN_TILT_UP_RIGHT(s1, s2)` | `s1 = pan speed ; s2 = tilt speed 1 to 18` |
| `PAN_TILT_DOWN_LEFT(s1, s2)` | `s1 = pan speed ; s2 = tilt speed 1 to 18` |
| `PAN_TILT_DOWN_RIGHT(s1, s2)` | `s1 = pan speed ; s2 = tilt speed 1 to 18` |
| `PAN_TILT_STOP()` | `none` |
| `PAN_TILT_HOME()` | `none` |
| `PAN_TILT_RESET()` | `none` |
| `IF_Clear()` | `none` |
| `PAN_TILT_RAMP_CURVE(x)` | `x: 1 (Sharpness), 2 (Standard), 3 (Gentle)` |
| `PAN_TILT_SLOW_MODE(x)` | `x: True / False` |
| `PAN_TILT_ABSOLUTE_POSITION(s, x, y)` | `s = speed value 1 to 18 ; x = Pan value -8160 to 8160 ; y = Tilt value -2040 to 2040` |
| `PAN_TILT_RELATIVE_POSITION(s, x, y)` | `s = speed value 1 to 18 ; x = Pan value -8160 to 8160 ; y = Tilt value -2040 to 2040` |

## Authors

- [Unix5](https://unix5.net)


## License

GNU General Public License v3.0 or later

See COPYING to see the full text.
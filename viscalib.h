#ifndef VISCALIB_H
#define VISCALIB_H

#include <Arduino.h>

class ViscaLib {
public:
  ViscaLib(Stream& serialPort);
  void IF_Clear();
  void PAN_TILT_UP(byte speed);
  void PAN_TILT_DOWN(byte speed);
  void PAN_TILT_LEFT(byte speed);
  void PAN_TILT_RIGHT(byte speed);
  void PAN_TILT_UP_LEFT(byte panSpeed, byte tiltSpeed);
  void PAN_TILT_UP_RIGHT(byte panSpeed, byte tiltSpeed);
  void PAN_TILT_DOWN_LEFT(byte panSpeed, byte tiltSpeed);
  void PAN_TILT_DOWN_RIGHT(byte panSpeed, byte tiltSpeed);
  void PAN_TILT_STOP(byte panSpeed, byte tiltSpeed);
  void PAN_TILT_HOME();
  void PAN_TILT_RESET();
  void PAN_TILT_RAMP_CURVE(byte rampCurve);
  void PAN_TILT_SLOW_MODE(bool enable);
  void PAN_TILT_ABSOLUTE_POSITION(byte speed, int panPosition, int tiltPosition);
  void PAN_TILT_RELATIVE_POSITION(byte speed, int panPosition, int tiltPosition);

private:
  Stream& _serial;
  void sendList(byte list[], size_t listsize);
};

#endif  // VISCALIB_H
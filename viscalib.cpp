#include "viscalib.h"

ViscaLib::ViscaLib(Stream& serialPort) : _serial(serialPort) {
}

void ViscaLib::sendList(byte list[], size_t listsize) {
  _serial.write(0x81);
  //_serial.print(0x81, HEX);
  for (size_t i = 0; i < listsize; i++) {
    _serial.write(list[i]);
    //_serial.print(" ");
    //_serial.print(list[i], HEX);
  }
  _serial.write(0xFF);
  //_serial.println(0xFF, HEX);
}

void ViscaLib::IF_Clear() {
  byte list[3] = {0x01, 0x00, 0x01};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_UP(byte speed) {
  byte list[7] = {0x01, 0x06, 0x01, speed, speed, 0x03, 0x01};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_DOWN(byte speed) {
  byte list[7] = {0x01, 0x06, 0x01, speed, speed, 0x03, 0x02};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_LEFT(byte speed) {
  byte list[7] = {0x01, 0x06, 0x01, speed, speed, 0x01, 0x03};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_RIGHT(byte speed) {
  byte list[7] = {0x01, 0x06, 0x01, speed, speed, 0x02, 0x03};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_UP_LEFT(byte panSpeed, byte tiltSpeed) {
  byte list[7] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x01, 0x01};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_UP_RIGHT(byte panSpeed, byte tiltSpeed) {
  byte list[7] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x02, 0x01};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_DOWN_LEFT(byte panSpeed, byte tiltSpeed) {
  byte list[7] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x01, 0x02};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_DOWN_RIGHT(byte panSpeed, byte tiltSpeed) {
  byte list[7] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x02, 0x02};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_STOP(byte panSpeed, byte tiltSpeed) {
  // Commande pour arrêter le mouvement PAN/TILT
  byte list[7] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x03, 0x03};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_HOME() {
  byte list[3] = {0x01, 0x06, 0x04};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_RESET() {
  byte list[3] = {0x01, 0x06, 0x05};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_RAMP_CURVE(byte rampCurve) {
  byte list[] = {0x01, 0x06, 0x31, rampCurve};
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_SLOW_MODE(bool enable) {
  byte list[] = {0x01, 0x06, 0x44, 0x03};
  if (enable) {
    list[3] = 0x02;
  }
  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_ABSOLUTE_POSITION(byte speed, int panPosition, int tiltPosition) {

  byte list[13] = {0x01, 0x06, 0x02, speed, speed, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  int16_t signedpanPosition = constrain(panPosition, -8160, 8160);

  uint8_t signedpanPosition_byte1 = (signedpanPosition >> 8) & 0xFF;
  uint8_t signedpanPosition_byte2 = signedpanPosition & 0xFF;

  list[5] = signedpanPosition_byte1 >> 4;
  list[6] = signedpanPosition_byte1 & 0x0F;
  list[7] = signedpanPosition_byte2 >> 4;
  list[8] = signedpanPosition_byte2 & 0x0F;

  int16_t signedtiltPosition = constrain(tiltPosition, -2040, 2040);

  uint8_t signedtiltPosition_byte1 = (signedtiltPosition >> 8) & 0xFF;
  uint8_t signedtiltPosition_byte2 = signedtiltPosition & 0xFF;

  list[9] = signedtiltPosition_byte1 >> 4;
  list[10] = signedtiltPosition_byte1 & 0x0F;
  list[11] = signedtiltPosition_byte2 >> 4;
  list[12] = signedtiltPosition_byte2 & 0x0F;

  sendList(list, sizeof(list) / sizeof(list[0]));
}

void ViscaLib::PAN_TILT_RELATIVE_POSITION(byte speed, int panPosition, int tiltPosition) {

  byte list[13] = {0x01, 0x06, 0x03, speed, speed, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  int16_t signedpanPosition = constrain(panPosition, -8160, 8160);
  uint8_t signedpanPosition_byte1 = (signedpanPosition >> 8) & 0xFF;
  uint8_t signedpanPosition_byte2 = signedpanPosition & 0xFF;

  list[5] = signedpanPosition_byte1 >> 4;
  list[6] = signedpanPosition_byte1 & 0x0F;
  list[7] = signedpanPosition_byte2 >> 4;
  list[8] = signedpanPosition_byte2 & 0x0F;

  int16_t signedtiltPosition = constrain(tiltPosition, -2040, 2040);
  uint8_t signedtiltPosition_byte1 = (signedtiltPosition >> 8) & 0xFF;
  uint8_t signedtiltPosition_byte2 = signedtiltPosition & 0xFF;

  list[9] = signedtiltPosition_byte1 >> 4;
  list[10] = signedtiltPosition_byte1 & 0x0F;
  list[11] = signedtiltPosition_byte2 >> 4;
  list[12] = signedtiltPosition_byte2 & 0x0F;

  sendList(list, sizeof(list) / sizeof(list[0]));
}
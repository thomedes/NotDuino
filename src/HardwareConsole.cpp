#include "HardwareConsole.h"

int HardwareConsole::available() { return 0; }

size_t HardwareConsole::write(uint8_t byte) {
  putchar(byte);
  return 1;
}

int HardwareConsole::read() { return EOF; }
int HardwareConsole::peek() { return EOF; }

HardwareConsole Console;

#ifndef USE_SERIAL_AS_SERIAL
HardwareSerial Serial = HardwareConsole();
#endif

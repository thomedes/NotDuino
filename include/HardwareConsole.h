#ifndef NOTDUINO__CONSOLE_H__
#define NOTDUINO__CONSOLE_H__

#include "Stream.h"

class HardwareConsole : public Stream {
public:
  int available() override;
  int read() override;
  int peek() override;
  size_t write(uint8_t byte) override { putchar(byte); return 1; }
};

extern HardwareConsole Console;

#endif // NOTDUINO__CONSOLE_H__

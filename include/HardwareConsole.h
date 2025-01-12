/**
 * @file HardwareConsole.h
 * @brief Defines the HardwareConsole class which acts as a console interface
 * for Arduino programs.
 *
 * The HardwareConsole class inherits from the Serial class to provide a console
 * interface for Arduino programs. It overrides specific methods to handle
 * console input and output, while ignoring serial-specific commands such as
 * speed and parity.
 *
 * @class HardwareConsole
 * @brief A console interface derived from the Serial class.
 *
 * The HardwareConsole class overrides the following methods:
 * - available(): Checks the number of bytes available for reading.
 * - read(): Reads a byte from the console.
 * - peek(): Returns the next byte to be read without removing it from the input
 * buffer.
 * - write(uint8_t byte): Writes a byte to the console output.
 *
 * @note This class is designed to be used as a console interface in Arduino
 * programs, and it ignores serial-specific commands.
 *
 * @var HardwareConsole::Console
 * @brief An external instance of the HardwareConsole class.
 */
#ifndef NOTDUINO__CONSOLE_H__
#define NOTDUINO__CONSOLE_H__

#include "HardwareSerial.h"

class HardwareConsole : public HardwareSerial {
public:
  HardwareConsole() : HardwareSerial() {}
  int available() override;
  int read() override;
  int peek() override;
  size_t write(uint8_t byte) override;
};

#endif // NOTDUINO__CONSOLE_H__

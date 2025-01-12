/**
 * @file Print.h
 * @brief Interface for printing data to various output devices.
 *
 * This file defines the Print class, which provides methods for printing
 * data in various formats to output devices.
 */

#ifndef NOTDUINO__PRINT_H__
#define NOTDUINO__PRINT_H__

#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

// DO NOT MOVE THIS INCLUDE TO THE TOP OF THE FILE
// This include contains macros that conflict with the standard library :-(
#include "Printable.h"
#include "WString.h"

/**
 * @enum
 * @brief Define common numeric bases.
 */
enum { DEC = 10, HEX = 16, OCT = 8, BIN = 2 };

/**
 * @class Print
 * @brief Abstract base class for printing data.
 *
 * The Print class provides methods for printing data in various formats.
 * Subclasses must implement the write(uint8_t) method to provide specific
 * output functionality.
 */
class Print {
protected:
  void setWriteError(int err = 1) { write_error_ = err; }

public:
  /**
   * @brief Get the write error status.
   * @return Non-zero if there was a write error, zero otherwise.
   */
  int getWriteError() { return write_error_; }

  /**
   * @brief Clear the write error status.
   */
  void clearWriteError() { write_error_ = 0; }

  /**
   * @brief Write a single byte.
   * @param byte The byte to write.
   * @return The number of bytes written (1 on success, 0 on failure).
   */
  virtual size_t write(uint8_t byte) = 0;

  /**
   * @brief Write a null-terminated string.
   * @param str The string to write.
   * @return The number of bytes written.
   */
  size_t write(const char *str) {
    return write((const uint8_t *)str, strlen(str));
  }

  /**
   * @brief Write a buffer of data.
   * @param buffer The buffer to write.
   * @param size The size of the buffer.
   * @return The number of bytes written.
   */
  virtual size_t write(const uint8_t *buffer, size_t size) {
    size_t n;
    for (n = 0; n < size; n++) {
      if (write(buffer[n]) == 0) {
        break;
      }
    }
    return n;
  }

  /**
   * @brief Write a buffer of data.
   * @param buffer The buffer to write.
   * @param size The size of the buffer.
   * @return The number of bytes written.
   */
  size_t write(const char *buffer, size_t size) {
    return write(reinterpret_cast<const uint8_t *>(buffer), size);
  }
  /**
   * @brief Get the number of bytes available for writing.
   * @return The number of bytes available for writing.
   */
  virtual int availableForWrite() { return INT_MAX; }

  size_t print(const __FlashStringHelper *);
  size_t print(const String &str) { return write(str.c_str(), str.length()); }
  size_t print(const char str[]) { return write(str, strlen(str)); }
  size_t print(char ch) { return write(static_cast<uint8_t>(ch)); }
  size_t print(unsigned char value, int base = DEC);
  size_t print(int value, int base = DEC);
  size_t print(unsigned int value, int base = DEC);
  size_t print(long value, int base = DEC);
  size_t print(unsigned long value, int base = DEC);
  size_t print(double value, int decimals = 2);
  size_t print(const Printable &obj) { return obj.printTo(*this); }

  size_t println(const __FlashStringHelper *fsh) {
    return print(fsh) + println();
  }
  size_t println(const String &str) { return print(str) + println(); }
  size_t println(const char str[]) { return print(str) + println(); }
  size_t println(char ch) { return print(ch) + println(); }
  size_t println(unsigned char value, int base = DEC) {
    return print(value, base) + println();
  }
  size_t println(int value, int base = DEC);
  size_t println(unsigned value, int base = DEC) {
    return print(value, base) + println();
  }
  size_t println(long value, int base = DEC) {
    return print(value, base) + println();
  }
  size_t println(unsigned long value, int base = DEC) {
    return print(value, base) + println();
  }
  size_t println(double value, int decimals = 2) {
    return print(value, decimals) + println();
  }
  size_t println(const Printable &x) { return print(x) + println(); }
  size_t println(void) { return print('\n'); }

  virtual void flush() { /* Empty implementation for backward compatibility */ }

private:
  // Private member variables
  bool write_error_;
};

#endif // NOTDUINO__PRINT_H__

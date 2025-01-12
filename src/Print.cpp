#include "Print.h"

#include <algorithm>
#include <cassert>

//------------------------------------------------------------------------------
//  S T A T I C   F U N C T I O N S
//------------------------------------------------------------------------------

/**
 * @brief Formats an unsigned number into a string buffer.
 *
 * If the buffer is too small to hold the formatted number, the function will
 * continue to format the number and return the required length for the
 * formatted number, not including the null terminator. In this case the
 * contents of the buffer are undefined.
 *
 * @tparam U The type of the unsigned number.
 * @param buffer The buffer to store the formatted number.
 * @param buffer_size The size of the buffer.
 * @param value The unsigned number to format.
 * @param base The numerical base to use for formatting.
 * @param position The starting position in the buffer to write the number.
 * @return The length of the formatted number, not including the null terminatr.
 */
template <typename U>
static size_t format_unsigned_number(char buffer[], size_t buffer_size, U value,
                                     int base, size_t position = 0) {
  static const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  assert(base > 0 && base <= 36);

  size_t i = position;
  do {
    if (i < buffer_size) {
      buffer[i] = digits[value % base];
    }
    ++i, value /= base;
  } while (value > 0);

  if (i < buffer_size) {
    std::reverse(buffer + position, buffer + i);
    buffer[i] = '\0';
  }

  return i;
}

/**
 * @brief Formats a signed number into a string buffer.
 *
 * If the buffer is too small to hold the formatted number, the function will
 * continue to format the number and return the required length for the
 * formatted number, not including the null terminator. In this case the
 * contents of the buffer are undefined.
 *
 * @tparam I The type of the signed number.
 * @param buffer The buffer to store the formatted number.
 * @param buffer_size The size of the buffer.
 * @param value The signed number to format.
 * @param base The numerical base to use for formatting.
 * @return The length of the formatted number, not including the null terminatr.
 */
template <typename I>
static size_t format_signed_number(char buffer[], size_t buffer_size, I value,
                                   int base) {
  size_t used = 0;

  if (value < 0) {
    buffer[0] = '-';
    used = 1;
    value = -value;
  }
  return format_unsigned_number(buffer, buffer_size, value, base, used);
}

//------------------------------------------------------------------------------
//  C L A S S   P U B L I C   M E T H O D S
//------------------------------------------------------------------------------

size_t Print::print(int value, int base) {
  char buffer[16];
  size_t len;

  len = format_signed_number(buffer, sizeof buffer, value, base);

  if (len < sizeof buffer) {
    print(buffer);
  } else {
    char *big_buffer = static_cast<char *>(malloc(len + 1));
    if (big_buffer != nullptr) {
      format_signed_number(big_buffer, len + 1, value, base);
      print(big_buffer);
      free(big_buffer);
    }
  }
  return len;
}

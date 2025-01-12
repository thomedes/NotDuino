#ifndef NOTDUINO__WSTRING_H__
#define NOTDUINO__WSTRING_H__

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

class __FlashStringHelper;

class String {
private:
  char buffer[1];
public:
  const char* c_str() const { return buffer; }
  size_t length() const { return 0; }
};

#endif // NOTDUINO__WSTRING_H__

#ifndef NOTDUINO__PRINTABLE_H__
#define NOTDUINO__PRINTABLE_H__

#include <stdlib.h>

class Print;

class Printable
{
  public:
    virtual size_t printTo(Print& p) const = 0;
};

#endif // NOTDUINO__PRINTABLE_H__

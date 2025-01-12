/*
  NotDuino.h - Main include file for the NotDuino library.
  Copyright (c) 2025 Toni Homedes i Saun.  All right reserved.

  NOTICE:

  Parts of this file are based on (copied from) the Arduino SDK, which is
  licensed under the GNU Lesser General Public License.
*/
#ifndef NOTDUINO__NOTDUINO_H__
#define NOTDUINO__NOTDUINO_H__

#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

// Named constants

enum { LOW, HIGH };
enum { INPUT, OUTPUT, INPUT_PULLUP };
enum { SERIAL, DISPLAY };
enum { LSBFIRST, MSBFIRST };
enum { CHANGE = 1, FALLING, RISING };

// Math constants

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

inline uint8_t lowByte(uint16_t w) { return w & 0xff; }
inline uint8_t highByte(uint16_t w) { return w >> 8; }

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

typedef uint8_t byte;

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);

void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
// #include "WCharacter.h"
// #include "WString.h"
#include "HardwareSerial.h"
// #include "USBAPI.h"
// #if defined(HAVE_HWSERIAL0) && defined(HAVE_CDCSERIAL)
// #error "Targets with both UART0 and CDC serial not supported"
// #endif

inline uint16_t makeWord(uint16_t w) { return w; }
inline uint16_t makeWord(byte high, byte low) { return (high << 8) | low; }

#define word(...) makeWord(__VA_ARGS__)

#endif // __cplusplus

#include "pins_arduino.h"

#endif // NOTDUINO__NOTDUINO_H__

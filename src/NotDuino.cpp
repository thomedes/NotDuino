#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <windows.h>
#include <synchapi.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

#include "NotDuino.h"

#include <HardwareSerial_private.h>

/*----------------------------------------------------------------------------*\
    S T A T I C   G L O B A L S
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
    P U B L I C   F U N C T I O N S
\*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

long unsigned int millis(void) {
  return 0;
}

void delay(unsigned long ms) {
#if defined(__unix__) || defined(__APPLE__)
  usleep(ms * 1000);
#elif defined(__windows__)
  Sleep(ms);
#else
#error "Unsupported platform"
#endif
}

void pinMode(uint8_t pin, uint8_t mode) {}
void digitalWrite(uint8_t pin, uint8_t value) {}

void __attribute__((weak)) setup(void) {}
void __attribute__((weak)) loop(void) {}

#ifdef __cplusplus
} // extern "C"
#endif

__attribute__((weak))
int main(void) {
  setup();
  for (;;) {
    loop();
  }
  return 0;
}

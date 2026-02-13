#include "variant.h"

#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
                                      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
                                      32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
                                      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 };

void initVariant() {
  // Disable reading of the BAT voltage.
  // https://wiki.seeedstudio.com/XIAO_BLE#q3-what-are-the-considerations-when-using-xiao-nrf52840-sense-for-battery-charging
  pinMode(VBAT_ENABLE, OUTPUT);
  // digitalWrite(VBAT_ENABLE, HIGH);
  //  This was taken from Seeed github butis not coherent with the doc,
  //  VBAT_ENABLE should be kept to LOW to protect P0.14, (1500/500)*(4.2-3.3)+3.3 = 3.9V > 3.6V
  //  This induces a 3mA current in the resistors :( but it's better than burning the nrf
  digitalWrite(VBAT_ENABLE, LOW);

  pinMode(PIN_QSPI_CS, OUTPUT);
  digitalWrite(PIN_QSPI_CS, HIGH);

  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, HIGH);
}

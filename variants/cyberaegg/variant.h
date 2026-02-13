#ifndef _CYBERAEGG_NRF52840_H_
#define _CYBERAEGG_NRF52840_H_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO    // Board uses 32khz crystal for LF
// #define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define PINS_COUNT              (64)
#define NUM_DIGITAL_PINS        (64)
#define NUM_ANALOG_INPUTS       (8)
#define NUM_ANALOG_OUTPUTS      (0)

// LEDs
#define PIN_LED                 (LED_RED)
#define LED_PWR                 (PINS_COUNT)
#define PIN_NEOPIXEL            (PINS_COUNT)
#define NEOPIXEL_NUM            (0)

#define LED_BUILTIN             (PIN_LED)

#define LED_RED                 (39)
#define LED_GREEN               (47)
#define LED_BLUE                (2)
#define PIN_STATUS_LED          (LED_BLUE)

#define LED_STATE_ON            (0) // State when LED is on

// Buttons
#define PIN_BUTTON1             (26)

#define VBAT_ENABLE             (7) // Pull low to enable battery voltage reading

// Analog pins
#define PIN_VBAT                (31)

#define BAT_NOT_CHARGING        (40) // LOW when charging

#define AREF_VOLTAGE            (3.0)
#define ADC_MULTIPLIER          (3.0F) // 1M, 512k divider bridge

// Power management boot protection threshold (millivolts)
// Set to 0 to disable boot protection
#define PWRMGT_VOLTAGE_BOOTLOCK 0 // Won't boot below this voltage

// LPCOMP wake configuration (voltage recovery from SYSTEMOFF)
#define PWRMGT_LPCOMP_AIN       7 // AIN7 = P0.31 = PIN_VBAT
// IMPORTANT: The XIAO exposes battery via a resistor divider (ADC_MULTIPLIER = 3.0).
// LPCOMP measures the divided voltage, not the battery voltage directly.
// Vpin = VDD * (REFSEL fraction), and VBAT ≈ Vpin * ADC_MULTIPLIER.
//
// Using 3/8 VDD gives a wake threshold above the boot protection point:
// - If VDD ≈ 3.0V:  VBAT ≈ (3.0 * 3/8) * 3 ≈ 3375mV
// - If VDD ≈ 3.3V:  VBAT ≈ (3.3 * 3/8) * 3 ≈ 3712mV
#define PWRMGT_LPCOMP_REFSEL    2 // 3/8 VDD (~3.38-3.71V)

#define ADC_RESOLUTION          (12)

// Other pins
#define PIN_NFC1                (30)
#define PIN_NFC2                (31)

// Serial interfaces
#define PIN_SERIAL1_RX          (7)
#define PIN_SERIAL1_TX          (6)

// SPI Interfaces
#define SPI_INTERFACES_COUNT    (1) // FIXME define SPI1 pins

#define PIN_SPI_MISO            (3)
#define PIN_SPI_MOSI            (46)
#define PIN_SPI_SCK             (45)

// Lora SPI is on SPI0
#define P_LORA_SCLK             PIN_SPI_SCK
#define P_LORA_MISO             PIN_SPI_MISO
#define P_LORA_MOSI             PIN_SPI_MOSI

#define SX126X_RXEN             (4)

// Wire Interfaces
#define WIRE_INTERFACES_COUNT   (1)

#define PIN_WIRE_SDA            (17) // 4 and 5 are used for the sx1262 !
#define PIN_WIRE_SCL            (16) // use WIRE1_SDA

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// #define PIN_WIRE1_SDA           (17)
// #define PIN_WIRE1_SCL           (16)
// PDM Interfaces

// QSPI Pins
#define PIN_QSPI_SCK           (21)
#define PIN_QSPI_CS            (25)
#define PIN_QSPI_IO0           (20)
#define PIN_QSPI_IO1           (24)
#define PIN_QSPI_IO2           (22)
#define PIN_QSPI_IO3           (23)

// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES (P25Q16H)
#define EXTERNAL_FLASH_USE_QSPI

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif

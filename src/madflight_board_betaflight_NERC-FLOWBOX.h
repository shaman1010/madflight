/*==============================================================================
Generated on: 2024-05-14 03:27:32.085389
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FLOWBOX
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_NERC-FLOWBOX.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-FLOWBOX"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC13
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI1)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  PA6
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PA7
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PA4
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PA1
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   -1
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   -1
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB10,PA0,PB6,PB7}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PA10
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PA9
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  -1
#endif

//GPS: (SERIAL2)
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX    PA3
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PA2
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  -1
#endif

//Battery ADC voltage and current inputs:
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V     -1
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     -1
#endif

const int HW_PIN_OUT[] = HW_PIN_OUT_LIST;

//Include Libraries
#include <Wire.h> //I2C communication
#include <SPI.h> //SPI communication
#include "madflight/hw_STM32/STM32_PWM.h" //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 2
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB1
//#define HW_PIN_LED PC13
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_GYRO_EXTI PA1
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_BEEPER_FREQUENCY 2185
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.3.0 May 20 2021 / 03:37:19 (e0ad71db2) MSP API: 1.44

board_name FLOWBOX
manufacturer_id NERC

# resources
resource BEEPER 1 B01
resource MOTOR 1 B10
resource MOTOR 2 A00
resource MOTOR 3 B06
resource MOTOR 4 B07
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 3 B05
resource FLASH_CS 1 A15
resource GYRO_EXTI 1 A01
resource GYRO_CS 1 A04

# timer
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 5 Channel 3

# feature
feature -AIRMODE
feature RX_SERIAL

# serial
serial 0 64 115200 57600 0 115200

# master

set blackbox_device = SPIFLASH
set beeper_frequency = 2185
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set flash_spi_bus = 3
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800

*/
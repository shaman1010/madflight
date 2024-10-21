/*==============================================================================
Generated on: 2024-10-21 06:47:52.051171
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FF_RACEPIT
Manufacturer ID: FFPV

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_FFPV-FF_RACEPIT.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FFPV-FF_RACEPIT"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "M25P16"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW90FLIP
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PB9
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
  #define HW_PIN_IMU_EXTI  PC4
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
  #define HW_PIN_OUT_LIST {PB0,PB1,PB11,PB10}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PB7
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
  #define HW_PIN_BAT_V     PC2
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PC1
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
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PB7,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,PC15}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {3,PA8,PC9} } // {INDEX,SCL,SDA}

//other pins
//#define HW_PIN_LED PB9
#define HW_PIN_LED_2 PB8
#define HW_PIN_BEEPER PC3
#define HW_PIN_PINIO PC0
#define HW_PIN_PINIO_2 PC8
#define HW_PIN_CAMERA_CONTROL PA10
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_OSD_CS PB12
#define HW_PIN_LED_STRIP PB6
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ESCSERIAL PB0

//set statements
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_I2C3_PULLUP ON
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90FLIP
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DSHOT_BURST ON
#define HW_SET_MOTOR_PWM_PROTOCOL Dshot600
#define HW_SET_PINIO_CONFIG 1,129,1,1
#define HW_SET_PINIO_BOX 40,41,255,255
#define HW_SET_TLM_HALFDUPLEX OFF
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_ADC_DEVICE 2
#define HW_SET_BATTERY_METER ADC
#define HW_SET_CURRENT_METER ADC


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.0.0 Mar  2 2019 / 07:01:01 (29db27584) MSP API: 1.4

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

board_name FF_RACEPIT
manufacturer_id FFPV

defaults nosave

# Basic I/O
resource LED 1 B09
resource LED 2 B08
resource BEEPER 1 C03
set beeper_inversion = ON
set beeper_od = OFF
resource PINIO 1 C00
resource PINIO 2 C08
resource CAMERA_CONTROL 1 A10

# Buses
resource I2C_SCL 3 A08
resource I2C_SDA 3 C09
set i2c3_pullup = ON

resource SPI_SCK 1 A05
resource SPI_MISO 1 A06
resource SPI_MOSI 1 A07

resource SPI_SCK 2 B13
resource SPI_MISO 2 B14
resource SPI_MOSI 2 B15

resource SPI_SCK 3 B03
resource SPI_MISO 3 B04
resource SPI_MOSI 3 B05

# Acc/gyro
resource GYRO_CS 1 A04
resource GYRO_EXTI 1 C04
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90FLIP

# SPI Flash
set flash_spi_bus = 3
resource FLASH_CS 1 A15

# OSD
resource OSD_CS 1 B12
set max7456_spi_bus = 2

# Timers
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 B11
resource MOTOR 4 B10
resource LED_STRIP 1 B06

# DMA
dma ADC 2 1      # ADC 2:   DMA2 Stream 3 Channel 1
dma pin B06 0    # pin B06: DMA1 Stream 0 Channel 2 
dma pin B00 0    # pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0    # pin B01: DMA1 Stream 2 Channel 5
dma pin B10 0    # pin B10: DMA1 Stream 1 Channel 3
dma pin B11 1    # pin B11: DMA1 Stream 7 Channel 3

set dshot_burst = ON
set motor_pwm_protocol = Dshot600

# Serial ports
resource SERIAL_TX 1 A09
resource SERIAL_RX 1 B07

resource SERIAL_TX 2 A02
resource SERIAL_RX 2 A03

resource SERIAL_TX 3 C10
resource SERIAL_RX 3 C11
resource INVERTER 3 C15

resource SERIAL_TX 4 A00
resource SERIAL_RX 4 A01

resource SERIAL_TX 5 C12
resource SERIAL_RX 5 D02

resource SERIAL_TX 6 C06
resource SERIAL_RX 6 C07

# ADC
resource ADC_BATT 1 C02
resource ADC_CURR 1 C01

# Remaining
resource ESCSERIAL 1 B00

# Some configs
feature RX_SERIAL
feature OSD
serial 0 0 115200 57600 0 115200
serial 1 0 115200 57600 0 115200
serial 2 64 115200 57600 0 115200
serial 3 0 115200 57600 0 115200
serial 4 0 115200 57600 0 115200
serial 5 0 115200 57600 0 115200
set pinio_config = 1,129,1,1
set pinio_box = 40,41,255,255
set tlm_halfduplex = OFF
set blackbox_device = SPIFLASH
set adc_device = 2
set battery_meter = ADC
set current_meter = ADC

*/

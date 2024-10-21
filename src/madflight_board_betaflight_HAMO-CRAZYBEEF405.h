/*==============================================================================
Generated on: 2024-10-21 06:47:52.504686
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: CRAZYBEEF405
Manufacturer ID: HAMO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_HAMO-CRAZYBEEF405.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HAMO-CRAZYBEEF405"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define IMU_USE  IMU_USE_SPI_MPU6000
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PB5
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

//BARO/MAG I2C: (I2C2)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB10
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB11
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB0,PB1,PC9,PC8}
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
  #define HW_PIN_GPS_INVERTER  PC13
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
#define HW_SERIAL_COUNT 3
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,PC13}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_PPM PB8
#define HW_PIN_PWM PB8
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB5
#define HW_PIN_ESCSERIAL PB8
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PC5
#define HW_PIN_pulldown PB8

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 2
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.2.0 Dec  3 2019 / 01:50:56 (054bd66bc4) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_MAX7456

board_name CRAZYBEEF405
manufacturer_id HAMO

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 C09
resource MOTOR 4 C08
resource PPM 1 B08
resource PWM 1 B08
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 6 C07
resource INVERTER 2 C13
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 B05
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B08
resource ADC_BATT 1 C02
resource ADC_CURR 1 C01
resource FLASH_CS 1 A15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource USB_DETECT 1 C05
# this enables non-inverted serial receivers on the SUMD/DSM2 pin
resource pulldown 1 B08

# timer
timer B08 AF3
# pin B08: TIM10 CH1 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B11 0
# pin B11: DMA1 Stream 7 Channel 3

# feature
feature OSD

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 2
set blackbox_device = SPIFLASH
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800

*/

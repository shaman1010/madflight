/*==============================================================================
Generated on: 2023-12-28 16:40:48.372177
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FENIX_F405
Manufacturer ID: FOSS

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FOSS-FENIX_F405.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FOSS-FENIX_F405"
#define HW_MCU "STM32F405"

//Defines from betaflight (not all will be used by madflight, and some boards define two or more IMU/MAG/BARO - madflight does not support this)
#define USE_IMU_SPI_MPU6000
#define USE_FLASH_W25M512
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW0FLIP
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PA8;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI3)
const int HW_PIN_SPI_MISO = PC11;
const int HW_PIN_SPI_MOSI = PC12;
const int HW_PIN_SPI_SCLK = PC10;
const int HW_PIN_IMU_CS   = PB3;
const int HW_PIN_IMU_EXTI = PB6;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[HW_OUT_COUNT] = {PB1,PB0,PA3,PA2};

//RC Receiver: (SERIAL3)
const int HW_PIN_RCIN_RX  = PB11;
const int HW_PIN_RCIN_TX  = PB10;

//GPS: (SERIAL1)
const int HW_PIN_GPS_RX   = PA10;
const int HW_PIN_GPS_TX   = PA9;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC4;
const int HW_PIN_BAT_I    = PA1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "src/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.3.0 Dec 27 2020 / 20:40:55 (32373e3e0) MSP API: 1.44

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25M512
#define USE_MAX7456

board_name FENIX_F405
manufacturer_id FOSS

# resources
resource MOTOR 1 B01
resource MOTOR 2 B00
resource MOTOR 3 A03
resource MOTOR 4 A02
resource LED_STRIP 1 C08
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 6 C07
resource LED 1 A08
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ADC_BATT 1 C04
resource ADC_CURR 1 A01
resource FLASH_CS 1 B12
resource OSD_CS 1 A04
resource GYRO_EXTI 1 B06
resource GYRO_CS 1 B03

# timer
timer B01 AF1
# pin B01: TIM1 CH3N (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B01 0
# pin B01: DMA2 Stream 6 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7

# feature
feature RX_SERIAL
feature OSD
feature LED_STRIP

# serial
serial 5 64 115200 57600 0 115200

# master
set serialrx_provider = CRSF
set dshot_bitbang = OFF
set motor_pwm_protocol = DSHOT300
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 270
set system_hse_mhz = 8
set max7456_spi_bus = 1
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 3
set gyro_1_sensor_align = CW0FLIP
set gyro_1_align_pitch = 1800

*/
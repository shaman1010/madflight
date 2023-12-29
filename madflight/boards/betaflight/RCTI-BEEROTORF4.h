/*==============================================================================
Generated on: 2023-12-29 16:14:55.469339
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: BEEROTORF4
Manufacturer ID: RCTI

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/RCTI-BEEROTORF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-RCTI-BEEROTORF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_ICM20689
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PB4;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PA8;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB6;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PB0,PB1,PA1,PA0,PC6,PC7,PB5,PB9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = PC15;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC0;
const int HW_PIN_BAT_I    = PC1;

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

//Serial
#define HW_SERIAL_COUNT 3
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,PC15}, {3,PB10,PB11,PC14} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB6,PB7} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PB0,PB1,PA1,PA0,PC6,PC7,PB5,PB9}

//other pins
#define HW_PIN_BEEPER PB3
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PB8
//#define HW_PIN_LED PB4
#define HW_PIN_ESCSERIAL PA3
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_SDCARD_CS PB12
#define HW_PIN_SDCARD_DETECT PC3
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PA8
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PC5

//set statements
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_DSHOT_BURST OFF
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 2
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_2_SPIBUS 1


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.0 May 26 2019 / 13:44:05 (00969f3ba) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_ICM20689
#define USE_ACC
#define USE_ACC_SPI_ICM20689
#define USE_MAX7456
#define USE_SDCARD

board_name BEEROTORF4
manufacturer_id RCTI

# resources
resource BEEPER 1 B03
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A01
resource MOTOR 4 A00
resource MOTOR 5 C06
resource MOTOR 6 C07
resource MOTOR 7 B05
resource MOTOR 8 B09
resource PPM 1 A03
resource LED_STRIP 1 B08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource INVERTER 2 C15
resource INVERTER 3 C14
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 1 B04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 A03
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C02
resource ADC_CURR 1 C01
resource SDCARD_CS 1 B12
resource SDCARD_DETECT 1 C03
resource OSD_CS 1 A15
resource GYRO_EXTI 1 A08
resource GYRO_CS 1 A04
resource USB_DETECT 1 C05

# timer
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B00 AF1
# pin B00: TIM1 CH2N (AF1)
timer B01 AF3
# pin B01: TIM8 CH3N (AF3)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer C06 AF2
# pin C06: TIM3 CH1 (AF2)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma SPI_TX 3 0
# SPI_TX 3: DMA1 Stream 5 Channel 0
dma SPI_RX 3 0
# SPI_RX 3: DMA1 Stream 0 Channel 0
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin B00 0
# pin B00: DMA2 Stream 6 Channel 0
dma pin B01 1
# pin B01: DMA2 Stream 4 Channel 7
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C06 0
# pin C06: DMA1 Stream 4 Channel 5
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2

# feature
feature OSD

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SDCARD
set dshot_burst = OFF
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set system_hse_mhz = 8
set max7456_spi_bus = 3
set dashboard_i2c_bus = 1
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_2_spibus = 1

*/

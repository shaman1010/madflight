/*==============================================================================
Generated on: 2023-12-29 16:14:55.416620
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: KROOZX
Manufacturer ID: LEGA

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/LEGA-KROOZX.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-LEGA-KROOZX"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6000
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW90
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PA14;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PB2;
const int HW_PIN_IMU_EXTI = PNONE;

//BARO/MAG I2C: (I2C3)
const int HW_PIN_I2C_SDA  = PA8;
const int HW_PIN_I2C_SCL  = PC9;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PA2,PA3,PA0,PA1,PB1,PB0,PB8,PB9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = PB13;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC3;
const int HW_PIN_BAT_I    = PC2;

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
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,PB13}, {3,PB10,PB11,-1}, {4,PC10,PC11,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,PB12} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 2
#define HW_PIN_I2C { {1,PB6,PB7}, {3,PA8,PC9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PA2,PA3,PA0,PA1,PB1,PB0,PB8,PB9}

//other pins
#define HW_PIN_BEEPER PC1
#define HW_PIN_PPM PC7
#define HW_PIN_LED_STRIP PC6
//#define HW_PIN_LED PA14
#define HW_PIN_LED_2 PA13
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC0
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_SDCARD_CS PA15
#define HW_PIN_SDCARD_DETECT PC13
#define HW_PIN_PINIO PC5
#define HW_PIN_OSD_CS PC4
#define HW_PIN_GYRO_EXTI PNONE
#define HW_PIN_GYRO_CS PB2

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 3
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 1000
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 3
#define HW_SET_SYSTEM_HSE_MHZ 16
#define HW_SET_MAX7456_SPI_BUS 1
#define HW_SET_DASHBOARD_I2C_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90
#define HW_SET_GYRO_1_ALIGN_YAW 900


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.2.0 Mar 11 2020 / 03:01:30 (norevision) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_MAX7456
#define USE_SDCARD

board_name KROOZX
manufacturer_id LEGA

# resources
resource BEEPER 1 C01
resource MOTOR 1 A02
resource MOTOR 2 A03
resource MOTOR 3 A00
resource MOTOR 4 A01
resource MOTOR 5 B01
resource MOTOR 6 B00
resource MOTOR 7 B08
resource MOTOR 8 B09
resource PPM 1 C07
resource LED_STRIP 1 C06
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 C10
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 C11
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource INVERTER 1 B13
resource INVERTER 6 B12
resource I2C_SCL 1 B06
resource I2C_SCL 3 A08
resource I2C_SDA 1 B07
resource I2C_SDA 3 C09
resource LED 1 A14
resource LED 2 A13
resource SPI_SCK 1 A05
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 3 B05
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C00
resource ADC_CURR 1 C02
resource SDCARD_CS 1 A15
resource SDCARD_DETECT 1 C13
resource PINIO 1 C05
resource OSD_CS 1 C04
# Disabling GYRO_EXTI since gyro and OSD are on same SPI bus
# resource GYRO_EXTI 1 A04
resource GYRO_EXTI 1 NONE
resource GYRO_CS 1 B02

# timer
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)

# dma
dma SPI_TX 3 0
# SPI_TX 3: DMA1 Stream 5 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0

# feature
feature OSD

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 3
set blackbox_device = SDCARD
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 1000
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set system_hse_mhz = 16
set max7456_spi_bus = 1
set dashboard_i2c_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900

*/

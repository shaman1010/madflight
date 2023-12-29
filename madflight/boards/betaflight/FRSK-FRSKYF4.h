/*==============================================================================
Generated on: 2023-12-29 16:14:55.320364
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FRSKYF4
Manufacturer ID: FRSK

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FRSK-FRSKYF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FRSK-FRSKYF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6000
#define USE_BARO_SPI_BMP280
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PB5;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[]    = {PB0,PB1,PA3,PA2,PA1,PA8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC2;
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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {3,PB10,PB11,-1}, {6,PC6,PC7,PC8} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 6
#define HW_MOTOR_OUT {PB0,PB1,PA3,PA2,PA1,PA8}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_PPM PB8
#define HW_PIN_PWM PB8
#define HW_PIN_PWM_2 PB9
#define HW_PIN_PWM_3 PC6
#define HW_PIN_PWM_4 PC7
#define HW_PIN_PWM_5 PC8
#define HW_PIN_PWM_6 PC9
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB5
#define HW_PIN_ESCSERIAL PB8
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_BARO_CS PB3
#define HW_PIN_SDCARD_CS PB12
#define HW_PIN_SDCARD_DETECT PB7
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PC5

//set statements
#define HW_SET_BARO_SPI_DEVICE 3
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 2
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_1_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.2.0 Dec  6 2019 / 00:42:14 (b18478f43e) MSP API: 1.43

#mcu STM32F405

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_SPI_BMP280
#define USE_MAX7456
#define USE_SDCARD

board_name FRSKYF4
manufacturer_id FRSK

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A03
resource MOTOR 4 A02
resource MOTOR 5 A01
resource MOTOR 6 A08
resource PPM 1 B08
resource PWM 1 B08
resource PWM 2 B09
resource PWM 3 C06
resource PWM 4 C07
resource PWM 5 C08
resource PWM 6 C09
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 6 C07
resource INVERTER 6 C08
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
resource BARO_CS 1 B03
resource SDCARD_CS 1 B12
resource SDCARD_DETECT 1 B07
resource OSD_CS 1 A15
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource USB_DETECT 1 C05

# timer
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2

# feature
feature RX_SERIAL
feature TELEMETRY

# serial
serial 0 64 115200 57600 0 115200
serial 5 32 115200 57600 0 115200

# master
set baro_spi_device = 3
set serialrx_provider = SBUS
set blackbox_device = SDCARD
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set system_hse_mhz = 8
set max7456_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700

*/

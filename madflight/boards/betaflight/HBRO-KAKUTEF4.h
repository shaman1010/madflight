/*==============================================================================
Generated on: 2023-12-29 16:14:55.352732
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: KAKUTEF4
Manufacturer ID: HBRO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/HBRO-KAKUTEF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HBRO-KAKUTEF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6000
#define USE_IMU_SPI_ICM20689
#define USE_BARO_BMP280
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

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
const int HW_PIN_IMU_CS   = PC4;
const int HW_PIN_IMU_EXTI = PC5;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[]    = {PB0,PB1,PA3,PA2,PA0,PC8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = PB15;

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
#define HW_SERIAL_COUNT 3
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {3,PB10,PB11,PB15}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 6
#define HW_MOTOR_OUT {PB0,PB1,PA3,PA2,PA0,PC8}

//other pins
#define HW_PIN_BEEPER PC9
#define HW_PIN_PPM PC7
#define HW_PIN_LED_STRIP PA1
//#define HW_PIN_LED PB5
#define HW_PIN_LED_2 PB4
#define HW_PIN_LED_3 PB6
#define HW_PIN_ESCSERIAL PC7
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC1
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_FLASH_CS PB3
#define HW_PIN_OSD_CS PB14
#define HW_PIN_GYRO_EXTI PC5
#define HW_PIN_GYRO_CS PC4
#define HW_PIN_USB_DETECT PA8

//set statements
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 275
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_MAX7456_PREINIT_OPU ON
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_1_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.0 Oct 16 2019 / 11:57:16 (c37a7c91a) MSP API: 1.42

#mcu STM32F405
#wiki https://betaflight.com/docs/wiki/boards/KAKUTEF4

#define USE_ACC
#define USE_ACC_SPI_MPU6000                               
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM20689
#define USE_ACC_SPI_ICM20689
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name KAKUTEF4
manufacturer_id HBRO

# resources
resource BEEPER 1 C09
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A03
resource MOTOR 4 A02
resource MOTOR 5 A00
resource MOTOR 6 C08
resource PPM 1 C07
resource LED_STRIP 1 A01
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 6 C07
resource INVERTER 3 B15
resource LED 1 B05
resource LED 2 B04
resource LED 3 B06
resource SPI_SCK 1 A05
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 C07
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C01
resource ADC_CURR 1 C02
resource FLASH_CS 1 B03
resource OSD_CS 1 B14
resource GYRO_EXTI 1 C05
resource GYRO_CS 1 C04
resource USB_DETECT 1 A08

# timer
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6

# feature
feature RX_SERIAL
feature OSD

# serial
serial 2 64 115200 57600 0 115200

# master
set serialrx_provider = SBUS
set battery_meter = ADC
set ibata_scale = 275
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 3
set max7456_preinit_opu = ON
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700

*/

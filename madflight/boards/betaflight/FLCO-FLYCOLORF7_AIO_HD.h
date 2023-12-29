/*==============================================================================
Generated on: 2023-12-29 16:14:55.282438
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FLYCOLORF7_AIO_HD
Manufacturer ID: FLCO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FLCO-FLYCOLORF7_AIO_HD.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FLCO-FLYCOLORF7_AIO_HD"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6500
#define USE_FLASH_W25Q128FV
#define USE_BARO_BMP280
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PB2;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C2)
const int HW_PIN_I2C_SDA  = PB10;
const int HW_PIN_I2C_SCL  = PB11;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PC6,PC7,PB0,PB1,PB6,PB8,PB7,PC9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC1;
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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PC6,PC7,PB0,PB1,PB6,PB8,PB7,PC9}

//other pins
#define HW_PIN_BEEPER PC13
#define HW_PIN_PPM PA15
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PB2
#define HW_PIN_CAMERA_CONTROL PB9
#define HW_PIN_ADC_BATT PC1
#define HW_PIN_ADC_RSSI PC3
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_BARO_CS PC15
#define HW_PIN_FLASH_CS PC8
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_PINIO PC14

//set statements
#define HW_SET_PID_PROCESS_DENOM 2
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_SPI_DEVICE 3
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_ALIGN_BOARD_YAW -45
#define HW_SET_PINIO_BOX 40,255,255,255


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.0 Aug 28 2019 / 06:11:37 (4f923e482) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_BARO
#define USE_BARO_BMP280
#define USE_MAX7456

board_name FLYCOLORF7_AIO_HD
manufacturer_id FLCO

# resources
resource BEEPER 1 C13
resource MOTOR 1 C06
resource MOTOR 2 C07
resource MOTOR 3 B00
resource MOTOR 4 B01
resource MOTOR 5 B06
resource MOTOR 6 B08
resource MOTOR 7 B07
resource MOTOR 8 C09
resource PPM 1 A15
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 C10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 C11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 B02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 B09
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C03
resource ADC_CURR 1 C02
resource BARO_CS 1 C15
resource FLASH_CS 1 C08
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource PINIO 1 C14

# timer
timer C06 AF2
# pin C06: TIM3 CH1 (AF2)
timer C07 AF2
# pin C07: TIM3 CH2 (AF2)
timer B00 AF3
# pin B00: TIM8 CH2N (AF3)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer B09 AF3
# pin B09: TIM11 CH1 (AF3)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin C06 0
# pin C06: DMA1 Stream 4 Channel 5
dma pin C07 0
# pin C07: DMA1 Stream 5 Channel 5
dma pin B00 0
# pin B00: DMA2 Stream 2 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7

# feature
feature RX_SERIAL
feature LED_STRIP
feature OSD

# serial
serial 20 1 115200 57600 0 115200
serial 0 64 115200 57600 0 115200

# master
set pid_process_denom = 2
set serialrx_provider = SBUS
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_spi_device = 3
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set align_board_yaw = -45
set pinio_box = 40,255,255,255

*/

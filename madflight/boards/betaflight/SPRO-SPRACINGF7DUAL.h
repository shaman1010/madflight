/*==============================================================================
Generated on: 2023-12-29 16:14:55.512003
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: SPRACINGF7DUAL
Manufacturer ID: SPRO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/SPRO-SPRACINGF7DUAL.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-SPRO-SPRACINGF7DUAL"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6500
#define USE_MAX7456
#define USE_SDCARD

//Sensor specific setup
#define IMU_ROTATE_CW0
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC4;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA15;
const int HW_PIN_IMU_EXTI = PC13;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PC8,PC6,PC9,PC7,PB6,PB7,PB1,PB0};

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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PC10,PC11,-1}, {5,PC12,PD2,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PC8,PC6,PC9,PC7,PB6,PB7,PB1,PB0}

//other pins
#define HW_PIN_BEEPER PC15
#define HW_PIN_SERVO PA9
#define HW_PIN_SERVO_2 PA10
#define HW_PIN_PPM PA3
#define HW_PIN_PWM PA3
#define HW_PIN_PWM_2 PA2
#define HW_PIN_PWM_3 PA9
#define HW_PIN_PWM_4 PA10
#define HW_PIN_LED_STRIP PA1
//#define HW_PIN_LED PC4
#define HW_PIN_TRANSPONDER PA8
#define HW_PIN_CAMERA_CONTROL PA0
#define HW_PIN_ADC_BATT PC1
#define HW_PIN_ADC_RSSI PC0
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_SDCARD_CS PC3
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC13
#define HW_PIN_GYRO_EXTI_2 PC14
#define HW_PIN_GYRO_CS PA15
#define HW_PIN_GYRO_CS_2 PB2
#define HW_PIN_VTX_POWER PB7
#define HW_PIN_VTX_CS PB6
#define HW_PIN_VTX_DATA PB0
#define HW_PIN_VTX_CLK PB1

//set statements
#define HW_SET_GYRO_TO_USE BOTH
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_ADC_DEVICE 3
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_DSHOT_BURST ON
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 300
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 3
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0
#define HW_SET_GYRO_2_SPIBUS 1
#define HW_SET_GYRO_2_SENSOR_ALIGN CW270


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.0 Jul  3 2019 / 00:11:51 (095b2e543) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_MAX7456
#define USE_SDCARD

board_name SPRACINGF7DUAL
manufacturer_id SPRO

# resources
resource BEEPER 1 C15
resource MOTOR 1 C08
resource MOTOR 2 C06
resource MOTOR 3 C09
resource MOTOR 4 C07
resource MOTOR 5 B06
resource MOTOR 6 B07
resource MOTOR 7 B01
resource MOTOR 8 B00
resource SERVO 1 A09
resource SERVO 2 A10
resource PPM 1 A03
resource PWM 1 A03
resource PWM 2 A02
resource PWM 3 A09
resource PWM 4 A10
resource LED_STRIP 1 A01
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 C10
resource SERIAL_TX 5 C12
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 C11
resource SERIAL_RX 5 D02
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C04
resource TRANSPONDER 1 A08
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 A00
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C00
resource ADC_CURR 1 C02
resource SDCARD_CS 1 C03
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C13
resource GYRO_EXTI 2 C14
resource GYRO_CS 1 A15
resource GYRO_CS 2 B02
resource VTX_POWER 1 B07
resource VTX_CS 1 B06
resource VTX_DATA 1 B00
resource VTX_CLK 1 B01

# timer
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)

# dma
dma SPI_TX 3 1
# SPI_TX 3: DMA1 Stream 7 Channel 0
dma ADC 3 0
# ADC 3: DMA2 Stream 0 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin C07 1
# pin C07: DMA2 Stream 3 Channel 7
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B11 0
# pin B11: DMA1 Stream 7 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin A09 1
# pin A09: DMA2 Stream 2 Channel 6
dma pin A10 1
# pin A10: DMA2 Stream 6 Channel 6

# feature
feature OSD

# master
set gyro_to_use = BOTH
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set adc_device = 3
set blackbox_device = SDCARD
set dshot_burst = ON
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 300
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set max7456_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW270

*/

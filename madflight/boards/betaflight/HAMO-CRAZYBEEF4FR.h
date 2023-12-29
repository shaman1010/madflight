/*==============================================================================
Generated on: 2023-12-29 16:14:55.339672
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: CRAZYBEEF4FR
Manufacturer ID: HAMO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/HAMO-CRAZYBEEF4FR.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HAMO-CRAZYBEEF4FR"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6000
#define USE_IMU_SPI_ICM20689
#define USE_IMU_SPI_ICM42688P
#define USE_RX_CC2500
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW90
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PA1;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB10,PB6,PB7,PB8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PB0;
const int HW_PIN_BAT_I    = PB1;

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
#define HW_SERIAL_COUNT 2
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB10,PB6,PB7,PB8}

//other pins
#define HW_PIN_BEEPER PC15
#define HW_PIN_PPM PA3
#define HW_PIN_PWM PA2
#define HW_PIN_PWM_2 PA9
#define HW_PIN_PWM_3 PA10
#define HW_PIN_LED_STRIP PA0
//#define HW_PIN_LED PC13
#define HW_PIN_ADC_BATT PB0
#define HW_PIN_ADC_CURR PB1
#define HW_PIN_OSD_CS PB12
#define HW_PIN_RX_SPI_CS PA15
#define HW_PIN_RX_SPI_EXTI PC14
#define HW_PIN_RX_SPI_BIND PB2
#define HW_PIN_RX_SPI_LED PB9
#define HW_PIN_GYRO_EXTI PA1
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_DSHOT_BURST AUTO
#define HW_SET_DSHOT_BITBANG OFF
#define HW_SET_RX_SPI_PROTOCOL FRSKY_X
#define HW_SET_RX_SPI_BUS 3
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 179
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.1.0 Jul  8 2019 / 00:24:09 (5e6e1af0b) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC_SPI_ICM20689
#define USE_GYRO_SPI_ICM20689
#define USE_ACCGYRO_BMI270
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_RX_CC2500
#define USE_MAX7456

board_name CRAZYBEEF4FR
manufacturer_id HAMO

# resources
resource BEEPER 1 C15
resource MOTOR 1 B10
resource MOTOR 2 B06
resource MOTOR 3 B07
resource MOTOR 4 B08
resource PPM 1 A03
resource PWM 1 A02
resource PWM 2 A09
resource PWM 3 A10
resource LED_STRIP 1 A00
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ADC_BATT 1 B00
resource ADC_CURR 1 B01
resource OSD_CS 1 B12
resource RX_SPI_CS 1 A15
resource RX_SPI_EXTI 1 C14
resource RX_SPI_BIND 1 B02
resource RX_SPI_LED 1 B09
resource GYRO_EXTI 1 A01
resource GYRO_CS 1 A04

# timer
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0

# feature
feature OSD
feature RX_SPI

# master
set dshot_burst = AUTO
set dshot_bitbang = OFF
set rx_spi_protocol = FRSKY_X
set rx_spi_bus = 3
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 179
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90

*/

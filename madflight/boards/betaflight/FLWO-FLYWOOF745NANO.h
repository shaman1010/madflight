/*==============================================================================
Generated on: 2023-12-29 16:14:55.299763
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FLYWOOF745NANO
Manufacturer ID: FLWO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/FLWO-FLYWOOF745NANO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FLWO-FLYWOOF745NANO"
#define HW_MCU "STM32F745"

//Defines from betaflight. Note: madflight will pick the first IMU that is matched in imu.h, this might not be the IMU that is actually on the board. Comment the offending IMU out.
#define USE_IMU_SPI_MPU6000
#define USE_BARO_BMP280
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

//Sensor specific setup
#define IMU_ROTATE_CW270
#define BARO_I2C_ADR 0
#define MAG_I2C_ADR 0

//LED:
const int HW_PIN_LED      = PA2;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI4)
const int HW_PIN_SPI_MISO = PE5;
const int HW_PIN_SPI_MOSI = PE6;
const int HW_PIN_SPI_SCLK = PE2;
const int HW_PIN_IMU_CS   = PE4;
const int HW_PIN_IMU_EXTI = PE1;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB6;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PB0,PB1,PE9,PE11,PC9,PA3,PB4,PB5};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PD6;
const int HW_PIN_GPS_TX   = PD5;
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
#define HW_SERIAL_COUNT 7
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PD5,PD6,-1}, {3,PD8,PD9,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1}, {7,PE8,PE7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {4,PE2,PE5,PE6} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 2
#define HW_PIN_I2C { {1,PB6,PB7}, {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PB0,PB1,PE9,PE11,PC9,PA3,PB4,PB5}

//other pins
#define HW_PIN_BEEPER PD15
#define HW_PIN_PPM PE13
#define HW_PIN_LED_STRIP PD12
//#define HW_PIN_LED PA2
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_PINIO PC0
#define HW_PIN_FLASH_CS PA4
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PE1
#define HW_PIN_GYRO_CS PE4
#define HW_PIN_USB_DETECT PA8

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BARO_HARDWARE BMP280
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_IBATA_SCALE 175
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_FLASH_SPI_BUS 1
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 4
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F745 (S745) 4.2.0 Jun 14 2020 / 03:05:04 (8f2d21460) MSP API: 1.43
#mcu STM32F745

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name FLYWOOF745NANO
manufacturer_id FLWO

# resources
resource BEEPER 1 D15
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 E09
resource MOTOR 4 E11
resource MOTOR 5 C09
resource MOTOR 6 A03
resource MOTOR 7 B04
resource MOTOR 8 B05
resource PPM 1 E13
resource LED_STRIP 1 D12
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 E08
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 A02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 4 E02
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 4 E05
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 4 E06
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C02
resource PINIO 1 C00
resource FLASH_CS 1 A04
resource OSD_CS 1 B12
resource GYRO_EXTI 1 E01
resource GYRO_CS 1 E04
resource USB_DETECT 1 A08

# timer
timer E13 AF1
# pin E13: TIM1 CH3 (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer E09 AF1
# pin E09: TIM1 CH1 (AF1)
timer E11 AF1
# pin E11: TIM1 CH2 (AF1)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin E13 1
# pin E13: DMA2 Stream 6 Channel 6
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin E09 2
# pin E09: DMA2 Stream 3 Channel 6
dma pin E11 1
# pin E11: DMA2 Stream 2 Channel 6
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin D12 0
# pin D12: DMA1 Stream 0 Channel 2

# feature
feature RX_SERIAL
feature LED_STRIP
feature OSD

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set baro_hardware = BMP280
set blackbox_device = SPIFLASH
set current_meter = ADC
set ibata_scale = 175
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set dashboard_i2c_bus = 1
set flash_spi_bus = 1
set gyro_1_bustype = SPI
set gyro_1_spibus = 4
set gyro_1_sensor_align = CW270

*/

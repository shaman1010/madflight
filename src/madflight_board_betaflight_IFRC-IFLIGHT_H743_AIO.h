/*==============================================================================
Generated on: 2024-10-23 18:06:29.182138
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: IFLIGHT_H743_AIO
Manufacturer ID: IFRC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include <madflight_board_betaflight_IFRC-IFLIGHT_H743_AIO.h>
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-IFRC-IFLIGHT_H743_AIO"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "M25P16"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#define HW_PIN_LED       PC13
#define HW_LED_ON        1 //0:low is on, 1:high is on

//IMU SPI: (SPI1)
#define HW_PIN_SPI_MISO  PA6
#define HW_PIN_SPI_MOSI  PA7
#define HW_PIN_SPI_SCLK  PA5
#define HW_PIN_IMU_CS    PA4
#define HW_PIN_IMU_EXTI  PD0

//BARO/MAG I2C: (I2C1)
#define HW_PIN_I2C_SDA   PB8
#define HW_PIN_I2C_SCL   PB9

//Outputs:
#define HW_OUT_COUNT     4
#define HW_PIN_OUT_LIST  {PB0,PB1,PE9,PE11}

//RC Receiver: (SERIAL1)
#define HW_PIN_RCIN_RX   PA10
#define HW_PIN_RCIN_TX   PA9
#define HW_PIN_RCIN_INVERTER  -1

//GPS: (SERIAL2)
#define HW_PIN_GPS_RX    PA3
#define HW_PIN_GPS_TX    PA2
#define HW_PIN_GPS_INVERTER  -1

//Battery ADC voltage and current inputs:
#define HW_PIN_BAT_V     PC3
#define HW_PIN_BAT_I     PC2

//-------------------------------------

//Serial
#define HW_SERIAL_COUNT 7
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {6,PC6,PC7,-1}, {7,PE8,PE7,-1}, {8,PE1,PE0,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 4
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12}, {4,PE2,PE5,PE6} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PD15
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PD12
//#define HW_PIN_LED PC13
#define HW_PIN_CAMERA_CONTROL PC8
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_OSD_CS PE4
#define HW_PIN_GYRO_EXTI PD0
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_ADC_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 110
#define HW_SET_IBATA_SCALE 200
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_MAX7456_SPI_BUS 4
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / IFLIGHT_H743_AIO (IF7A) 4.2.4 Oct 20 2020 / 08:14:15 (fbcaf8c50) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

board_name IFLIGHT_H743_AIO
manufacturer_id IFRC

# resources
resource BEEPER 1 D15
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 E09
resource MOTOR 4 E11
resource PPM 1 A03
resource LED_STRIP 1 D12
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 E08
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource SERIAL_RX 8 E00
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_SCK 4 E02
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MISO 4 E05
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource SPI_MOSI 4 E06
resource CAMERA_CONTROL 1 C08
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C02
resource FLASH_CS 1 A15
resource OSD_CS 1 E04
resource GYRO_EXTI 1 D00
resource GYRO_CS 1 A04

# timer
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer E09 AF1
# pin E09: TIM1 CH1 (AF1)
timer E11 AF1
# pin E11: TIM1 CH2 (AF1)

# dma
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 3 9
# ADC 3: DMA2 Stream 1 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 2 0
# TIMUP 2: DMA1 Stream 0 Request 22
dma TIMUP 3 0
# TIMUP 3: DMA1 Stream 0 Request 27
dma TIMUP 4 0
# TIMUP 4: DMA1 Stream 0 Request 32
dma TIMUP 8 0
# TIMUP 8: DMA1 Stream 0 Request 51
dma pin D12 10
# pin D12: DMA2 Stream 2 Request 29
dma pin A03 0
# pin A03: DMA1 Stream 0 Request 21
dma pin C08 0
# pin C08: DMA1 Stream 0 Request 49
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 1
# pin B01: DMA1 Stream 1 Request 26
dma pin E09 2
# pin E09: DMA1 Stream 2 Request 11
dma pin E11 3
# pin E11: DMA1 Stream 3 Request 12

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set mag_bustype = I2C
set mag_i2c_device = 1
set adc_device = 1
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 110
set ibata_scale = 200
set beeper_inversion = ON
set max7456_spi_bus = 4
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1

*/
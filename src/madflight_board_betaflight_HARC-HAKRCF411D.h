/*==============================================================================
Generated on: 2024-10-21 06:47:52.582811
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: HAKRCF411D
Manufacturer ID: HARC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_HARC-HAKRCF411D.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HARC-HAKRCF411D"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BARO_USE  BARO_USE_BMP280
#define BARO_USE  BARO_USE_DPS310
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC13
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI1)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  PA6
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PA7
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PA4
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PA1
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB8
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB9
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB4,PB5,PB6,PB7}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PA10
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PA9
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  -1
#endif

//GPS: (SERIAL2)
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX    PA3
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PA2
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  -1
#endif

//Battery ADC voltage and current inputs:
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V     PB0
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PB1
#endif

const int HW_PIN_OUT[] = HW_PIN_OUT_LIST;

//Include Libraries
#include <Wire.h> //I2C communication
#include <SPI.h> //SPI communication
#include "madflight/hw_STM32/STM32_PWM.h" //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 3
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {11,PA15,PB3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB2
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PC13
#define HW_PIN_LED_2 PC14
#define HW_PIN_ADC_BATT PB0
#define HW_PIN_ADC_CURR PB1
#define HW_PIN_PINIO PB10
#define HW_PIN_PINIO_2 PC14
#define HW_PIN_FLASH_CS PA0
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PA1
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PC15

//set statements
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_ADC_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_PINIO_CONFIG 1,1,1,1
#define HW_SET_PINIO_BOX 40,41,255,255
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.2.2 Aug 16 2020 / 01:47:01 (e833ac612) MSP API: 1.43

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name HAKRCF411D
manufacturer_id HARC

# resources
resource BEEPER 1 B02
resource MOTOR 1 B04
resource MOTOR 2 B05
resource MOTOR 3 B06
resource MOTOR 4 B07
resource PPM 1 A03
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_RX 1 A10
resource SERIAL_TX 2 A02
resource SERIAL_RX 2 A03
resource SERIAL_RX 11 B03
resource SERIAL_TX 11 A15
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C13
resource LED 2 C14
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ADC_BATT 1 B00
resource ADC_CURR 1 B01
resource PINIO 1 B10
resource PINIO 2 C14
resource FLASH_CS 1 A00
resource OSD_CS 1 B12
resource GYRO_EXTI 1 A01
resource GYRO_CS 1 A04
resource USB_DETECT 1 C15

# timer
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3

# feature
feature RX_SERIAL
feature TELEMETRY
feature SOFTSERIAL
feature OSD

# serial
serial 20 1 115200 57600 0 115200
serial 0 0 115200 57600 0 115200
serial 1 64 115200 57600 0 115200
serial 30 0 115200 57600 0 115200

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set adc_device = 1
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set mag_bustype = I2C
set mag_i2c_device = 1
set max7456_spi_bus = 2
set pinio_config = 1,1,1,1
set pinio_box = 40,41,255,255
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180

*/

/*==============================================================================
Generated on: 2024-10-21 06:47:52.144907
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: STELLARF4
Manufacturer ID: FLMO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_FLMO-STELLARF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FLMO-STELLARF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "M25P16"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC8
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
  #define HW_PIN_IMU_EXTI  PC4
#endif

//BARO/MAG I2C: (I2C2)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB10
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB11
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     8
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB6,PB7,PB8,PB9,PB0,PB1,PB5,PB4}
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
  #define HW_PIN_BAT_V     PC0
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PC1
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
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PC5
#define HW_PIN_SERVO PA8
#define HW_PIN_SERVO_2 PC9
#define HW_PIN_PPM PA3
//#define HW_PIN_LED PC8
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_SDCARD_CS PA15
#define HW_PIN_PINIO PC3
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 2
#define HW_SET_SERIALRX_PROVIDER CRSF
#define HW_SET_DSHOT_BURST ON
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT300
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 110
#define HW_SET_IBATA_SCALE 386
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_OSD_DISPLAYPORT_DEVICE MAX7456
#define HW_SET_DASHBOARD_I2C_BUS 2
#define HW_SET_PINIO_CONFIG 1,1,1,1
#define HW_SET_PINIO_BOX 40,255,255,255
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_BOX_USER_1_NAME CAMERA


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.4.2 Aug 14 2023 / 20:54:15 (23d066d08) MSP API: 1.45

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

board_name STELLARF4
manufacturer_id FLMO

# resources
resource BEEPER 1 C05
resource MOTOR 1 B06
resource MOTOR 2 B07
resource MOTOR 3 B08
resource MOTOR 4 B09
resource MOTOR 5 B00
resource MOTOR 6 B01
resource MOTOR 7 B05
resource MOTOR 8 B04
resource SERVO 1 A08
resource SERVO 2 C09
resource PPM 1 A03
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 C10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 C11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 C08
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C02
resource ADC_CURR 1 C01
resource SDCARD_CS 1 A15
resource PINIO 1 C03
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04

# timer
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)

# dma
dma SPI_MOSI 2 0
# SPI_MOSI 2: DMA1 Stream 4 Channel 0
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7

# feature
feature RX_SERIAL
feature TELEMETRY
feature OSD

# serial
serial 1 64 115200 57600 0 115200
serial 3 1 115200 57600 0 115200
serial 4 1024 115200 57600 0 115200

# beacon
beacon RX_LOST
beacon RX_SET

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 2
set serialrx_provider = CRSF
set dshot_burst = ON
set motor_pwm_protocol = DSHOT300
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 110
set ibata_scale = 386
set beeper_inversion = ON
set beeper_od = OFF
set blackbox_device = SPIFLASH
set flash_spi_bus = 2
set max7456_spi_bus = 2
set osd_displayport_device = MAX7456
set dashboard_i2c_bus = 2
set pinio_config = 1,1,1,1
set pinio_box = 40,255,255,255
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set box_user_1_name = CAMERA SWITCH

*/

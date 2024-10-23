/*==============================================================================
Generated on: 2024-10-23 18:06:29.034408
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: FLYCOLORF4
Manufacturer ID: FLCO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include <madflight_board_betaflight_FLCO-FLYCOLORF4.h>
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FLCO-FLYCOLORF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6500
#define BARO_USE  BARO_USE_BMP388
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#define HW_PIN_LED       PC15
#define HW_LED_ON        1 //0:low is on, 1:high is on

//IMU SPI: (SPI1)
#define HW_PIN_SPI_MISO  PA6
#define HW_PIN_SPI_MOSI  PA7
#define HW_PIN_SPI_SCLK  PA5
#define HW_PIN_IMU_CS    PA4
#define HW_PIN_IMU_EXTI  PC4

//BARO/MAG I2C: (I2C2)
#define HW_PIN_I2C_SDA   PB10
#define HW_PIN_I2C_SCL   PB11

//Outputs:
#define HW_OUT_COUNT     8
#define HW_PIN_OUT_LIST  {PB6,PB7,PB8,PB9,PB0,PB1,PC8,PA15}

//RC Receiver: (SERIAL1)
#define HW_PIN_RCIN_RX   PA10
#define HW_PIN_RCIN_TX   PA9
#define HW_PIN_RCIN_INVERTER  -1

//GPS: (SERIAL2)
#define HW_PIN_GPS_RX    PA3
#define HW_PIN_GPS_TX    PA2
#define HW_PIN_GPS_INVERTER  -1

//Battery ADC voltage and current inputs:
#define HW_PIN_BAT_V     PC0
#define HW_PIN_BAT_I     PC1

//-------------------------------------

//Serial
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PC2,PC3}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PC14
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PB14
//#define HW_PIN_LED PC15
#define HW_PIN_CAMERA_CONTROL PB15
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_FLASH_CS PC13
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 2
#define HW_SET_ADC_DEVICE 1
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 111
#define HW_SET_IBATA_SCALE 235
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_DSHOT_BURST ON
#define HW_SET_PID_PROCESS_DENOM 2
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.4.3 Fed 20 2024 / 08:45:24 (229ac66) MSP API: 1.44

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_BARO
#define USE_BARO_BMP388
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name FLYCOLORF4
manufacturer_id FLCO

# resource 
resource BEEPER    1 C14
resource MOTOR     1 B06
resource MOTOR     2 B07 
resource MOTOR     3 B08 
resource MOTOR     4 B09
resource MOTOR     5 B00
resource MOTOR     6 B01
resource MOTOR     7 C08
resource MOTOR     8 A15 
resource PPM       1 A03
resource LED_STRIP 1 B14
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
resource I2C_SCL   2 B10
resource I2C_SDA   2 B11
resource LED       1 C15
resource SPI_SCK   1 A05
resource SPI_SCK   2 B13
resource SPI_SCK   3 B03
resource SPI_MISO  1 A06
resource SPI_MISO  2 C02
resource SPI_MISO  3 B04
resource SPI_MOSI  1 A07
resource SPI_MOSI  2 C03
resource SPI_MOSI  3 B05
resource CAMERA_CONTROL 1 B15
resource ADC_BATT  1 C00
resource ADC_RSSI  1 C05
resource ADC_CURR  1 C01
resource FLASH_CS  1 C13
resource OSD_CS    1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS   1 A04

# timer
timer A03 AF2
# pin A03: TIM5 CH4 (AF2) 
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
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer B14 AF1
# pin B14: TIM1 CH2N (AF1)
timer B15 AF9
# pin B15: TIM12 CH2 (AF9)

# dma  
dma ADC 1   0
# ADC 1:   DMA2 Stream 0 Channel 0
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
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
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin B14 1
# pin B14: DMA2 Stream 2 Channel 6

# feature
feature RX_SERIAL
feature LED_STRIP
feature TELEMETRY
feature OSD

# serial
serial 20 1 115200 57600 0 115200
serial 3 64 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 2
set adc_device = 1
set current_meter = ADC
set battery_meter = ADC
set vbat_scale    = 111
set ibata_scale   = 235
set serialrx_provider = SBUS
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set blackbox_device = SPIFLASH
set flash_spi_bus = 3
set dshot_burst = ON
set pid_process_denom = 2
set gyro_1_sensor_align = CW180
set gyro_1_bustype = SPI
set gyro_1_spibus = 1

*/
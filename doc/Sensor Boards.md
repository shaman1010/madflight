# Sensor Boards

An overview of available sensor boards.

* The "Breakout Board?" column lists price if board is cheap & easy to procure.
* Prices in USD from Aliexpress incl shipping.
* Table created Dec 2023

## 6-axis IMU

| Part    | Breakout Board? | Interface | Notes |
|-|-|-|-|
MPU6000   | yes | SPI, I2C | 8k gyro, 1k acc, WHO_AM_I=0x68 6-bit I2C address of the MPU-60X0, Released 2011 (EOL)
MPU6050   | yes | I2C | 8k gyro, 1k acc, WHO_AM_I=0x68 6-bit I2C address of the MPU-60X0, Released 2011 (EOL)
MPU6500   | $2 | SPI, I2C | 8k gyro, 4k acc, Released 2014
BMI160    | $2
BMI180    |
BMI270    | no | SPI | 6k gyro, Used in current commercial FC
LSM6DS3   | $2
LSM6DSO   | $10
MPU3000   | no | | Released 2011 (EOL)
MPU3050   | no | | Released 2011 (EOL)
MPU6886   | no | | Released
ICM20602  | no
ICM20608  | no
ICM20689  | no 
ICM42688P | no | | 32k gyro, Used in current commercial FC

## 9-axis IMU

| Part    | Breakout Board? | Interface | Notes |
|-|-|-|-|
MPU9150  | $7 | I2C | 8k gyro, WHO_AM_I=0x68 or 0x69 depending on AD0 pin, MPU6050 + AK8975, (EOL)
MPU9250  | $7 | SPI 20MHz, I2C | 8k gyro, 4k acc, 100Hz mag, WHO_AM_I=0x71, MPU6500 + AK8963, Released 2014 (EOL) Note: many fake relabelled MPU6500 boards on the market for $4 or less.
MPU9255  | $9 | SPI 20MHz, I2C | 8k gyro, WHO_AM_I=0x73, MPU6000 + AK8963
ICM20948 | $9 | SPI 7MHz, I2C | replacement of MPU-9250/9255, Released 2018
LSM9DSO  | no

## Magnetometer

| Part    | Breakout Board? | Interface | Notes |
|-|-|-|-|
HMC5883L | $2 | I2C | 12-bit ADC, noise 2 ug, resolution 0.73 ug, 160 Hz
AK8963 | | I2C | 100 Hz
AK8975 | | I2C | 100 Hz

## Barometer

| Part    | Breakout Board? | Interface | Notes |
|-|-|-|-|
DPS310    | $3 | SPI, I2C | Relative precision: 6Pa 0.5m, Resolution 0.06Pa, Used in current commercial FC
BMP180    | $2
BMP280    | $2 | | Used in current commercial FC
BMP388    | $8 | SPI, I2C 
MS5611    | $4 | SPI 20MHz, I2C | Resolution RMS: 0.012mbar, 1.2Pa, 10cm @ 100Hz
SPL06-001 | no

## Multi Sensor Modules

| Module | Price | DOF | Sensors |
|-|-|-|-|
GY-85 | | 9DOF | ITG3205 + ADXL345 + HMC5883L
GY-86 | | 10DOF | MPU6050 HMC5883L MS5611
GY-87 | $4 | 10DOF | MPU6050 HMC5883L BMP180
GY-91 | $8 | 10DOF | MPU9250 BMP280
GY-521 | $2 | 6DOF | MPU6050
GY-912 | $11 | 10DOF | ICM20948 BMP388
/**
 @file FaBoMotor_DRV8830.cpp
 @brief This is a library for the FaBo Temperature I2C Brick.

   Released under APACHE LICENSE, VERSION 2.0
   http://www.apache.org/licenses/
 @author FaBo<info@fabo.io>
*/

#include "FaBoMotor_DRV8830.h"

/**
 @brief Constructor
*/
FaBoMotor::FaBoMotor(uint8_t addr) {
  _i2caddr = addr;
  Wire.begin();
}

/**
 @brief Begin Device
*/
boolean FaBoMotor::begin() {
  uint8_t status = 0;
  return readI2c(DRV8830_FAULT_REG, 1, &status);
}

/**
 @brief Configure Device
 @param [in] config Configure Parameter
*/
void FaBoMotor::drive(uint8_t direction, uint8_t speed) {
  uint8_t param = speed << 2 | direction;   
  writeI2c(DRV8830_CONTROL_REG, param);
}

/**
 @brief Write I2C
 @param [in] address register address
 @param [in] data write data
*/
void FaBoMotor::writeI2c(uint8_t address, uint8_t data) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

/**
 @brief Read I2C
 @param [in] address register address
 @param [in] num read length
 @param [out] data read data
*/
boolean FaBoMotor::readI2c(uint8_t address, uint8_t num, uint8_t * data) {
  Wire.beginTransmission(_i2caddr);
  
  boolean result = Wire.write(address);
  Serial.print(result);
  
  Wire.endTransmission();
  uint8_t i = 0;
  Wire.requestFrom(_i2caddr, num);
  while( Wire.available() ) {
    data[i++] = Wire.read();
  }
  return result;
}

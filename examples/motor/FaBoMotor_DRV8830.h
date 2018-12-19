/**
 @file FaBoTemperature_ADT7410.h
 @brief This is a library for the FaBo Temperature I2C Brick.
 
   Released under APACHE LICENSE, VERSION 2.0
   http://www.apache.org/licenses/
 @author FaBo<info@fabo.io>
*/

#ifndef FABOMOTOR_DRV8830_H
#define FABOMOTOR_DRV8830_H

#include <Arduino.h>
#include <Wire.h>

#define DRV8830_SLAVE_ADDRESS 0x64 ///< Default I2C Slave Address

/// @name Register Addresses
/// @{
#define DRV8830_CONTROL_REG 0x00
#define DRV8830_FAULT_REG 0x01
/// @}

/// @name Drive Controller
/// @{
#define DRV8830_STANBY 0b00
#define DRV8830_REVERSE 0b01
#define DRV8830_FORWARD 0b10
#define DRV8830_BRAKE 0b11
/// @}

/// @name Output Voltage
/// @{
#define DRV8830_SPEED_MIN 0x06
#define DRV8830_SPEED_1 0x06
#define DRV8830_SPEED_2 0x07
#define DRV8830_SPEED_3 0x08
#define DRV8830_SPEED_4 0x09
#define DRV8830_SPEED_5 0x0A
#define DRV8830_SPEED_6 0x0B
#define DRV8830_SPEED_7 0x0C
#define DRV8830_SPEED_8 0x0D
#define DRV8830_SPEED_9 0x0E
#define DRV8830_SPEED_10 0x0F
#define DRV8830_SPEED_11 0x10
#define DRV8830_SPEED_12 0x11
#define DRV8830_SPEED_13 0x12
#define DRV8830_SPEED_14 0x13
#define DRV8830_SPEED_15 0x14
#define DRV8830_SPEED_16 0x15
#define DRV8830_SPEED_17 0x16
#define DRV8830_SPEED_18 0x17
#define DRV8830_SPEED_19 0x18
#define DRV8830_SPEED_20 0x19
#define DRV8830_SPEED_21 0x1A
#define DRV8830_SPEED_22 0x1B
#define DRV8830_SPEED_23 0x1C
#define DRV8830_SPEED_24 0x1D
#define DRV8830_SPEED_25 0x1E
#define DRV8830_SPEED_26 0x1F
#define DRV8830_SPEED_27 0x20
#define DRV8830_SPEED_28 0x21
#define DRV8830_SPEED_29 0x22
#define DRV8830_SPEED_30 0x23
#define DRV8830_SPEED_31 0x24
#define DRV8830_SPEED_32 0x25
#define DRV8830_SPEED_33 0x26
#define DRV8830_SPEED_34 0x27
#define DRV8830_SPEED_35 0x28
#define DRV8830_SPEED_36 0x29
#define DRV8830_SPEED_37 0x2A
#define DRV8830_SPEED_38 0x2B
#define DRV8830_SPEED_39 0x2C
#define DRV8830_SPEED_40 0x2D
#define DRV8830_SPEED_41 0x2E
#define DRV8830_SPEED_42 0x2F
#define DRV8830_SPEED_43 0x30
#define DRV8830_SPEED_44 0x31
#define DRV8830_SPEED_45 0x32
#define DRV8830_SPEED_46 0x33
#define DRV8830_SPEED_47 0x34
#define DRV8830_SPEED_48 0x35
#define DRV8830_SPEED_49 0x36
#define DRV8830_SPEED_50 0x37
#define DRV8830_SPEED_51 0x38
#define DRV8830_SPEED_52 0x39
#define DRV8830_SPEED_53 0x3A
#define DRV8830_SPEED_54 0x3B
#define DRV8830_SPEED_55 0x3C
#define DRV8830_SPEED_56 0x3D
#define DRV8830_SPEED_57 0x3E
#define DRV8830_SPEED_58 0x3F
#define DRV8830_SPEED_MAX 0x3F
/// @}

/**
 @class FaBoTemperature
 @brief FaBo Temperature I2C Controll class
*/
class FaBoMotor {
  public:
    FaBoMotor(uint8_t addr = DRV8830_SLAVE_ADDRESS);
    boolean begin(void);
    void drive(uint8_t direction, uint8_t speed);
  private:
    uint8_t _i2caddr;
    void writeI2c(uint8_t address, uint8_t data);
    boolean readI2c(uint8_t address, uint8_t num, uint8_t * data);
};

#endif // FABOMOTOR_DRV8830_H

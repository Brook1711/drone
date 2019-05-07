#ifndef __MYIIC_H
#define __MYIIC_H
#include <stdint.h>
#include <stdbool.h>

#include "I2C.h"

#include "hw_memmap.h"
#include "gpio.h"
#include "pin_map.h"

#include "sysctl.h"

void Init_I2C(void);
void i2cWrite(uint8_t addr, uint8_t regAddr, uint8_t data) ;
uint8_t i2cRead(uint8_t addr, uint8_t regAddr);

void Init_I2C0(void);
void i2c0Write(uint8_t addr, uint8_t regAddr, uint8_t data) ;
uint8_t i2c0Read(uint8_t addr, uint8_t regAddr);


void Single_WriteI2C(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data);
unsigned char Single_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address);
short int Double_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address);
#endif

















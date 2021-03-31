/*
 * mu_vision_sensor_uart_hw_interface.cpp
 *
 *  Created on: 2018年8月8日
 *      Author: ysq
 */

#include "mu_vision_sensor_i2c_hw_interface.h"
#include "DebugTool/morpx_debug_tool.h"

#if MICROBIT_CODAL
#define BUFFER_TYPE uint8_t*
#else
#define BUFFER_TYPE char*
#endif

MuVisionSensorI2C::MuVisionSensorI2C(MuVsI2C* i2c_port, uint32_t address)
    : MuVsI2CMethod(address),
      i2c_port_(i2c_port) {
}

MuVisionSensorI2C::~MuVisionSensorI2C() {}

uint32_t MuVisionSensorI2C::I2CRead(uint8_t reg_address, uint8_t* temp) {
  //Debug Output
#if MORPX_DEBUG_ENABLE && LOG_OUTPUT
  MU_PRINTF("[R:%02x,", reg_address);
#endif
  if (i2c_port_->write(mu_address_<<1, (BUFFER_TYPE)&reg_address, 1) != MICROBIT_OK)
      return MU_FAIL;
  //Debug Output
#if MORPX_DEBUG_ENABLE && LOG_OUTPUT
  MU_PRINTF("%02x],", *temp);
#endif
  if (i2c_port_->read(mu_address_<<1, (BUFFER_TYPE)temp, 1) != MICROBIT_OK)
      return MU_FAIL;
  return MU_OK;
}

uint32_t MuVisionSensorI2C::I2CWrite(uint8_t reg_address, uint8_t value) {
  uint8_t ret = i2c_port_->writeRegister(mu_address_<<1,reg_address,value);
  //Debug Output
#if MORPX_DEBUG_ENABLE && LOG_OUTPUT
  MU_PRINTF("[W:%02x,%02x],",reg_address,value);
#endif
  return ret;
}

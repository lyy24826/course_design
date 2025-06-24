#include "adc_key.h"
#include "hal_adc.h"



uint8 Adc_KeyGetValue(void)
{
  uint16 adc_value = 0;
  uint8 ret = 0;
  adc_value = HalAdcRead(HAL_ADC_CHANNEL_6, HAL_ADC_RESOLUTION_12);
  //0.8V
  if(adc_value>500 && adc_value<600) {
    ret = KEY_UP;
  }
  //1.1V
  if(adc_value>700 && adc_value<800) {
    ret = KEY_DOWN;
  } 
  //3.3V
  if(adc_value>2000 && adc_value<2100) {
    ret = KEY_LEFT;
  }  
  //1.65v
  if(adc_value>1070 && adc_value<1170) {
    ret = KEY_RIGHT;
  } 
  return ret;
}










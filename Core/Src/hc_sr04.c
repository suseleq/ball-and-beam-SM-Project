/*
 * hc_sr04.c
 *
 *  Created on: Dec 23, 2024
 *      Author: Kuba
 */

#include "hc_sr04.h"
#include "main.h"

#define HC_SR04_US_TO_CM_CONVERTER 0.017f

void hc_sr04_init(struct us_sensor_str *us_sensor, TIM_HandleTypeDef *htim_echo, TIM_HandleTypeDef *htim_trig, uint32_t trig_channel)
{
	us_sensor->htim_echo = htim_echo;
		us_sensor->htim_trig = htim_trig;
		us_sensor->trig_channel = trig_channel;

		HAL_TIM_IC_Start_IT(us_sensor->htim_echo, TIM_CHANNEL_1 | TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(us_sensor->htim_trig, us_sensor->trig_channel);
}

float hc_sr04_convert_us_to_cm(uint32_t distance_us)
{
    return ((float)distance_us * HC_SR04_US_TO_CM_CONVERTER);
}

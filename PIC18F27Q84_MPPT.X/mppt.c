#include "mppt.h"

void mppt_init()
{
    V_prev = 50.0;
    P_prev = 300.0;
    duty_cycle = 50.0;
}

void mppt_cycle()
{
    	V_pv = ADC_GetSingleConversion(channel_ANA0) * (5.0 / 1023.0);
    	I_pv = ADC_GetSingleConversion(channel_ANA1) * (5.0 / 1023.0);
    	V_bat = ADC_GetSingleConversion(channel_ANA4) * (5.0 / 1023.0);

    	P_pv = V_pv * I_pv;

    	if (P_pv > P_prev) {
        		if (V_pv > V_prev) {
          			duty_cycle -= DUTY_CYCLE_STEP;
    		} else {
        			duty_cycle += DUTY_CYCLE_STEP;
    		}
        } else {
    		if (V_pv > V_prev) {
        			duty_cycle += DUTY_CYCLE_STEP;
    		} else {
        			duty_cycle -= DUTY_CYCLE_STEP;
    		}
	}

    	min_duty = 2 * V_bat - 2;
    	max_duty = min_duty + 1;
    	if (duty_cycle > max_duty) duty_cycle = max_duty;
    	if (duty_cycle < min_duty) duty_cycle = min_duty;
        
        uint16_t uint_duty_cycle = (uint16_t)(
                (duty_cycle / 100.0)*((PWM1S1P1H<<8) + PWM1S1P1L)
                );
    	PWM1_16BIT_SetSlice1Output1DutyCycleRegister(uint_duty_cycle);

    	P_prev = P_pv;
    	V_prev = V_pv;

    	__delay_ms(100);
}

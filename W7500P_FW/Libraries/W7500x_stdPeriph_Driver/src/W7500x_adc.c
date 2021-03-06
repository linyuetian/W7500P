/*******************************************************************************************************************************************************
 * Copyright �� 2016 <WIZnet Co.,Ltd.> 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the ��Software��), 
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED ��AS IS��, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*********************************************************************************************************************************************************/
/**
  ******************************************************************************
  * @file    W7500x_stdPeriph_Driver/src/W7500x_adc.c    
  * @author  IOP Team
  * @version v1.0.0
  * @date    26-AUG-2015
  * @brief   This file contains all the functions prototypes for the adc 
  *          firmware library.
  ******************************************************************************
  *
  ******************************************************************************
  */

/*include -------------------------------------*/
#include "W7500x_adc.h"

void ADC_PowerDownEnable (FunctionalState NewState)
{
	if (NewState != DISABLE)    ADC->ADC_CTR = ADC_CTR_PWD_PD;
	else                        ADC->ADC_CTR = ADC_CTR_PWD_NRMOP;
}

void ADC_ChannelSelect (ADC_CH num)
{
	assert_param(IS_ADC_CH_NUM(num));
	ADC->ADC_CHSEL = num;
}

void ADC_Start (void)
{
	ADC->ADC_START = ADC_START_START;
}

uint16_t ADC_ReadData (void)
{
	return ((uint16_t)ADC->ADC_DATA);
}

void ADC_InterruptMask (FunctionalState NewState)
{
	if (NewState != DISABLE)    ADC->ADC_INT = ADC_INT_MASK_ENA;
	else                        ADC->ADC_INT = ADC_INT_MASK_DIS;
}

uint8_t ADC_IsEOC (void)
{
	return (((uint8_t)ADC->ADC_INT && 0x01ul));
}
		
void ADC_InterruptClear (void)
{
	ADC->ADC_INT = ADC_INTCLEAR;
}

void ADC_Init (void)
{
	// ADC_CLK on
	ADC_PowerDownEnable(DISABLE);
	//ADC_ChannelSelect(num);
}

void ADC_DeInit (void)
{
	// ADC_CLK off
	ADC_PowerDownEnable(ENABLE);
	ADC_InterruptMask(DISABLE);
}


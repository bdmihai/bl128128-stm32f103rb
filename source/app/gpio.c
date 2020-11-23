/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2020 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 15.May.2020  |
 |                                                                            |
 |___________________________________________________________________________*/

#include "stm32f1xx.h"
#include "gpio.h"

void vGPIOInit()
{
    /* set the pis A0-7 as output low speed (max 2MHz) */
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF0_Msk | GPIO_CRL_MODE0_Msk, GPIO_CRL_MODE0_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF1_Msk | GPIO_CRL_MODE1_Msk, GPIO_CRL_MODE1_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF2_Msk | GPIO_CRL_MODE2_Msk, GPIO_CRL_MODE2_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF3_Msk | GPIO_CRL_MODE3_Msk, GPIO_CRL_MODE3_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF4_Msk | GPIO_CRL_MODE4_Msk, GPIO_CRL_MODE4_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk, GPIO_CRL_MODE5_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk, GPIO_CRL_MODE6_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk, GPIO_CRL_MODE7_1);

    /* set the pis B5-9 as output low speed (max 2MHz) */
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk, GPIO_CRL_MODE5_1);
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk, GPIO_CRL_MODE6_1);
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk, GPIO_CRL_MODE7_1);
    MODIFY_REG(GPIOB->CRH, GPIO_CRH_CNF8_Msk | GPIO_CRH_MODE8_Msk, GPIO_CRH_MODE8_1);
    MODIFY_REG(GPIOB->CRH, GPIO_CRH_CNF9_Msk | GPIO_CRH_MODE9_Msk, GPIO_CRH_MODE9_1);

    /* set the pis C13 as output low speed (max 2MHz) */
    MODIFY_REG(GPIOC->CRH, GPIO_CRH_CNF13_Msk | GPIO_CRH_MODE13_Msk, GPIO_CRH_MODE13_1);
}

void vGPIOSetLed()
{
    GPIOC->BSRR = GPIO_BSRR_BS13;
}

void vGPIOResetLed()
{
    GPIOC->BSRR = GPIO_BSRR_BR13;
}

void vGPIOSetCS()
{
    GPIOB->BSRR = GPIO_BSRR_BS5;
}

void vGPIOResetCS()
{
    GPIOB->BSRR = GPIO_BSRR_BR5;
}

void vGPIOSetRES()
{
    GPIOB->BSRR = GPIO_BSRR_BS6;
}

void vGPIOResetRES()
{
    GPIOB->BSRR = GPIO_BSRR_BR6;
}

void vGPIOSetDC()
{
    GPIOB->BSRR = GPIO_BSRR_BS7;
}

void vGPIOResetDC()
{
    GPIOB->BSRR = GPIO_BSRR_BR7;
}

void vGPIOSetWR()
{
    GPIOB->BSRR = GPIO_BSRR_BS8;
}

void vGPIOResetWR()
{
    GPIOB->BSRR = GPIO_BSRR_BR8;
}

void vGPIOSetRD()
{
    GPIOB->BSRR = GPIO_BSRR_BS9;
}

void vGPIOResetRD()
{
    GPIOB->BSRR = GPIO_BSRR_BR9;
}

void vGPIOConfigDataOut()
{
    /* set the pis 0-7 as output low speed (max 2MHz) */
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF0_Msk | GPIO_CRL_MODE0_Msk, GPIO_CRL_MODE0_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF1_Msk | GPIO_CRL_MODE1_Msk, GPIO_CRL_MODE1_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF2_Msk | GPIO_CRL_MODE2_Msk, GPIO_CRL_MODE2_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF3_Msk | GPIO_CRL_MODE3_Msk, GPIO_CRL_MODE3_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF4_Msk | GPIO_CRL_MODE4_Msk, GPIO_CRL_MODE4_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk, GPIO_CRL_MODE5_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk, GPIO_CRL_MODE6_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk, GPIO_CRL_MODE7_1);
}

void vGPIOConfigDataIn()
{
    /* set the pis 0-7 as input floating*/
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF0_Msk | GPIO_CRL_MODE0_Msk, GPIO_CRL_CNF0_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF1_Msk | GPIO_CRL_MODE1_Msk, GPIO_CRL_CNF1_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF2_Msk | GPIO_CRL_MODE2_Msk, GPIO_CRL_CNF2_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF3_Msk | GPIO_CRL_MODE3_Msk, GPIO_CRL_CNF3_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF4_Msk | GPIO_CRL_MODE4_Msk, GPIO_CRL_CNF4_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk, GPIO_CRL_CNF5_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk, GPIO_CRL_CNF6_1);
    MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk, GPIO_CRL_CNF7_1);
}

void vGPIOWriteData(uint8_t data)
{
    GPIOA->ODR = data;
}

uint8_t vGPIOReadData() 
{
    return GPIOA->IDR;
}

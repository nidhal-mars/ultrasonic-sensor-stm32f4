#include "stm32f4_discovery.h"
#include "delay.h"

uint32_t Read_Distance(void);
void Init();

uint32_t distance ;

int main()
{  
    Init();   // initialisation de pin
    SysTick_Init(); // pour pouvoire utiliser la fonction delay :)

    while (1)
    {
    distance=Read_Distance();
    delay_nms(100);
    }
}


void Init()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpioStructure;
       
    gpioStructure.GPIO_Pin = GPIO_Pin_10;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &gpioStructure);
    
    gpioStructure.GPIO_Pin = GPIO_Pin_11;
    gpioStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(GPIOD, &gpioStructure);
}
//Les Pins pour le Test sont PD10 (Trig) et PD11(echo) 

uint32_t Read_Distance(void)
{
		        __IO uint8_t flag=0;
	 	        __IO uint32_t disTime=0;
	 		GPIO_SetBits(GPIOD,GPIO_Pin_10);
	 		delay_nus(10);
	 		GPIO_ResetBits(GPIOD,GPIO_Pin_10);

		while(flag == 0)
		{ 
			while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_11) == SET)
			{
				 disTime++;
				 flag = 1;
			}
		
		}
	 		return disTime;
}
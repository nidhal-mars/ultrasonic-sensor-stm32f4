#include "delay.h"
 __IO uint32_t sysTickCounter; //Qui va ètre dècrèmentè pour assurer le delay
 
void SysTick_Init(void) {
    /****************************************
     *SystemFrequency/1000      1ms         *
     *SystemFrequency/100000    10us        *
     *SystemFrequency/1000000   1us         *
     *****************************************/
    while (SysTick_Config(SystemCoreClock / 1000000) != 0) 
    {}  // One SysTick interrupt now equals 1us : une interruption par 1us
 
}
 
// This method needs to be called in the SysTick_Handler:cherche la fonction SysTick_Handler dans le fichier stm32f4xx_it.c
 
void TimeTick_Decrement(void) 
{
    if (sysTickCounter != 0x00) 
    {sysTickCounter--;}
}
void delay_nus(u32 n) //cette fonction fait le delay de 1us
{   sysTickCounter = n;
while (sysTickCounter != 0) { }}
 void delay_1ms(void)      //Cette fonction ELEMENTAIRE fait un Delay de 1ms
 {  sysTickCounter = 1000;
    while (sysTickCounter != 0) {}
}
void delay_nms(u32 n) ///qui sera appeler dans le Main :elle fais le delay de n*1ms
{  while (n--)                
    {  delay_1ms();}
}
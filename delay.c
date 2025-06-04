#include"header.h"
void delay_us(u32 delayUS)
{
	for(delayUS*=12;delayUS>0;delayUS--);
}
void delay_ms(u32 delayMS)
{
  	for(delayMS*=12000;delayMS>0;delayMS--);
}
void delay_s(u32 delayS)
{
	for(delayS*=12000000;delayS>0;delayS--);
}

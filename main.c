#include"main_header.h"
int main()
{
	InitLCD(),Init_RTC(),Init_KPM();
	CmdLCD(0x0C);
	while(1)
	{
		display();
		if(((IOPIN1>>AHSW)&1)==1)
		{
			select();
		}		
	}	
}

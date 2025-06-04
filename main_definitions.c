#include"main_header.h"
#define LED 28 //P.0.0
s32 hourk,mink,seck,datek,monthk,yeark,dayk;
s32 houron,minon,secon;
s32 houroff,minoff,secoff;
void display(void)
{
	s32 T,Ton,Toff;
	IODIR1 |= 1<<LED;
		CmdLCD(0x0C);
	  GetRTCTime(&hourk,&mink,&seck);
		DisplayRTCTime(hourk,mink,seck);
		GetRTCDate(&datek,&monthk,&yeark);
		DisplayRTCDate(datek,monthk,yeark);
		GetRTCDay(&dayk);
		DisplayRTCDay(dayk);
		T=((hourk*60*60)+(mink*60)+seck);
		Ton=((houron*60*60)+(minon*60)+secon);
	  Toff=((houroff*60*60)+(minoff*60)+secoff);
		if((T>=Ton)&&(T<=Toff))
		{
			SetCursor(1,13);
			StrLCD("ok");
			IOSET1=1<<LED;
		}
		else
		{
			SetCursor(1,13);
			StrLCD("no");
			IOCLR1=1<<LED;
}
}
void select(void)
{
	u32 key;
	while(1)
	{
	CmdLCD(0x01);
	SetCursor(1,0);
	StrLCD("1.TIME");
	SetCursor(2,1);
	StrLCD("2.EDIT ON - OFF TIME ");
	SetCursor(1,8);
	StrLCD("3.EXIT");
	key=KeyDetect();
	CmdLCD(0x01);
	if(key==3)
	{
		break;
	}
		switch(key)
		{
			case 1: edit();
						break;
			case 2:device_on_off();
						break;
			case 3:break;
			default: CmdLCD(0x01);
							StrLCD("Enter correct");
							SetCursor(2,0);
							StrLCD("optin");
							delay_ms(500);
		}
	}
}
void edit(void)
{
	u32 key,data;
	CmdLCD(0x01);
	while(1)
	{
	SetCursor(1,0);
	StrLCD("1.H 2.M 3.S7.Day");
	SetCursor(2,0);
	StrLCD("4.d 5.M 6.Y 8.E ");
	key=KeyDetect();
		CmdLCD(0x01);
		if(key==8)
		{
			break;
		}
	switch(key)
	{
		case 1:
					CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("HOUR:");
					data=ReadNum();
					if(data>24)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCHour(data);
					break;
		case 2:CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("MIN:");
					data=ReadNum();
					if(data>59)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCMin(data);
					break;
		case 3:CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("SEC:");
					data=ReadNum();
					if(data>59)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCSec(data);
					break;
		case 4:CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("DATE:");
					data=ReadNum();
					if(data>31)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCDATE(data);
					break;
		case 5:CmdLCD(DSP_ON_CUR_BLINK);
				//	StrLCD("MONTH:");
					data=ReadNum();
					if(data>12)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCMONTH(data);
					break;
		case 6:CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("YEAR:");
					data=ReadNum();
					if(data>2026)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					SetRTCYEAR(data);
					break;
		case 7:CmdLCD(DSP_ON_CUR_BLINK);
					//StrLCD("DAY:");
					data=ReadNum();
					if(data>6)
					{
						SetCursor(2,0);
						StrLCD("INVALID INPUT");
						delay_ms(150);
					}
					setRTCDay(data);
					break;
		case 8:break;
		default:CmdLCD(0x01);
						StrLCD("INVALID");
						delay_ms(100);
	}
	}
}
void device_on_off(void)
{
	u32 key;
	CmdLCD(0x01);
	while(1)
	{
	CmdLCD(0x01);
	StrLCD("1.ON TIME");
	SetCursor(2,0);
	StrLCD("2.OFF TIME");
	SetCursor(1,10);
	StrLCD("3.EXIT");
	key=KeyDetect();
	CmdLCD(0x01);
	if(key==3)
	{
		break;
	}
	switch(key)
	{
		case 1:Device_on();
					break;
		case 2:Device_off();
					break;
		case 3:break;
		default:CmdLCD(0x01);
						StrLCD("INVALID");
			
	}
	}
}
void Device_on(void)
{
	u32 key;
	CmdLCD(0x01);
	while(1)
	{
	CmdLCD(0x01);
	StrLCD("1.H 2.M 3.S");
	SetCursor(2,0);
	StrLCD("4.Exit");
	key=KeyDetect();
	CmdLCD(0x01);
	if(key==4)
	{
		break;
	}
	switch(key)
	{
		case 1:CmdLCD(DSP_ON_CUR_BLINK);
						//StrLCD("HOUR:");
						houron=ReadNum();
						if(houron>24)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}	
						break;
		case 2:CmdLCD(DSP_ON_CUR_BLINK);
						//StrLCD("MIN:");
						minon=ReadNum();
						if(minon>59)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}
						break;
		case 3:CmdLCD(DSP_ON_CUR_BLINK);
						//StrLCD("SEC:");
						secon=ReadNum();
						if(secon>59)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}
					  break;
		case 4:break;
		default:CmdLCD(0x01);
						StrLCD("INVALID");
						delay_ms(100);
	}	
}
}
void Device_off(void)
{
	u32 key;
	CmdLCD(0x01);
	while(1)
	{
	CmdLCD(0x01);
	StrLCD("1.H 2.M 3.S");
	SetCursor(2,0);
	StrLCD("4.Exit");
	key=KeyDetect();
	CmdLCD(0x01);
	if(key==4)
	{
		break;
	}
	switch(key)
	{
		case 1:CmdLCD(DSP_ON_CUR_BLINK);
					  //StrLCD("HOUR:");
						houroff=ReadNum();
						if(houroff>24)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}
						break;
		case 2:CmdLCD(DSP_ON_CUR_BLINK);
						//StrLCD("MIN:");
						minoff=ReadNum();
						if(minoff>59)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}
						break;
		case 3:CmdLCD(DSP_ON_CUR_BLINK);
						//StrLCD("SEC:");
						secoff=ReadNum();
						if(secoff>59)
						{
							SetCursor(2,0);
							StrLCD("INVALID INPUT");
							delay_ms(150);
						}
					break;
		case 4:break;
		default:CmdLCD(0x01);
						StrLCD("INVALID");
						delay_ms(100);
	}	
	}
	}

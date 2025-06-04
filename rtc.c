#include <LPC21xx.H>
#include"rtc_defines.h"
#include"header.h"
#include"lcd.h"
char week[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
void Init_RTC(void)
{
	CCR=1<<1;
	PREINT=PREINT_Val;
	PREFRAC=PREFRAC_Val;
	//CCR=1<<0;
	CCR=RTC_CCR_EN | RTC_CCR_CLKSRC;
}
void GetRTCTime(s32 *hr,s32 *mi,s32 *se)
{
	*hr=HOUR;
	*mi=MIN;
	*se=SEC;
}
void DisplayRTCTime(u32 hour,u32 min,u32 sec)
{
	  SetCursor(1,0);
		CharLCD((hour/10)+48);
		CharLCD((hour%10)+48);
		CharLCD(':');
		CharLCD((min/10)+48);
		CharLCD((min%10)+48);
		CharLCD(':');
		CharLCD((sec/10)+48);
		CharLCD((sec%10)+48);
}
void GetRTCDate(s32 *date,s32 *mon,s32 *year)
{
	*date=DOM;
	*mon=MONTH;
	*year=YEAR;
}
void DisplayRTCDate(u32 date,u32 mon,u32 year)
{
	SetCursor(2,0);
		CharLCD((date/10)+48);
		CharLCD((date%10)+48);
		CharLCD('/');
		CharLCD((mon/10)+48);
		CharLCD((mon%10)+48);
		CharLCD('/');
		U32LCD(year);
}
void GetRTCDay(s32 *day)
{
	*day=DOW;
}
void DisplayRTCDay(u32 day)
{
	SetCursor(1,10);
	StrLCD(week[day]);
}
void setRTCTime(u32 hour,u32 min,u32 sec)
{
	HOUR=hour;
	MIN=min;
	SEC=sec;
}
void setRTCDate(u32 day,u32 mon,u32 year)
{
	DOM=day;
	MONTH=mon;
	YEAR=year;
}
void setRTCDay(u32 day)
{
	DOW=day;
}
void SetRTCHour(u32 houron)
{
	HOUR=houron;
}
void SetRTCMin(s32 minon)
{
	MIN=minon;
}
void SetRTCSec(s32 secon)
{
	SEC=secon;
}
/*void SetRTChour(s32 houroff)
{
	HOUR=houroff;
}
void SetRTCmin(s32 minoff)
{
	MIN=minoff;
}
void SetRTCsec(s32 secoff)
{
	SEC=secoff;
}
void SetRTCHOUR(s32 hourk)
{
	HOUR=hourk;
}
void SetRTCMIN(s32 mink)
{
	MIN=mink;
}
void SetRTCSEC(s32 seck)
{
	SEC=seck;
}*/
void SetRTCDATE(s32 datek)
{
	DOM=datek;
}
void SetRTCMONTH(s32 monthk)
{
	MONTH=monthk;
}
void SetRTCYEAR(s32 yeark)
{
	YEAR=yeark;
}
/*void SetRTCDAY(s32 dayk)
{
	DOW=dayk;
}*/








	

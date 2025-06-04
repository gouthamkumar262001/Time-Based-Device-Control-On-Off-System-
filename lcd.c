#include <LPC21xx.H>
#include"header.h"
#include"delay.h"
#include"lcd.h"
#include"lcd_defines.h"
void WriteLCD(u8 byte)
{
	IOCLR0=1<<LCD_RW;
	IOPIN0=((IOPIN0&~(0xFF<<LCD_DATA))|(byte<<LCD_DATA));
	IOSET0=1<<LCD_EN;
	delay_us(1); 
	IOCLR0=1<<LCD_EN;
	delay_ms(2);
}
void CmdLCD(u8 cmd)
{
	IOCLR0=1<<LCD_RS;
	WriteLCD(cmd);
}
void InitLCD(void)
{
	//IODIR0=((IODIR0&~(0xFF<<LCD_DATA))|(0xFF<<LCD_DATA));
	IODIR0|=0xFF<<LCD_DATA;
	IODIR0|=1<<LCD_RS;
	IODIR0|=1<<LCD_RW;
	IODIR0|=1<<LCD_EN;
	delay_ms(15);
	CmdLCD(0x30);
	delay_ms(4);
	//CmdLCD(0x30);
	delay_us(1);
	CmdLCD(0x30);
	delay_us(100);
	CmdLCD(0x30);
	CmdLCD(MODE_8BIT_2LINE);
	CmdLCD(DSP_ON_CUR_BLINK);
	CmdLCD(CLEAR_LCD);
	CmdLCD(SHIFT_CUR_RIGHT);
}
void CharLCD(u8 asciival)
{
	IOSET0=1<<LCD_RS;
	WriteLCD(asciival);
}
void SetCursor(u8 lineno,u8 pos)
{
	if( lineno==1)
	{
		CmdLCD(GOTO_LINE1_POS0+pos);
	}
	else if(lineno==2)
	{
		CmdLCD(GOTO_LINE2_POS0+pos);
	}
}
void StrLCD(s8 *str)
{
	while(*str)
		CharLCD(*str++);
}
void U32LCD(u32 num)
{
	u8 a[10];
	s32 index=0;
	if(num==0)
	{
		CharLCD('0');
	}
	else
	{
		while(num)
		{
			a[index]=(num%10)+48;
			index++;
			num/=10;
		}
		for(--index;index>=0;index--)
		{
			CharLCD(a[index]);
		}
	}
}
void S32LCD(s32 num)
{
	if(num<0)
	{
		CharLCD('-');
		num=-num;
	}
}
void F32LCD(f32 fnum,u32 ndp)
{
	s32 inum;
	if(fnum<0.0)
	{
		CharLCD('-');
		fnum=-fnum;
	}
	inum=fnum;
	U32LCD(inum);
	CharLCD('.');
	while(ndp)
	{
		fnum=(fnum-inum)*10;
		inum=fnum;
		CharLCD(inum+48);
		ndp--;
	}
	
}
void BuildCGRAM(u8 *p)
{
	u32 i;
	CmdLCD(GOTO_CGRAM_START);
	for(i=0;i<=7;i++)
	{
		CharLCD(p[i]);
	}
	CmdLCD(GOTO_LINE1_POS0);
}


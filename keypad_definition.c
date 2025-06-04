#include <LPC21xx.H>
#include"header.h"
#include"keypad_defines.h"
#include"keypad.h"
#include"lcd_defines.h"
#include"lcd.h"
#include"main_header.h"
unsigned char row_val,col_val;
unsigned int c0,c1,c2,c3;
unsigned char keypad_lut[4][4] = {7,8,9,'/',
																	4,5,6,'x',
																	1,2,3,'-',
																	'C',0,'=','+'};

u8 row_check[] = {0x0E,0x0D,0x0B,0x07};
void Init_KPM()
{
	IODIR1 |= (1<<ROW0 | 1<<ROW1 | 1<<ROW2 | 1<<ROW3);
	IOCLR1 = (1<<ROW0 | 1<<ROW1 | 1<<ROW2 | 1<<ROW3);
	IOSET1 = (1<<COL0 | 1<<COL1 | 1<<COL2 | 1<<COL3);
}													
u32 ColScan(void)
{
	c0 = (IOPIN1>>COL0)&1;
	c1 = (IOPIN1>>COL1)&1;
	c2 = (IOPIN1>>COL2)&1;
	c3 = (IOPIN1>>COL3)&1;
	if((c0&c1&c2&c3) == 0)
		return 0;
	else
		return 1;	
}

u32 RowCheck(void)
{
	u32 rNo;
	
	for(rNo=0;rNo<=3;rNo++)
	{
		WRITENIBBLE(IOPIN1,ROW0,row_check[rNo]);
		//WRITENIBBLE(IOPIN1,ROW0,(15^(1<<rNo)));
		if(ColScan() == 0)
			break;	
	}	
	return rNo;
}

u32 ColCheck(void)
{
	u32 cNo;
	
	if(((IOPIN1>>COL0)&1) == 0)
		cNo = 0;
	else if(((IOPIN1>>COL1)&1) == 0)
		cNo = 1;
	else if(((IOPIN1>>COL2)&1) == 0)
		cNo = 2;
	else if(((IOPIN1>>COL3)&1) == 0)
		cNo = 3;
	return cNo;	
}	
u32 KeyDetect(void)
{
	IOCLR1 = (1<<ROW0 | 1<<ROW1 | 1<<ROW2 | 1<<ROW3);
	while(ColScan());
	row_val = RowCheck();
	col_val = ColCheck();
	while(!ColScan());
	return keypad_lut[row_val][col_val];	
}

u32 ReadNum(void)
{
	s32 keyC,num=0,cnt=0,j=0;
	
	while(1)
	{
		keyC = KeyDetect();
		if(keyC>=0 && keyC<=9)
		{
			num = (num*10) + keyC;
			cnt++;
			//CharLCD(keyC+48);
			CmdLCD(0x01);
			U32LCD(num);
		}
		else if(keyC == 'C')
		{
			if(num>0)
			{
				num = num/10;
				CmdLCD(0x01);
				SetCursor(1,0);
				U32LCD(num);
			}
		}
		else if(keyC == '=')
		{
			break;
		}
		else if(keyC=='-')
		{
				SetCursor(1,(cnt--)-1);
		}
		else if(keyC=='+')
		{
				SetCursor(1,(cnt++)+1);
		}
		else if(keyC=='x')
		{
			//SetCursor(1,cnt);
			j=KeyDetect();
			U32LCD(j);
			num=j;
		}
	}
	return num;
}

	
		
	

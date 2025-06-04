//main_header.h
#ifndef _MAIN_HEADER_H
#define _MAIN_HEADER_H
#include <LPC21xx.H>
#include"lcd.h"
#include"lcd_defines.h"
#include"rtc.h"
#include"rtc_defines.h"
#include"header.h"
#include"keypad.h"
#include"main.h"
#include"delay.h"
#include"keypad_defines.h"
#define AHSW 25//P.1.25
#define LED 28//p.0.04
#define WRITENIBBLE(WORD,SBITPOS,NIBBLE) WORD=((WORD&~(15<<SBITPOS))|(NIBBLE<<SBITPOS))



#endif

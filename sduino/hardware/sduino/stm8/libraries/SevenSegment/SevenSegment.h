/*
	SevenSegment.h - sduino 7 Segment Led Display Library 
	Copyright (c) 2018  huaweiwx@sina.com

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "Arduino.h"
#include <xmacro.h>
#include <Print.h>

void SevenSegment_init(uint8_t da, uint8_t db, uint8_t dc, uint8_t dd, uint8_t de, uint8_t df, 
					   uint8_t dg, uint8_t dp, uint8_t d1, uint8_t d2,uint8_t d3,uint8_t d4,
											 uint8_t d5,uint8_t d6,uint8_t d7,uint8_t d8);
					   
void SevenSegment_begin(uint8_t inv);

void SevenSegment_showDEC(int16_t num);
void SevenSegment_showFloat(float num);
void SevenSegment_showHEX(uint32_t num);
void SevenSegment_display(void);

void SevenSegment_setLine(uint8_t l);
void SevenSegment_setPoint(uint8_t p);
void SevenSegment_setPos(uint8_t i);

void SevenSegment_showChar(uint8_t c,uint8_t pos);
size_t SevenSegment_write(uint8_t);


/* Syntax:
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d01,d02,d03,d04,d11,d12,d13,d14) //argc=16 2*4 
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d01,d02,d03,d11,d12,d13) 		//argc=14 2*3
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d1,d2,d3,d4) 					//argc=12 1*4
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d1,d2,d3) 						//argc=11 1*3
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d1,d2) 							//argc=10 1*2
 *	SevenSegment (instancename,da,db,dc,dd,de,df,dg,dp,d1) 							    //argc=9  1*1
 */
 
//2*4
#define XSevenSegment_inst16(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4,D5,D6,D7,D8) \
	    SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4,D5,D6,D7,D8)

//2*3
#define XSevenSegment_inst14(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4,D5,D6) \
	    SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4,D5,D6,255,255)

//1*4
#define XSevenSegment_inst12(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4) \
	    SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,D4,255,255,255,255)

//1*3
#define XSevenSegment_inst11(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3) \
	    SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2,D3,255,255,255,255,255)

#define XSevenSegment_inst10(DA,DB,DC,DD,DE,DF,DG,DP,D1,D2) \
		SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DT,D1,D2,255,255,255,255,255,255)

#define  XSevenSegment_inst9(DA,DB,DC,DD,DE,DF,DG,DP,D1) \
		SevenSegment_init(DA,DB,DC,DD,DE,DF,DG,DT,D1,255,255,255,255,255,255,255)

// The instantiation function remembers the pin mapping and the name of the
// needed constructor function in a function definition.
#define XSevenSegmentinst(instance,...) \
        inline void instance##_inst(void){\
		VARFUNC(XSevenSegment_inst,__VA_ARGS__);\
	}
	
#define XSevenSegmentbegin(instance) \
        void instance##_begin(uint8_t inv){\
             instance##_inst();\
		     SevenSegment_begin(inv);\
	}

// There are unneeded char declarations at the beginning the end of the
// list. The declaration at the beginning is to consume a possible "static"
// or "extern" before the macro call. The "extern char" at the end consumes
// the semicolon following at the end of line after the macro call.
//
// As a useful side effect this declaration will throw a compiler error
// message if the user tries to define two instances within one sketch.
//
// Calling the 'XPrintMethods' macro defines all functions needed for the
// the pseudo-inheritence of all output functions from Print "class".

#define SevenSegment(instance,...) \
	char	 	SevenSegment; \
	XSevenSegmentinst	(instance,__VA_ARGS__) \
    XSevenSegmentbegin(instance)\
    \
	X2Method2	(SevenSegment,instance,showChar,uint8_t,uint8_t) \
	X2Method1	(SevenSegment,instance,showDEC,int16_t) \
	X2Method1	(SevenSegment,instance,showFloat,float) \
	X2Method1	(SevenSegment,instance,showHEX,uint32_t) \
	X2Method1	(SevenSegment,instance,setLine,uint8_t) \
	X2Method1	(SevenSegment,instance,setPoint,uint8_t) \
	X2Method1	(SevenSegment,instance,setPos,uint8_t) \
	X2Method0	(SevenSegment,instance,display) \
	X2Method1return (SevenSegment,instance,size_t,write,uint8_t) \
	\
	XPrintMethods	(SevenSegment,instance) \
	extern char	SevenSegment

#endif

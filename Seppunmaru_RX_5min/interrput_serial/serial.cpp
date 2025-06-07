/*
 * serial.cpp
 *
 *  Created on: 2018/05/02
 *      Author: StarrySky
 */

#include "serial.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <mathf.h>
#include <math.h>

#define STR(s) #s
#define XSTR(s) STR(s)

#define OUT_BUFFER_MAX_CHARS 32
#define OUT_BUFFER_SIZE      (OUT_BUFFER_MAX_CHARS+1)

static  byte outbuffer[OUT_BUFFER_SIZE] = {0};


const char MessageNaN[] 	 	= "NaN";
const char MessagePInf[]	 	= "+inf";
const char MessageNInf[]	 	= "-inf";
const char MessageTooLarge[] 	= "TooLarge";
const char MessageTooSmall[] 	= "TooSmall";


static inline void bputSword(sword v)
{
	sprintf((char*)outbuffer, "%" SCNu16, v);
}

static inline void bputDword(dword v)
{
	sprintf((char*)outbuffer, "%" SCNu32, v);
	rsend();
}

static inline void bputInt16(int16_t v)
{
	sprintf((char*)outbuffer, "%" SCNd16, v);
}

static inline void bputInt32(int16_t v)
{
	sprintf((char*)outbuffer, "%" SCNd32, v);
}

static inline void bflush()
{
	rprint((const char *)outbuffer);
}

static inline void bflushln()
{
	rprint((const char *)outbuffer);
	rprintln();
}

static const char* getErrorIfNeeded(float a)
{
	if( !isfinite(a) ) {
		if(isnan(a))
			return MessageNaN;
		else if(a > 0)
			return MessagePInf;
		else
			return MessageNInf;
	} else if( a > INT32_MAX) {
		return MessageTooLarge;
	} else if(a < -INT32_MAX) {
		return MessageTooSmall;
	}
	return NULL;
}


void rprint(const char *str) {
	char c;
	while ((c = *str++) != 0)
	{
		putUByte(c);
	}
	rsend();
}

void rprintln(const char *str) {
	rprint(str);
	rprintln();
}

void rprintln() {
	rprint("\r\n");
}

void rprint(byte a) {
	rprint((sword) a);
}

void rprintln(byte a) {
	rprintln((sword) a);
}

void rprint(sword a) {
	bputSword(a);
	bflush();
}

void rprintln(sword a) {
	bputSword(a);
	bflushln();
}

void rprint(dword a) {
	bputDword(a);
	bflush();
}

void rprintln(dword a) {
	bputDword(a);
	bflushln();
}

void rprint(sbyte a) {
	rprint((int16_t) a);
}

void rprintln(sbyte a) {
	rprintln((int16_t) a);
}

void rprint(int16_t a) {
	bputInt16(a);
	bflush();
}

void rprintln(int16_t a) {
	bputInt16(a);
	bflushln();
}

void rprint(int32_t a) {
	bputInt32(a);
	bflush();
}

void rprintln(int32_t a) {
	bputInt32(a);
	bflushln();
}

void rprint(float a) {
	{
		const char* mes = getErrorIfNeeded(a);
		if(mes != NULL) {
			rprint(mes);
			return;
		}
	}
	byte    sign;
	int32_t high;
	int32_t low ;

	if(a<0)
		sign = '-';
	else
		sign = '+';

	// 符号削除
	a = fabs(a);

	{
		// high low 取得
		float   tmp;
		tmp  = floorf(a);
		high = (int32_t)tmp;
		tmp  = a-tmp;
		low  = (int32_t)(tmp * 10000);
	}

	// 出力
	putUByte(sign);
	{
		bputInt32(high);
		bflush();
	}
	putUByte('.');
	{
		sprintf((char*)outbuffer, "%04" SCNd32, low);
		bflush();
	}
}

void rprintln(float a) {
	rprint(a);
	rprintln();
}


void rprintm(float a) {
	rprint((int32_t) (a * 1000));
}

void rprintmln(float a) {
	rprintln((int32_t) (a * 1000));
}

void rbell() {
	putUByte('\a');
}



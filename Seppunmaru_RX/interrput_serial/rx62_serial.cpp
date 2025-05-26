/*
 * rx62_serial.cpp
 *
 *  Created on: 2018/05/02
 *      Author: StarrySky
 */

#include "rx62_serial.hpp"

SendBuffer sb2;
ReceiveQueue rq2;

struct SerialSetting{
	uint8_t  cks;
	uint8_t  brr;
	float    err;
};

static void initRecieveBuffer2() {
	rq2.writer = 1;
	rq2.reader = 0;
	sb2.size = 0;
	sb2.index = 0;
}

static SerialSetting& calcError(dword baudrate, SerialSetting &s)
{
	float clock = RX_MODULE_CLOCK;
	dword div = baudrate;
	div *= (s.brr+1);
	div *= 32;
	div *= (1 << (2*s.cks));
	s.err = (clock / div - 1) * 100;
	return s;
}

static SerialSetting getSettingOf(dword baudrate)
{
	SerialSetting st;
	
	byte  n   = 0;
	dword div = 32 * (1 << (2*n)) * baudrate;
	dword N   = RX_MODULE_CLOCK / div -1;
	for(byte n=0; n<4; ++n)
	{
		div = 32 * (1 << (2*n)) * baudrate;
		N   = RX_MODULE_CLOCK / div -1;
		if(N <= UINT8_MAX) {
			
			st.brr = N;
			st.cks = n;
			calcError(baudrate, st);
			return st;
		}
	}
	stopByError("Not supported baudrate");
}


// =======================================
// serial2
// =======================================
static void initSCI2 (dword baudrate) {
	// calc setting
	SerialSetting st = getSettingOf(baudrate);

	initRecieveBuffer2();

	MSTP(SCI2)       = 0;  // SCI2 wake up.
	PORT1.DDR.BIT.B2 = 0;  // Make RxD2-A input
	PORT1.ICR.BIT.B2 = 1;  // Enable Input Buffer on RxD2-A
	PORT1.DDR.BIT.B3 = 1;  // Make TxD2-A output
	PORT1.DR .BIT.B3 = 1;  // Set HIGH

	SCI2.SCR.BYTE    = 0;  // Disable Tx / Rx

	// Set mode register
	//  -Asynchronous Mode
	//  -8 bits
	//  -no parity
	//  -1 stop bit
	//  -PCLK clock (n = 0)
	SCI2.SMR.BYTE    = 0x00;

	// Enable RXI and TXI interrupts, even though we are not
	// using the interrupts, we will be checking the IR bits
	// as flags
	SCI2.SCR.BIT.RIE = 0;  //
	SCI2.SCR.BIT.TIE = 0;  //

	// Clear IR bits for TIE and RIE
	IR(SCI2, RXI2)   = 0;
	IR(SCI2, ERI2)   = 0;
	IR(SCI2, TXI2)   = 0;

	IEN(SCI2, RXI2)  = 1;
	IEN(SCI2, ERI2)  = 1;
	IEN(SCI2, TXI2)  = 0;

	IPR(SCI2, RXI2)  = 11;
	IPR(SCI2, ERI2)  = 11;
	IPR(SCI2, TXI2)  = 10;

	//  Set baud rate
	SCI2.SMR.BIT.CKS = st.cks;;
	SCI2.BRR = st.brr;

	for(volatile int i=0; i<32; i++){}

    SCI2.SCR.BIT.TEIE = 0;
	SCI2.SCR.BYTE |= 0xF0; // TIE, RIE, TE, E を同時に有効にする
	//SCI2.SCR.BIT.TIE  = 1;
	//SCI2.SCR.BIT.RIE  = 1;
	//SCI2.SCR.BIT.TE   = 1;
	//SCI2.SCR.BIT.RE   = 1; //RX Manual P.1356 : TE or RE いずれかが 1　のときは　０以外受け付けないので、後のRXが失敗する。
	SCI2.RDR;

	// logging
	//rprint("\r\r\n\nSCI2 Enabled (");
	//rprint(baudrate);
	//rprint(", error=");
	//rprint(st.err);
	//rprintln(")");
	//rsend();
}

  




// Implements
void initConsole(dword baudrate) {
  initSCI2(baudrate);
}

// Implements
void rflush() {
	rq2.reader = RECIEVE_INDEX_MASK & (rq2.writer-1);
	rq2.error  = 0;
}

void rsend() {
	if(sb2.size > 0)
		return;

	
	while(SCI2.SSR.BIT.TEND == 0);

	sb2.size = sb2.index;
	sb2.index = 0;

	IEN(SCI2, TXI2)  = 1;
}

// Implements
void putUByte(byte output_char)
{
	
	while(sb2.size > 0);
	sb2.buf[sb2.index++] = output_char;
	if(sb2.index >= SEND_BUF_SIZE) {
		rsend();
	}
}

// Implements
// 0以上の値　1バイト分のデータ
// -1のときが，データがまだ来てない
// 上記以外のとき，エラーが発生している
// エラーの場合は エラーコードにnot演算した値(~err)を返しています。
int16_t getUByte()
{
	int16_t err = rq2.error;
	if(err != 0)
	{
		rq2.error = 0;
		return ~err;
	}
	uint16_t  wi  = rq2.writer;
	uint16_t  ri  = RECIEVE_INDEX_MASK & (rq2.reader+1);
	uint8_t tmp  = 0;
	if(wi == ri) {
		return -1;
	};
	tmp = rq2.buf[ri];
	rq2.reader = ri;
	return (int16_t)(tmp) & 0xFF;
}

/*
 * rx62_serial.hpp
 *
 *  Created on: 2018/05/02
 *      Author: StarrySky
 */

#ifndef RX62_RX62_SERIAL_HPP_
#define RX62_RX62_SERIAL_HPP_


#include "rx62_common.hpp"
#include "serial.hpp"

#define RECIEVE_BUF_SIZE   128
#define RECIEVE_INDEX_MASK (RECIEVE_BUF_SIZE-1)
#define SEND_BUF_SIZE      32


#define RECIEVE_OVER_RUN         1
#define RECIEVE_FRAMING_ERROR    2
#define RECIEVE_BUFFER_OVERFLOW  4
#define DEBUG_ERROR_CODE         16
#define NO_RECIEVE_DATA          (-1)


struct SendBuffer {
	volatile sword size  ;
	volatile sword index ;
	volatile byte  buf[SEND_BUF_SIZE];
};

struct ReceiveQueue {
	volatile sword writer  ;
	volatile sword reader  ;
	volatile byte  error   ;
	volatile byte  buf[RECIEVE_BUF_SIZE];
};


extern SendBuffer sb2;

extern ReceiveQueue rq2;

inline void errorOnInterrupt2() {
	static byte bit = 0;
	static byte fer;
	static byte ovr;
	
	bit=0;

	if(SCI2.SSR.BIT.RDRF)
		SCI2.RDR;

	fer = SCI2.SSR.BIT.FER;
	SCI2.SSR.BIT.FER  = 0;
	ovr = SCI2.SSR.BIT.ORER;
	SCI2.SSR.BIT.ORER = 0;

	if(fer == 1)
		bit |= RECIEVE_FRAMING_ERROR;
	if(ovr == 1)
		bit |= RECIEVE_OVER_RUN;

	rq2.error |= bit;
}


inline void receiveOnInterrupt2() {
	static byte tmp=0;
	static sword wi=0;
	static sword ri=0;
	
	tmp = SCI2.RDR;
	wi  = rq2.writer;
	ri  = rq2.reader;
	
	if(wi == ri) {
		rq2.error |= RECIEVE_BUFFER_OVERFLOW;
		return;
	}
	rq2.buf[wi] = tmp;
	rq2.writer  = RECIEVE_INDEX_MASK & (wi+1);
}
void errorOnInterrupt2();


inline void sendOnInterrupt2()
{
	static sword i = 0;
	static sword s = 0;

	i = sb2.index++;
	s = sb2.size;

	if(i < s) {
		SCI2.TDR = sb2.buf[i];
	}

	if(i+1 >= s) {
		sb2.index = 0;
		sb2.size  = 0;
		IEN(SCI2, TXI2)  = 0;
	}
}

#endif /* RX62_RX62_SERIAL_HPP_ */

/*
 * serial.hpp
 *
 *  Created on: 2018/05/02
 *      Author: StarrySky
 */

#ifndef API_SERIAL_HPP_
#define API_SERIAL_HPP_

#include "mytype.hpp"

/**
 * initialization serial console.
 * @param baudrate 
 */
void initConsole(dword baudrate);

/**
 * interface
 * clear buffer
 */
void rflush();

/**
 * interface
 * start write
 */
void rsend();

/**
 * interface
 * send a byte
 * @param output_char
 */
void putUByte(uint8_t output_char);

/**
 * interface
 * get a byte
 */
int16_t getUByte();


void rprint(const char *str);
void rprintln(const char *str);
void rprintln(void);
void rprint(sword a);
void rprintln(sword a);
void rprint(dword a);
void rprintln(dword a);
void rprint(int16_t a);
void rprintln(int16_t a);
void rprint(int32_t a);
void rprintln(int32_t a);
void rprint(float a);
void rprintln(float a);
void rprintm(float a);
void rprintmln(float a);

// pon!
void rbell();


#endif /* API_SERIAL_HPP_ */

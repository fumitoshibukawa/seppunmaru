/*
 * rx62_common.hpp
 *
 *  Created on: 2018/05/02
 *      Author: StarrySky
 */

#ifndef RX62_RX62_COMMON_HPP_
#define RX62_RX62_COMMON_HPP_

#include "iodefine.h"

#include "mytype.hpp"
#include "serial.hpp"
#include "value.hpp"


// ICK
#define RX_CPU_CLOCK    96000000
// PCK (P = peripheral)
#define RX_MODULE_CLOCK 48000000
// BCK
#define RX_BUS_CLOCK    48000000


inline void stopByError(char* message) {
	rprintln(message);
	while(1);	
}

#endif /* RX62_RX62_COMMON_HPP_ */

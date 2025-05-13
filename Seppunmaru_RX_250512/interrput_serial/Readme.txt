-------- PROJECT GENERATOR --------
PROJECT NAME :	interrput_serial
PROJECT DIRECTORY :	C:\WorkSpace\interrput_serial\interrput_serial
CPU SERIES :	RX600
CPU TYPE :	RX62N
TOOLCHAIN NAME :	Renesas RX Standard Toolchain
TOOLCHAIN VERSION :	1.2.1.0
GENERATION FILES :
    C:\WorkSpace\interrput_serial\interrput_serial\dbsct.c
        Setting of B,R Section
    C:\WorkSpace\interrput_serial\interrput_serial\typedefine.h
        Aliases of Integer Type
    C:\WorkSpace\interrput_serial\interrput_serial\sbrk.c
        Program of sbrk
    C:\WorkSpace\interrput_serial\interrput_serial\iodefine.h
        Definition of I/O Register
    C:\WorkSpace\interrput_serial\interrput_serial\intprg.c
        Interrupt Program
    C:\WorkSpace\interrput_serial\interrput_serial\vecttbl.c
        Initialize of Vector Table
    C:\WorkSpace\interrput_serial\interrput_serial\vect.h
        Definition of Vector
    C:\WorkSpace\interrput_serial\interrput_serial\resetprg.c
        Reset Program
    C:\WorkSpace\interrput_serial\interrput_serial\hwsetup.c
        Hardware Setup file
    C:\WorkSpace\interrput_serial\interrput_serial\interrput_serial.c
        Main Program
    C:\WorkSpace\interrput_serial\interrput_serial\sbrk.h
        Header file of sbrk file
    C:\WorkSpace\interrput_serial\interrput_serial\stacksct.h
        Setting of Stack area
START ADDRESS OF SECTION :
 H'1000	B_1,R_1,B_2,R_2,B,R,SU,SI
 H'FFFF8000	PResetPRG
 H'FFFF8100	C_1,C_2,C,C$*,D_1,D_2,D,P,PIntPRG,W*,L
 H'FFFFFFD0	FIXEDVECT

* When the user program is executed,
* the interrupt mask has been masked.
* 
* Program start 0xFFFF8000.
* RAM start 0x1000.

DATE & TIME : 2018/10/17 18:10:06

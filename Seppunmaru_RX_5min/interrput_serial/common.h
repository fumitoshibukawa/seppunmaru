// *************************************
// *** common.h (���ʕϐ��C���ʒ萔) ***
// *************************************
#ifndef __COMMON_H
#define __COMMON_H
#include "mytype.hpp"
#include "iodefine.h"

// �G���R�[�_�J�E���g�J�n
#define START_ENCO_COUNT {MTUA.TSTR.BIT.CST1 = 1; MTUA.TSTR.BIT.CST2 = 1;  MTUB.TSTR.BIT.CST1 = 1; MTUB.TSTR.BIT.CST2 = 1;}
// �G���R�[�_�J�E���g��~
#define STOP_ENCO_COUNT {MTUA.TSTR.BIT.CST1 = 0; MTUA.TSTR.BIT.CST2 = 0; MTUB.TSTR.BIT.CST1 = 0; MTUB.TSTR.BIT.CST2 = 0;}
// ���荞�ݏ������~
#define STOP_FEED 	{CMT1.CMCR.BIT.CMIE  = 0;}

// --- �T���v�����O�^�C�� ---
#define  SampTime   10      // [ms]
#define  RsampTime   0.01f  // [s]

// --- �ő�f�[�^�� ---
#define  MaxDataNum  1001  // �ő厞�� = (MaxDataNum)*(SampTime)[ms]

#define  PI  3.141592654f

#define  Rad2Deg  57.29578f   // Rad �� Deg�@�ɕϊ�
#define  Deg2Rad  0.0174533f  // Deg �� Rad�@�ɕϊ�

// --- Joint Number ---
#define  Jnum    4
#define  Jnt1  0  
#define  Jnt2  1  
#define  Jnt3  2  
#define  Jnt4  3  
#define  MOTOR_L  0  //  Left wheel
#define  MOTOR_R  1  // Right wheel
#define  RD -1
#define  LD  1

// --- PD Line Trace ---
#define	KP	0.3		//0.3
#define KI	0.15
#define	KD	0.001
#define OI	0
#define IO	1 //white&black
#define II	3 //white&white
#define base_duty	350 // 290
#define base_duty2	250 // 150
#define Photo_1 PORT4.PORT.BIT.B7
#define Photo_2 AD0.ADDRB
#define Photo_3 AD0.ADDRC
#define Photo_4 PORT4.PORT.BIT.B6
#define Photo_RR PORT2.PORT.BIT.B6
#define Photo_RL PORT2.PORT.BIT.B7
#define WHITE 1
#define BLACK 0

// --- PID Search ---
#define	KP2	0.8
#define KI2 0.0002
#define	KD2	0.0005

// --- Feedback control ---
#define  STOP2   0
#define  ENCO   1
#define  PHOTO  2
#define  PHOTO_BACK 3
#define  PHOTO_SLOW 4

// --- �E�T�������T���̔F�� ---
#define RIGHT 1
#define LEFT 2

// --- size of input_buffer ---
//#define BUFFER_SIZE 41

// --- input_buffer ---
//char input_buffer[BUFFER_SIZE];

// --- for Pomp ---
#define POMP_OFF  PORT3.DR.BIT.B1 = 0;		// ���R�{�[�����o��~
#define POMP_ON   PORT3.DR.BIT.B1 = 1;		// �z���E���R�{�[�����o�J�n
#define WHITE_SWITCH PORTA.PORT.BIT.B6
#define BLUE_SWITCH PORTA.PORT.BIT.B5
#define BLACK_SWITCH PORTA.PORT.BIT.B4

// --- for Aruduino ---
#define ARM_PUT	        {PORTC.DR.BIT.B5=0;	PORTC.DR.BIT.B4=0; PORTC.DR.BIT.B7 = 0;}
#define ARM_MIDDLE	    {PORTC.DR.BIT.B5=0;	PORTC.DR.BIT.B4=1; PORTC.DR.BIT.B7 = 0;}		// �z���A�[���𒆊Ԃ܂Ŏ����グ��
#define ARM_LOW		    {PORTC.DR.BIT.B5=1;	PORTC.DR.BIT.B4=0; PORTC.DR.BIT.B7 = 0;}
#define ARM_CATCH	    {PORTC.DR.BIT.B5=1;	PORTC.DR.BIT.B4=1; PORTC.DR.BIT.B7 = 0;}

#define HUG_WAIT_DOWN	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define HUG_CATCH  	    {PORTD.DR.BIT.B0=1;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define HUG_WAIT_UP 	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define OPEN_UP	        {PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 0;}		// �n�O�@�\���J������ԂŎ����グ��
#define HUG_START_POSI	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 1;}
#define HUG_PYRAMID_UP	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}
#define HUG_PYRAMID_DOWN{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}
#define HUG_BULLDOZE	{PORTD.DR.BIT.B0=0; PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 1;}
#define HUG_BULL_NARROW	{PORTD.DR.BIT.B0=1; PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}		// �y�b�g�{�g���߂��̃{�[������邽�߂̃u���h�[�U�[

#define ULTRA_SONIC	 PORT5.PORT.BIT.B2 // �y�b�g�{�g���p(�ߋ���)
#define ULTRA_SONIC2 PORTC.PORT.BIT.B6 // �ʗp(������) Arduino D5

// --- for PasberryPi ---
#define SEARCH_START	PORTD.DR.BIT.B0
#define SEARCH_FINISH	PORTD.DR.BIT.B1
#define YES 1
#define NO  0
#define NOTHINGS		PORTD.PORT.BIT.B2

// --- for Music ---
//#define PLAY PORTB.DR.BIT.B5
//#define SEL0 PORTB.DR.BIT.B2
//#define SEL1 PORTB.DR.BIT.B3
//#define SEL2 PORTB.DR.BIT.B4

// ***********************
// *** For Kinemtatics ***
// ***********************

// --- Input Variables ---
#define  InputNum  2
#define  DDis  0  // dot Dis
#define  DTht  1  // dot Tht

// --- state type ---
typedef struct{
	float  d;  // ����
	float  v;  // ���x

} ki_stateType;


// --- kinematics shared type ---
typedef struct{
	float  W;  // �{�̂̉���
	float  r;  // �ԗ֔��a
    
	ki_stateType  traj[Jnum][MaxDataNum];
	
	float  in[InputNum][MaxDataNum];
    
} ki_sharedType;


// **********************
// *** For Controller ***
// **********************
// --- for time.h ---
#define  Stopped   0
#define  UntilInc  1
#define  Reached   1

// --- encoder count type ---
typedef struct{
	int  d, delta;  // pos, delta

} ct_eCountType;


// --- encoder type ---
typedef struct{
	ct_eCountType  present, last;

} ct_encoType;


// --- state type ---
typedef struct{
	float  d; 
	float  v; 

} ct_stateType;


// --- gain type ---
typedef struct{              
	float  kp, kv;  // for PD controller
    
} ct_gainType;


// --- joint type ---
typedef struct{
	ct_stateType  present, last;    
	ct_gainType   gain;
	float         delta;
    
} ct_jntType; 


// --- time type ---
typedef struct{
	volatile int  val;       //      val: now value�����o�O
	volatile int  startVal;  // startVal: begin time
	volatile int  stopVal;   //  stopVal: end time
	volatile int  inc;       //      inc: stop or move

} ct_timeType;


// --- control shared type ---
typedef struct{
	ct_jntType    jnt[Jnum];
	ct_encoType   enco[Jnum];
	ct_timeType   dTime;

	// motor
	float  Tr;  // ������
	int    pwm[Jnum];      // ���[�^��PWM�l�i�ő�l=Max_duty�j
	int    mot_dir[Jnum];  // ���[�^�̉�]����, jikken6�� LD, RD�̑���

	// encoder;
	float  WPulse2Rad;  // �ϊ��W�� enco[pulse] -> angle[rad]
	int    enco_dir[Jnum];      // �G���R�[�_�̉�]����
	int    tmp_enco_val[Jnum];  // �G���R�[�_�J�E���g�p���ϐ�

	// potentio
	float  Pot_rot2Rad;  // �ϊ��W�� ad[bit] (1024)-> angle[rad]
	float  start_angle;

	int  timeFlag;  // plan �̏I���t���O
	
	float  start_present_d[Jnum];  // ���{�b�g�̌��݈ʒu
 
	ct_stateType  data[Jnum][MaxDataNum];  // �f�[�^�Z�[�u�p�ϐ�
    
} ct_sharedType;

#endif

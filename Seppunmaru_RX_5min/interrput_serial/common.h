// *************************************
// *** common.h (共通変数，共通定数) ***
// *************************************
#ifndef __COMMON_H
#define __COMMON_H
#include "mytype.hpp"
#include "iodefine.h"

// エンコーダカウント開始
#define START_ENCO_COUNT {MTUA.TSTR.BIT.CST1 = 1; MTUA.TSTR.BIT.CST2 = 1;  MTUB.TSTR.BIT.CST1 = 1; MTUB.TSTR.BIT.CST2 = 1;}
// エンコーダカウント停止
#define STOP_ENCO_COUNT {MTUA.TSTR.BIT.CST1 = 0; MTUA.TSTR.BIT.CST2 = 0; MTUB.TSTR.BIT.CST1 = 0; MTUB.TSTR.BIT.CST2 = 0;}
// 割り込み処理を停止
#define STOP_FEED 	{CMT1.CMCR.BIT.CMIE  = 0;}

// --- サンプリングタイム ---
#define  SampTime   10      // [ms]
#define  RsampTime   0.01f  // [s]

// --- 最大データ数 ---
#define  MaxDataNum  1001  // 最大時間 = (MaxDataNum)*(SampTime)[ms]

#define  PI  3.141592654f

#define  Rad2Deg  57.29578f   // Rad ⇒ Deg　に変換
#define  Deg2Rad  0.0174533f  // Deg ⇒ Rad　に変換

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

// --- 右探索か左探索の認識 ---
#define RIGHT 1
#define LEFT 2

// --- size of input_buffer ---
//#define BUFFER_SIZE 41

// --- input_buffer ---
//char input_buffer[BUFFER_SIZE];

// --- for Pomp ---
#define POMP_OFF  PORT3.DR.BIT.B1 = 0;		// 自由ボール放出停止
#define POMP_ON   PORT3.DR.BIT.B1 = 1;		// 吸引・自由ボール放出開始
#define WHITE_SWITCH PORTA.PORT.BIT.B6
#define BLUE_SWITCH PORTA.PORT.BIT.B5
#define BLACK_SWITCH PORTA.PORT.BIT.B4

// --- for Aruduino ---
#define ARM_PUT	        {PORTC.DR.BIT.B5=0;	PORTC.DR.BIT.B4=0; PORTC.DR.BIT.B7 = 0;}
#define ARM_MIDDLE	    {PORTC.DR.BIT.B5=0;	PORTC.DR.BIT.B4=1; PORTC.DR.BIT.B7 = 0;}		// 吸引アームを中間まで持ち上げる
#define ARM_LOW		    {PORTC.DR.BIT.B5=1;	PORTC.DR.BIT.B4=0; PORTC.DR.BIT.B7 = 0;}
#define ARM_CATCH	    {PORTC.DR.BIT.B5=1;	PORTC.DR.BIT.B4=1; PORTC.DR.BIT.B7 = 0;}

#define HUG_WAIT_DOWN	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define HUG_CATCH  	    {PORTD.DR.BIT.B0=1;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define HUG_WAIT_UP 	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 0;}
#define OPEN_UP	        {PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 0;}		// ハグ機構を開いた状態で持ち上げる
#define HUG_START_POSI	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 1;}
#define HUG_PYRAMID_UP	{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=0; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}
#define HUG_PYRAMID_DOWN{PORTD.DR.BIT.B0=0;	PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}
#define HUG_BULLDOZE	{PORTD.DR.BIT.B0=0; PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 0; PORTD.DR.BIT.B3 = 1;}
#define HUG_BULL_NARROW	{PORTD.DR.BIT.B0=1; PORTD.DR.BIT.B1=1; PORTD.DR.BIT.B2 = 1; PORTD.DR.BIT.B3 = 1;}		// ペットボトル近くのボールを取るためのブルドーザー

#define ULTRA_SONIC	 PORT5.PORT.BIT.B2 // ペットボトル用(近距離)
#define ULTRA_SONIC2 PORTC.PORT.BIT.B6 // 缶用(中距離) Arduino D5

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
	float  d;  // 距離
	float  v;  // 速度

} ki_stateType;


// --- kinematics shared type ---
typedef struct{
	float  W;  // 本体の横幅
	float  r;  // 車輪半径
    
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
	volatile int  val;       //      val: now valueここバグ
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
	float  Tr;  // 減速比
	int    pwm[Jnum];      // モータのPWM値（最大値=Max_duty）
	int    mot_dir[Jnum];  // モータの回転方向, jikken6の LD, RDの代わり

	// encoder;
	float  WPulse2Rad;  // 変換係数 enco[pulse] -> angle[rad]
	int    enco_dir[Jnum];      // エンコーダの回転方向
	int    tmp_enco_val[Jnum];  // エンコーダカウント用仮変数

	// potentio
	float  Pot_rot2Rad;  // 変換係数 ad[bit] (1024)-> angle[rad]
	float  start_angle;

	int  timeFlag;  // plan の終了フラグ
	
	float  start_present_d[Jnum];  // ロボットの現在位置
 
	ct_stateType  data[Jnum][MaxDataNum];  // データセーブ用変数
    
} ct_sharedType;

#endif

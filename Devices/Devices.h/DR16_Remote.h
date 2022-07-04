/**
 * @file DR16_Remote.h
 * @author Leo Liu
 * @brief communicate and obtain data from DR16
 * @version 1.0
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dma.h"
#include "usart.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define DR16_BUFFER_NUMBER 22
#define DR16_BUFFER_TRUE_NUMBER 18
#define DR16_BUFFER_LAST_NUMBER 4

#define DR16_JOYSTICK_MAX 660

#define TOTAL_KEY_NUMBER 16

#define TIME_KEY_SINGLECLICK 1
#define TIME_KEY_HOLD 20

#define SWITCH_UP 	((uint16_t)1)
#define SWITCH_MID 	((uint16_t)3)
#define SWITCH_DOWN ((uint16_t)2)

#define KEY_W ((uint16_t)0x01<<0)
#define KEY_S ((uint16_t)0x01<<1)
#define KEY_A ((uint16_t)0x01<<2)
#define KEY_D ((uint16_t)0x01<<3)
#define KEY_SHIFT ((uint16_t)0x01<<4)
#define KEY_CTRL ((uint16_t)0x01<<5)   
#define KEY_Q ((uint16_t)0x01<<6)      
#define KEY_E ((uint16_t)0x01<<7)      
#define KEY_R ((uint16_t)0x01<<8)    
#define KEY_F ((uint16_t)0x01<<9)
#define KEY_G ((uint16_t)0x01<<10)     
#define KEY_Z ((uint16_t)0x01<<11)    
#define KEY_X ((uint16_t)0x01<<12)
#define KEY_C ((uint16_t)0x01<<13)
#define KEY_V ((uint16_t)0x01<<14)
#define KEY_B ((uint16_t)0x01<<15)  

typedef struct
{
	uint8_t Single_Click_Flag;
	uint8_t Hold_Flag;
	uint8_t State_Count;
	uint8_t State;
}Key_State;
	
typedef struct
{	
	uint8_t DR16_Buffer[DR16_BUFFER_NUMBER];
	
	struct
	{
		float x;
		float y;
		bool Left_Click;
		bool Right_Click;
	}Mouse;

	struct
	{
		int16_t Joystick_Left_Vx;
		int16_t Joystick_Left_Vy;
		int16_t Joystick_Right_Vx;
		int16_t Joystick_Right_Vy;
		uint8_t Left_Switch;
		uint8_t Right_Switch;
		int16_t Dial_Wheel;
	}Remote_Control;
	
	struct
	{
		uint16_t Buffer;
		Key_State Press_W;
		Key_State Press_S;
		Key_State Press_A;
		Key_State Press_D;
		Key_State Press_Shift;
		Key_State Press_Ctrl;
		Key_State Press_Q;
		Key_State Press_E;
		Key_State Press_R;
		Key_State Press_F;
		Key_State Press_G;
		Key_State Press_Z;
		Key_State Press_X;
		Key_State Press_C;
		Key_State Press_V;
		Key_State Press_B;
	}Keyboard;
}DR16_Data_t;

extern void DR16_Handler(UART_HandleTypeDef *huartx);
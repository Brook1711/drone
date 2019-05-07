#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdbool.h>
#include <stdint.h>


//#include "TM4C123GH6PM.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/fpu.h"
#include "driverlib/pin_map.h"
#include "ssd1306.h"
#include "oled.h"
#include "Time.h"
#include "uartstdio.h"
#include "interrupt.h"
#include "hw_gpio.h"
#include "i2c.h"
#include "Filter.h"
#include "data_type.h"

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)      ) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )


#define  USER_INT0  0x00   //PPM
#define  USER_INT1  0x20   //UART2
#define  USER_INT2  0x40   //UART0
#define  USER_INT3  0x60   //UART3
#define  USER_INT4  0x80   //UART1
#define  USER_INT5  0xA0   //532È¥¡¤1
#define  USER_INT7  0xE0   //TIMER0

#define ABS(X)  (((X)>0)?(X):-(X))
#define MAX(a,b)  ((a)>(b)?(a):(b))
#define Imu_Sampling_Freq  200
#define WP_Duty_Freq  200
#define WP_Duty_Dt  (1.0f/WP_Duty_Freq)


typedef   signed           char int8;
typedef unsigned           char u8;
//typedef unsigned           char uint8;
typedef unsigned           char byte;
//typedef   signed short     int int16;
//typedef unsigned short     int uint16;
typedef unsigned short     int u16;
typedef unsigned long     int u32; 

void system_init(void);
void schedule_task(void);

#endif

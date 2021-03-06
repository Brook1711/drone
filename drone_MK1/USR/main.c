#include "main.h"
#include "mpu6050_MK1.h"

Sensor my_sensor_data; //G所有的传感器数据都存在这个结构体里

int main(void)
{
  system_init();

	while(1)
	{
		schedule_task();
	}
}


void system_init(void)
{
	FPUEnable();
  FPULazyStackingEnable();
  SysCtlClockSet(SYSCTL_SYSDIV_4 |SYSCTL_USE_PLL |SYSCTL_OSC_MAIN |SYSCTL_XTAL_16MHZ);
	
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);
	
	initTime(); //延时初始化
	
	OLED_Init(); //显示屏初始化
	LCD_P8x16Str(0, 0, (unsigned char *)"GuoXuFeng");
	LCD_P8x16Str(0, 2, (unsigned char *)"DengHaoDong");
	LCD_P8x16Str(0, 4, (unsigned char *)"ZhangMingYu");
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1); //IIC1时钟初始化PA6：SCL；PA7：SDA
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); //使能GPIOA的时钟
	GPIOPinConfigure(GPIO_PA6_I2C1SCL); //设置PA6为SCL
	GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6); 
	GPIOPinConfigure(GPIO_PA7_I2C1SDA); //设置PA7为SDA
	GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7); 
	I2CMasterInitExpClk(I2C1_BASE, SysCtlClockGet(), true); //初始化主从
	I2CMasterEnable(I2C1_BASE);
	
	//G以下尝试初始化和使用MPU6050
	Init_MPU6050();//G初始化MPU6050模块

	
	
	return ;
}

void schedule_task(void)
{
	ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);
//	ROM_SysCtlDelay(SysCtlClockGet()/12);
	delay(10);
	ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
//	ROM_SysCtlDelay(SysCtlClockGet()/12);
	delay(10);
	
	//G尝试在任务调度函数里
	MPU6050_Read_Data(&my_sensor_data.gyro_raw, &my_sensor_data.accel_raw);//G从MPU6050直接读取数据
	LCD_CLS();//GLCD清零
	write_6_8_number(0, 0, my_sensor_data.gyro_raw.x);//G从MPU6050直接读取数据
	write_6_8_number(0, 2, my_sensor_data.gyro_raw.y);
	write_6_8_number(0, 4, my_sensor_data.gyro_raw.z);
	write_6_8_number(20, 0, my_sensor_data.accel_raw.x);
	write_6_8_number(20, 2, my_sensor_data.accel_raw.y);
	write_6_8_number(20, 4, my_sensor_data.accel_raw.z);
	return ;
}

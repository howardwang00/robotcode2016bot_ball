// Created on Sun January 31 2016

//#include <kipr/botball.h>

#include "drive.h"
#include "generic.h"

#include "functions.h"

//#defines in functions.h

int main()
{
	enable_servos();
	forward(20);
	msleep(1000);
	arm_up();
	msleep(1000);
	arm_down();
	msleep(1000);
	/*
	servo(3, 1000);
	arm_up();
	arm_down();
	*/
	
	
	disable_servos();
	return 0;
}

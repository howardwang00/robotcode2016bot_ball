// Created on Sun January 31 2016

//#include <kipr/botball.h>

#include "drive.h"
#include "generic.h"

#include "functions.h"

//#defines in functions.h

//#define MAIN
#ifdef main
int main() {
	
	
	shut_down_in(119.5);
	enable_servos();
	
	
	
	disable_servos();
}

#endif

#define DRIVEPATH_TEST
#ifdef DRIVEPATH_TEST
int main() {
	printf("In Drivepath test");
	
	//light_start(0);
	shut_down_in(119.5);
	arm_drive();
	claw_open();
	enable_servos();
	
	forward(100);
	/*
	msleep(500);
	collect_poms();
	*/
	
	
}

#endif

//#define ARM_CLAW_TEST
#ifdef ARM_CLAW_TEST
int main() {
	enable_servos();
	
	arm_up();
	msleep(1000);
	claw_open();
	msleep(1000);
	arm_down();
	msleep(1000);
	claw_close();
	msleep(5000);
	arm_up();
	msleep(1000);
	/*
	servo(3, 1000);
	arm_up();
	arm_down();
	*/
	
	
	disable_servos();
	return 0;
}
#endif

//#define CAMERA_TEST
#ifdef CAMERA_TEST
int main() {
	enable_servos();
	
	
	disable_servos();
	return 0;
}
#endif

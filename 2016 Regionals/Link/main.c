// Created on Sun January 31 2016

#include <kipr/botball.h>

//#include "drive.h"
//#include "generic.h"

#include "functions.h"

//#defines in functions.h

//#define MAIN
#ifdef MAIN
int main() {
	
	//light_start(0);
	shut_down_in(119.5);
	arm_drive();
	claw_open();
	bin_down();
	enable_servos();
	
	collect_poms();
	printf("Collected Initial Poms\n");
	
	forward(75);
	msleep(500);
	left(40, 0);
	msleep(300);
	//face 1st pile
	forward(45);
	pom_collection_sequence();
	
	
	
	
	disable_servos();
	ao();
	return 0;
}

#endif

#define DRIVEPATH_TEST
#ifdef DRIVEPATH_TEST
int main() {
	printf("In Drivepath test\n");
	
	
	//light_start(0);
	shut_down_in(119.5);
	arm_drive();
	claw_open();
	bin_down();
	enable_servos();
	
	forward(100);
	
	
	
	
	disable_servos();
	ao();
	return 0;
	
}

#endif

//#define ARM_CLAW_TEST
#ifdef ARM_CLAW_TEST
int main() {
	enable_servos();
	
	collect_poms();
	msleep(500);
	
	
	disable_servos();
	return 0;
}
#endif

//#define CAMERA_TEST
#ifdef CAMERA_TEST
int main() {
	enable_servos();
	
	check_poms();
	
	disable_servos();
	return 0;
}
#endif

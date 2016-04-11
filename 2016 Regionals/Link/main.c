// Created on Sun January 31 2016

#include <kipr/botball.h>

//#include "drive.h"
//#include "generic.h"

#include "functions.h"

//#defines in functions.h

#define MAIN
#ifdef MAIN
int main() {
	
	//light_start(0);
	shut_down_in(119.5);
	arm_up();
	claw_open();
	bin_down();
	enable_servos();
	
	collect_poms();
	printf("Collected Initial Poms in base\n");
	
	/*
	forward(70);
	msleep(500);
	left(35, 0);
	msleep(300);
	//face 1st pile
	forward(45);
	pomPileOne();
	*/
	forward(45);
	msleep(500);
	left(40, 0);
	//face 1st pile
	forward(65);	//needs to be exact or else claw will hit table divider
	pomPileOne();
	
	/*
	//4/9/16 Test Code
	forward(20);
	msleep(500);
	left(15, 0);
	msleep(300);
	//face 1st pile
	forward(80);
	pomPileOne();
	*/
	
	//go to pile 2
	multforward(45, 0.50);
	msleep(100);
	forward(15);
	msleep(300);
	left(80, ks/2);
	msleep(300);
	forward(5);
	pomPileTwo();
	
	if(green == 1 && red == 1) {
		printf("Collected all\n");
		//go to bin
		right(50, ks/2);
		forward(75);
	}
	else {
		//do pom pile three only if robot does not have both one red and one green
		pomPileThree();
	}
	
	disable_servos();
	ao();
	return 0;
}

#endif

//#define DRIVEPATH_TEST
#ifdef DRIVEPATH_TEST
int main() {
	printf("In Drivepath test\n");
	
	
	//light_start(0);
	shut_down_in(119.5);
	arm_drive();
	claw_open();
	bin_down();
	enable_servos();
	
	//forward(100);
	
	forward(10);
	int green = 0;	//whether green has been collected
	int red = 0;	//whether red has been collected
	
	start();	//start timer
	int pile1Result = pom_collection();
	backward(pom_collection_turn * 5);
	pom_collection_turn = 0;	//reset turn
	if(pile1Result == 0) {
		green = 1;
		printf("Collecting first pile of green poms\n");
	}
	else if(pile1Result == 1) {
		red = 1;
		printf("Collecting first pile of red poms\n");
	}
	//backward(5);
	left(15, ks/2);
	off(MOT_RIGHT);
	off(MOT_LEFT);
	collect_poms();
	collect_poms();
	msleep(1000);
	
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
	bin_dump();
	enable_servos();

	//check_poms();
	start();	//start timer
	pom_collection();
	
	disable_servos();
	return 0;
}
#endif

//#define DRIVE_TEST
#ifdef DRIVE_TEST
int main() {
	forward(100);
	msleep(500);
	return 0;
}
#endif

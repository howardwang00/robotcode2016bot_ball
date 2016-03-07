// Created on Sun March 6 2016

// Replace FILE with your file's name
#ifndef _FILE_H_
#define _FILE_H_

#include "drive.h"
#include "generic.h"

#define MOT_LEFT 2	//left wheel port
#define MOT_RIGHT 3	//right wheel port
#define MAIN_ARM 3	//main arm port
#define CLAW 2	//claw port

#define ARM_DOWN 380	//arm down position, the arm is down on the ground
#define ARM_UP 1871		//arm up position, for dumping in box
#define ARM_DRIVE 720	//arm position for driving
#define CLAW_OPEN 100	//claw open position
#define CLAW_CLOSE 100	//claw close position

void servo(int port, int position) {
	set_servo_position(port, position);
}
void arm_down() {
	servo(MAIN_ARM, ARM_DOWN);
}
void arm_up() {
	servo(MAIN_ARM, ARM_UP);
}
void arm_drive() {
	servo(MAIN_ARM, ARM_DRIVE);
}
void claw_open() {
	servo(CLAW, CLAW_OPEN);
}
void claw_close() {
	servo(CLAW, CLAW_CLOSE);
}


#endif

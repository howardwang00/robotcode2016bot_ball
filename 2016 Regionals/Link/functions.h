// Created on Sun March 6 2016

// Replace FILE with your file's name
#ifndef _FILE_H_
#define _FILE_H_

#include "drive.h"
#include "generic.h"

//two motors are in drive.h
//#define MOT_LEFT 1	//left wheel port
//#define MOT_RIGHT 0	//right wheel port
#define MAIN_ARM 3	//main arm port
#define CLAW 2	//claw port

#define ARM_DOWN 380	//arm down position, the arm is down on the ground
#define ARM_UP 1871		//arm up position, for dumping in box
#define ARM_DRIVE 720	//arm position for driving
#define CLAW_OPEN 0	//claw open position
#define CLAW_CLOSE 400	//claw close position

//camera code
#define RED 0	//for camera
#define GREEN 1
#define NOTHING 234	//random #

void servo(int port, int position) {
	set_servo_position(port, position);
}
void arm_down() {
	servo(MAIN_ARM, ARM_DOWN);
	msleep(50);	//wait to prevent servo shaking
}
void arm_up() {
	servo(MAIN_ARM, ARM_UP);
	msleep(50);
}
void arm_drive() {
	servo(MAIN_ARM, ARM_DRIVE);
	msleep(50);
}
void claw_open() {
	servo(CLAW, CLAW_OPEN);
	msleep(50);
}
void claw_close() {
	servo(CLAW, CLAW_CLOSE);
	msleep(50);
}
void collect_poms() {
	arm_down();
	msleep(500);
	claw_close();
	msleep(500);
	arm_up();
	msleep(500);
	claw_open();
	msleep(500);
}
int check_poms() {
	camera_open();
	camera_update();	//update many times for optimal results
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	int green_pom_area = get_object_area(GREEN, 0);
	int red_pom_area = get_object_area(RED, 0);
	printf("Green: %d", green_pom_area);
	printf("Red: %d", red_pom_area);
	
	return 0;	//no color blobs of either type detected
}


#endif

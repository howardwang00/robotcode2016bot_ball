// Created on Sun March 6 2016

// Replace FILE with your file's name
#ifndef _FILE_H_
#define _FILE_H_

#include "drive.h"
#include "generic.h"

//two motors are in drive.h
//#define MOT_LEFT 3	//left wheel port
//#define MOT_RIGHT 2	//right wheel port
#define MAIN_ARM 3	//main arm port
#define CLAW 2	//claw port

#define ARM_DOWN 350	//arm down position, the arm is down on the ground
#define ARM_UP 1670		//arm up position, for dumping in box
#define ARM_DRIVE 720	//arm position for driving
#define CLAW_OPEN 750	//claw open position
#define CLAW_CLOSE CLAW_OPEN + 600	//claw close position
#define BIN_DOWN 834;

//camera code	please disregard
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
	claw_open();
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
	printf("Green: %d\n", green_pom_area);
	printf("Red: %d\n", red_pom_area);
	if(green_pom_area > 100) {
		printf("Found green poms\n");
		return 0;
	}
	else if(red_pom_area > 100) {
		printf("Found red poms\n");
		return 1;
	}
	
	return -1;	//no color blobs of either color detected
}
int pom_collection() {
	printf("Time spent: %f\n", curr_time());
	if(check_poms() == 0) {
		return 0;
	}
	else if(check_poms() == 1) {
		return 1;
	}
	else if(curr_time() < 10) {
		backward(5);
		forward(5);
		msleep(50);
		return pom_collection();
	}
	return -1;
}
void pom_collection_sequence() {
	//robot must be at the first pom pile
	int green = 0;	//whether green has been collected
	int red = 0;	//whether red has been collected
	int gotPile1 = 0;
	int gotPile2 = 0;
	int gotPile3 = 0;
	
	start();	//start timer
	int pile1Result = pom_collection();
	if(pile1Result == 0) {
		green = 1;
		left(15, ks/2);
		collect_poms();
		collect_poms();
		printf("Collected first pile of green poms\n");
		gotPile1 = 1;
	}
	else if(pile1Result == 1) {
		red = 1;
		left(15, ks/2);
		collect_poms();
		collect_poms();
		printf("Collected first pile of red poms\n");
		gotPile1 = 1;
	}
	
	forward(50);
	msleep(100);
	left(40, ks/2);
	msleep(100);
	forward(20);
	
	//at next pile
	start();	//start timer
	msleep(100);
	int pile2Result = pom_collection();
	if(pile2Result == 0 && green == 0) {	//found green
		collect_poms();
		collect_poms();
		green = 1;
		gotPile2 = 1;
	}
	else if(pile2Result == 1 && red == 0) {	//found red
		collect_poms();
		collect_poms();
		red = 1;
		gotPile2 = 1;
	}
	else if(pile2Result == -1) {
		gotPile2 = 0;
	}
	
	if(green == 1 && red == 1) {
		printf("Collected all\n");
		//go to bin
	}
	else {
		printf("Missed a pile, going to third to complete collection.\n");
		//Go to third pile
	}
	
}

#endif

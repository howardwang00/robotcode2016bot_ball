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
#define BIN 0	//bin port

#define ARM_DOWN 350	//arm down position, the arm is down on the ground
#define ARM_UP 1670		//arm up position, for dumping in box
#define ARM_DRIVE 720	//arm position for driving
#define CLAW_OPEN 700	//claw open position
#define CLAW_OPEN_DROP CLAW_OPEN + 350	//claw open position
#define CLAW_CLOSE CLAW_OPEN + 650	//claw close position
#define BIN_DOWN 400
#define BIN_DUMP 1250

//camera code	please disregard
#define RED 0	//for camera
#define GREEN 1
#define NOTHING 234	//random #

int pom_collection_turn = 0;	//even - left, odd - right

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
void claw_open_drop() {
	servo(CLAW, CLAW_OPEN_DROP);
	msleep(50);
}
void claw_close() {
	servo(CLAW, CLAW_CLOSE);
	msleep(50);
}
void bin_down() {
	servo(BIN, BIN_DOWN);
	msleep(50);
}
void bin_dump() {
	servo(BIN, BIN_DUMP);
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
	claw_open_drop();
	msleep(300);
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
		if(pom_collection_turn % 2 == 0) {
			left(5, ks/2);
		}
		else {
			right(5, ks/2);
		}
		pom_collection_turn++;
		msleep(50);
		return pom_collection();
	}
	return -1;
}
void pom_collection_sequence() {
	//robot must be at the first pom pile
	int green = 0;	//whether green has been collected
	int red = 0;	//whether red has been collected
	
	start();	//start timer
	int pile1Result = pom_collection();
	backward(pom_collection_turn * 5);
	pom_collection_turn = 0;	//reset turn
	if(pile1Result == 0) {
		green = 1;
		left(15, ks/2);
		collect_poms();
		collect_poms();
		printf("Collected first pile of green poms\n");
	}
	else if(pile1Result == 1) {
		red = 1;
		left(15, ks/2);
		collect_poms();
		collect_poms();
		printf("Collected first pile of red poms\n");
	}
	
	forward(75);
	msleep(100);
	left(70, ks/2);
	msleep(100);
	forward(10);
	
	//at next pile, pile 2
	start();	//start timer
	msleep(100);
	int pile2Result = pom_collection();
	backward(pom_collection_turn * 5);
	pom_collection_turn = 0;	//reset turn
	if(pile2Result == 0 && green == 0) {	//found green
		collect_poms();
		collect_poms();
		green = 1;
	}
	else if(pile2Result == 1 && red == 0) {	//found red
		collect_poms();
		collect_poms();
		red = 1;
	}
	
	if(green == 1 && red == 1) {
		printf("Collected all\n");
		//go to bin
		right(50, ks/2);
		forward(75);
	}
	else {
		printf("Missed a pile, going to third to complete collection.\n");
		//Go to third pile
		right(60, ks/2);
		forward(40);
		int pile3result = pom_collection();
		backward(pom_collection_turn * 5);
		pom_collection_turn = 0;	//reset turn
		if(pile3result == 0 && green == 0) {
			collect_poms();
			green = 1;
		}
		else if(pile3result == 1 && red == 0) {
			collect_poms();
			red = 1;
		}
		if(green == 1 && red == 1) {
			printf("Collected all\n");
		}
		//go to bin
		
	}
	
}

#endif

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
#define BIN 1	//bin port
#define SECONDARY_ARM 1	//secondary arm port, secondary arm is for collecting two gold poms

#define ARM_DOWN 375	//arm down position, the arm is down on the ground
#define ARM_UP 1670		//arm up position, for dumping in box
#define ARM_MID 800	//arm position in the middle
#define CLAW_OPEN 750	//claw open position
#define CLAW_OPEN_DROP CLAW_OPEN + 300	//claw open position
#define CLAW_CLOSE CLAW_OPEN + 650	//claw close position
#define BIN_DOWN 450
#define BIN_MID 1000
#define BIN_DUMP 1250
#define GOLD_COLLECT 100	//collecting gold position
#define SECONDARY_MID 100
#define SECONDARY_BACK 100	//passive position

//camera code
#define RED 0	//for camera
#define GREEN 1
#define NOTHING 234	//random #

int green = 0;	//whether green has been collected
int red = 0;	//whether red has been collected
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
void arm_mid() {
	servo(MAIN_ARM, ARM_MID);
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
void bin_mid() {
	servo(BIN, BIN_MID);
	msleep(50);
}
void bin_dump() {
	servo(BIN, BIN_DUMP);
	msleep(50);
}
void collect_gold() {
	servo(SECONDARY_ARM, GOLD_COLLECT);
	msleep(50);
}
void secondary_mid() {
	servo(SECONDARY_ARM, SECONDARY_MID);
	msleep(50);
}
void secondary_back() {
	servo(SECONDARY_ARM, SECONDARY_BACK);
	msleep(50);
}
void collect_poms() {
	claw_open();
	
	//slowing down the arm
	servo(MAIN_ARM, 1200);
	msleep(100);
	arm_mid();
	msleep(100);
	arm_down();
	msleep(500);
	
	claw_close();
	msleep(700);
	arm_up();
	msleep(500);
	claw_open_drop();
	msleep(300);
	claw_open();
	msleep(500);
}
/*
void collect_poms_2() {
	servo(CLAW, CLAW_OPEN + 150);
	msleep(100);
	arm_down();
	msleep(700);
	claw_close();
	msleep(500);
	arm_up();
	msleep(500);
	claw_open_drop();
	msleep(300);
	claw_open();
	msleep(500);
}
*/
int check_poms() {
	camera_open();
	camera_update();	//update many times for optimal results
	camera_update();
	camera_update();
	int green_pom_area = get_object_area(GREEN, 0);
	int red_pom_area = get_object_area(RED, 0);
	//printf("Green: %d\n", green_pom_area);
	//printf("Red: %d\n", red_pom_area);
	if(green_pom_area > 150 && green_pom_area > red_pom_area) {
		printf("Found green poms\n");
		camera_close();
		return 0;
	}
	else if(red_pom_area > 150) {
		printf("Found red poms\n");
		camera_close();
		return 1;
	}
	camera_close();
	return -1;	//no color blobs of either color detected
}
int pom_collection() {
	printf("Time spent: %f\n", curr_time());
	int result = check_poms();
	if(result == 0) {
		return 0;
	}
	else if(result == 1) {
		return 1;
	}
	else if(curr_time() < 10) {
		if(pom_collection_turn == 0) {
			left(5, ks/2);
		}
		else if(pom_collection_turn % 2 == 0) {
			right(-5, ks/2);
			left(5, ks/2);
		}
		else {
			left(-5, ks/2);
			right(5, ks/2);
		}
		pom_collection_turn++;
		msleep(100);
		return pom_collection();
	}
	return -1;
}
void pomPileOne() {
	//robot must be at the first pom pile
	
	/*
	start();	//start timer
	int pile1Result = pom_collection();
	//backward(pom_collection_turn * 4);
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
	//left(5, ks/2);
	off(MOT_RIGHT);
	off(MOT_LEFT);
	*/
	collect_poms();
	collect_poms();
	
}
void pomPileTwo() {
	//at next pile, pile 2
	
	/*
	start();	//start timer
	int pile2Result = pom_collection();
	//backward(pom_collection_turn * 4);
	pom_collection_turn = 0;	//reset turn
	if(pile2Result == 0 && green == 0) {	//found green
		green = 1;
		collect_poms();
		collect_poms();
	}
	else if(pile2Result == 1 && red == 0) {	//found red
		red = 1;
		collect_poms();
		collect_poms();
	}
	*/
	collect_poms();
	collect_poms();
}
void pomPileThree() {
	printf("Missed a pile, going to third to complete collection.\n");
	//Go to third pile
	right(120, ks/2);
	/*
	int pile3result = pom_collection();
	//backward(pom_collection_turn * 4);
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
	*/
	collect_poms();
	collect_poms();
}

#endif

// Created on Sun January 31 2016

//#include <kipr/botball.h>

#include "drive.h"
#include "generic.h"

#define MOT_LEFT 2
#define MOT_RIGHT 3

int main()
{
	enable_servos();
	forward(100);
	
	
	disable_servos();
	return 0;
}

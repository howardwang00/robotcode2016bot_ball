#include "kipr/botball.h"
#include "createDrive.h"
#include "generic.h"

#define ARM_UP 500
#define CLAW_OPEN 200
#define CLAW_CLOSE 1O00
#define ARM_DOWN -1

int main()
{
     printf("a\n");
     printf("b\n");
	//create_full();
    printf("c\n");
	create_connect();
    printf("d\n");
    enable_servos();
    servo_set(2, ARM_UP, 0.5);
	create_forward(810, 150);
	create_right(75, 30, 120);
  servo_set(0, CLAW_OPEN, 1);
	create_forward(500, 150);
  	create_block();
 
     //servo_set(0, X , 0.2);
     servo_set(2, CLAW_DOWN, 0.5);
     create_backward(270, 100);
     disable_servos();
  	
	create_disconnect();
     return 0;
}

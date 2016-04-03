#include "kipr/botball.h"
#include "createDrive.h"
#include "generic.h"

#define ARM_UP 350
#define CLAW_OPEN 700
#define CLAW_CLOSE 1300
#define ARM_DOWN 1980
#define FORWARD_A 500
#define FORWARD_B 150

int main()
{
	
	//create_full();
    printf("c\n");
	//create_connect();

	
    printf("d\n");
    set_servo_position(0, ARM_UP);
    set_servo_position(2, CLAW_CLOSE);
    printf("e\n");
    enable_servos();
	/*create_forward(FORWARD_A, 150);
	create_right(76, 30, 120);
    create_forward(FORWARD_B, 150);
    create_left(40, 30, 120);
	create_forward(300, 150);*/
    msleep(1000);
    set_servo_position(0, ARM_DOWN);
    set_servo_position(2, CLAW_OPEN);
    //create_block();
     printf("f\n");
     msleep(2000);
     set_servo_position(2, 1370);
     msleep(500);
     set_servo_position(2, 1400);
     msleep(1000);
     printf("g\n");
     set_servo_position(0, 1800);
     msleep(500);
     set_servo_position(0, 1700);
     msleep(500);
     set_servo_position(0, 1500);
     msleep(500);
     //create_backward(270, 100);
     msleep(1000);
     disable_servos();
  	
	//create_disconnect();
    ao();
     return 0;
}
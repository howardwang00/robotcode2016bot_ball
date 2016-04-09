#include "createDrive.h"
#include "generic.h"

#define ARM_UP 350
#define CLAW_OPEN 700
#define CLAW_CLOSE 1350
#define ARM_DOWN 1980
#define FORWARD_A 630
#define FORWARD_B 150

int main()
{
    //set up
    //create_full();
    int a = 1;
    create_connect();
    set_servo_position(0, ARM_UP);
    set_servo_position(2, CLAW_CLOSE);
    enable_servos();
    
    //move to botguy
    create_forward(FORWARD_A, 200);
	create_right(64, 30, 120);
    create_forward(FORWARD_B, 200);
	create_forward(415, 200);
    create_stop();
    create_block();

    //open claw and set arm to get botguy
    msleep(1000);
    set_servo_position(0, ARM_DOWN);
    set_servo_position(2, CLAW_OPEN);
    msleep(2000);
    set_servo_position(2, 1370);
    msleep(500);
    set_servo_position(2, 1400);
    msleep(1000);
  
    //move it close to the pvc pipe so it doesn't need to move much over the ground
    create_backward(140, 75);
    create_block();
    create_stop();
    msleep(300);
  
    //move arm up slowly so botguy doesn't fall off
    set_servo_position(0, 1800);
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 1650);
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 1500);
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 1420);
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
  
    //get botguy to our side
    create_backward(175, 50);
    create_block();
    create_stop();
    msleep(300);
  
    //get botguy on ramp
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, ARM_DOWN);
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    create_left(21.69, 30, 37.5);
    create_block();
    create_stop();
    msleep(500);
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 1800);
    create_forward(100, 35);
    create_block();
    create_stop();
    set_servo_position(2, CLAW_OPEN);
    msleep(300);
    set_servo_position(0, 900); 
    msleep(300);
  
    //reset
    create_backward(72, 150);
    
    //box stuff
    create_right(90, 30, 150);
    create_forward(320, 150);
    create_left(8, 30, 37.5);
    create_stop();
    create_block();

  
     //open claw and set arm to get box
    msleep(1000);
    set_servo_position(0, ARM_DOWN);
    set_servo_position(2, CLAW_OPEN);
    msleep(2000);
    set_servo_position(2, 1370);
    msleep(500);
    set_servo_position(2, 1400);
    msleep(1000);
  
    create_backward(140, 75);
    create_block();
    create_stop();
  
    //move arm up
    set_servo_position(2, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 600);
    msleep(500);
    create_backward(169, 50);
    create_block();
    create_stop();
    create_right(130, 30, 30);
    create_block();
    create_stop();
    create_backward(60, 50);
    create_block();
    create_stop();
    set_servo_position(0, ARM_DOWN); 
    //end program
    disable_servos();
    create_disconnect();
    ao();
    return 0;
}
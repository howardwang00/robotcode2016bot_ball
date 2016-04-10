#include "createDrive.h"
#include "generic.h"

#define ARM_UP 400
#define CLAW_OPEN 630
#define CLAW_CLOSE 1300
#define ARM_DOWN 2000
#define ARM_PORT 0
#define CLAW_PORT 2
#define POKER_PORT 3
#define POKER_UP 2047
#define POKER_DOWN 0

int main()
{
    
    //set up
    create_full();
    create_connect();
    set_servo_position(ARM_PORT, ARM_UP);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    set_servo_position(POKER_PORT, POKER_DOWN);
    enable_servos();
    
    //move to botguy
    create_forward(630, 200);
	create_right(65, 30, 120);
    create_forward(150, 200);
	create_forward(410, 200);
    create_stop();
    create_block();

    //open claw and set arm to get botguy
    msleep(1000);
    set_servo_position(ARM_PORT, ARM_DOWN);
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    msleep(2000);
    set_servo_position(CLAW_PORT, 1370);
    msleep(300);
    set_servo_position(CLAW_PORT, 1400);
    msleep(1000);
  
    //move it close to the pvc pipe so it doesn't need to move much over the ground
    create_backward(140, 75);
    create_block();
    create_stop();
    msleep(300);
  
    //move arm up slowly so botguy doesn't fall off
    set_servo_position(ARM_PORT, 1800);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 1650);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 1500);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 1420);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
  
    //get botguy to our side
    create_backward(155, 50);
    create_block();
    create_stop();
    msleep(500);
  
    //get botguy on ramp
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 1450);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    create_left(17, 30, 37.5);
    create_block();
    create_stop();
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 1800);
    msleep(500);
    create_forward(145, 35);
    create_block();
    create_stop();
    //create_left(4, 30, 37.5);
    set_servo_position(CLAW_PORT, 850);
    msleep(1000);
    set_servo_position(ARM_PORT, 900); 
    msleep(500);
  
    //reset
    create_backward(180, 300);
    
    //box stuff
    create_right(65, 30, 150);
    create_forward(310, 150);
    create_stop();
    create_block();
    msleep(500);
  
    //open claw and set arm to get box
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    msleep(500);
    set_servo_position(ARM_PORT, ARM_DOWN);
    msleep(500);
    set_servo_position(CLAW_PORT, 1370);
    msleep(500);
    set_servo_position(CLAW_PORT, 1400);
    msleep(500);
  
    //take it closer to the pole and move back forward
    create_backward(140, 75);
    create_block();
    create_stop();
    set_servo_position(CLAW_PORT, 1000);
    msleep(500);
    set_servo_position(ARM_PORT, 2047);
    msleep(500);
    create_forward(70, 75);
    create_block();
    create_stop();
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    
  
    //move arm up
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(0, 350);
    msleep(500);
    
    //get the box to the colored line
    create_backward(70, 75);
    create_block();
    create_stop();
    create_right(139, 30, 100);
    create_block();
    create_stop();
    create_backward(60, 50);
    create_block();
    create_stop();
    set_servo_position(ARM_PORT, ARM_UP);
    msleep(500);
    set_servo_position(ARM_PORT, 1000);
    msleep(500);
    set_servo_position(ARM_PORT, ARM_DOWN); 
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    msleep(500);
    set_servo_position(ARM_PORT, ARM_UP);
    msleep(500);
  
    //turn and get composter
    create_block();
    create_stop();
    create_left(85, 30, 100);
    create_block();
    create_stop();
    create_forward(110, 100);
    create_block();
    create_stop();
    set_servo_position(ARM_PORT, 1844);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    set_servo_position(ARM_PORT, 500);
    msleep(500);
  
    //get the composter to the box
    create_right(128, 30, 100);
    create_block();
    create_stop();
    set_servo_position(CLAW_PORT, CLAW_CLOSE);
    msleep(500);
    //create_forward(1000, 150);
  
  while(get_create_lbump() == 0) {
    create_forward(10, 150);
    create_block();
  }
  
    create_right(20, 30, 150);
    create_forward(150, 150);
    create_block();
    create_stop();
  
    //dropping composter
    msleep(500);
    set_servo_position(CLAW_PORT, CLAW_OPEN);
    msleep(500);
    set_servo_position(CLAW_PORT, 1000);
    msleep(500);
    set_servo_position(ARM_PORT, ARM_UP);
    msleep(500);
  
    //move to the right position to get the ballz down
    set_servo_position(POKER_PORT, POKER_UP);
    msleep(500);
    create_right(90, 30, 100);
  
    //end program
    disable_servos();
    create_disconnect();
    ao();
    return 0;
}
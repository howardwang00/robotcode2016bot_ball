#include "kipr/botball.h"
#include "createDrive.h"
#include "generic.h"
#include "newmenu.h"
#include "singing.h"

int main()
{
	create_full();
	create_connect();
  	printf("Connected to create");
	create_left(45, 10, 60);
	create_forward(600, 400);
	create_right(70, 30, 120);
	create_forward(600, 400);
  	create_block();
	
	
	create_disconnect();
	return 0;
}

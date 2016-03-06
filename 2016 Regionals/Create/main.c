// Created on Sun January 31 2016

#include "createDrive.h";
#include "generic.h";
#include "newmenu.h";
#include "singing.h";

int main()
{
	
	create_connect();
	create_forward(50, 100);
	create_right(90, 30, 100);
	create_forward(50, 100);
	create_block();
	
	
	create_disconnect();
	return 0;
}

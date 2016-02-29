// Created on Sun January 31 2016

#include "createDrive.c";
#include <createDrive.h>;
#include <generic.c>;
#include <generic.h>;
#include <newmenu.c>;
#include <newmenu.h>;

int main()
{
	
	create_connect();
	create_drive_direct_dist(50, 50, 100);
	create_block();
	
	
	create_disconnect();
	return 0;
}

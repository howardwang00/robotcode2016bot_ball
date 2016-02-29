// Created on Sun January 31 2016

#include <drive.c>;
#include <drive.h>;
#include <generic.c>;
#include <generic.h>;
#include <newmenu.c>;
#include <newmenu.h>;

int main()
{
	enable_servos();
	forward(100);
	
	
	disable_servos();
	return 0;
}

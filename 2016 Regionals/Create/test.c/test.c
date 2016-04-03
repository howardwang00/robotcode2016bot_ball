// Created on Sun March 20 2016

int main()
{
	create_connect();
	create_drive_direct(100,100);
	wait_for_milliseconds(2000);
	create_drive_direct(-200, 200);	
	wait_for_milliseconds(5000);
	create_stop();
	create_disconnect();
	return 0;
}

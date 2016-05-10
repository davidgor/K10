//============================================================================
// Name        : Joystick.cpp
// Author      : David Gorrebeeck
// Version     : 0.1
// Copyright   : GPL
// Description : K9 software om hond te controleeren
//============================================================================

#include "Joystick.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <signal.h>
#include <thread>
#include "../../Loger/Loger.h"

int pos;
int ne=100;
// niets   0
// up      1
// down    2
// lings   3
// rechts  4
// enter   5

struct input_event ev[64];
int fevdev = -1;
int result = 0;
int size = sizeof(struct input_event);
int rd;
int value;
char name[256] = "Unknown";
char *device = "/dev/input/event0";


void Scan(){
	for(;;){
		rd = read(fevdev, ev, size * 64);

		switch(ev[0].code){ 								// selecteer toetscode
			case 106:
				pos = 1;
			break;
			case 105:
				pos =  2;
			break;
			case 108:
				pos =  3;
			break;
			case 103:
				pos =  4;
			break;
			case 28:
				pos =  5;
			break;
			default :
				pos =  0;
		}
		ne=100;
	}
}

void setZero(){
	for(;;){
		usleep(2500);
		ne--;
		if(ne<0)
			pos=0;
	}
}

Joystick::Joystick(Loger* loger) {
	loger->Log(3,"aankoppelen van joystick"); 	// zeg dat we gaan beginen

    fevdev = open(device, O_RDONLY);
    if (fevdev == -1) {
    	loger->Log(1,"ERROR:Failed to open event device.");
        throw 102;
    }

    result = ioctl(fevdev, EVIOCGNAME(sizeof(name)), name);
	loger->Log(4,"Reading From : dev");

    result = ioctl(fevdev, EVIOCGRAB, 1);

	std::thread first(Scan);
	first.detach();

	std::thread Zero(setZero);
	Zero.detach();


	loger->Log(3,"Yojstick aangekopelt");	 	// zeg dat de sensoren gestart zijn.
	return;

}

int Joystick::GetPos(){
	return pos;
}

Joystick::~Joystick() {
	close(fevdev);
	delete device;
}

/*
 * Sound.cpp
 *
 *  Created on: 26-dec.-2015
 *      Author: david12
 */

#include "Sound.h"

#include <string>
#include <stdlib.h>

Sound::Sound() {
	// TODO Auto-generated constructor stub

}

void Sound::Play(int sound){
	switch(0){//TODO repair
		case 1:
			system("screen -S K9_Play_sound -d -m aplay ./sound/start.wav");
		break;
		case 2:
			system("screen -S K9_Play_sound -d -m aplay ./sound/stop.wav");
		break;
	}
}

Sound::~Sound() {
	// TODO Auto-generated destructor stub
}


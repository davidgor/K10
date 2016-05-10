/*
 * ClasHolder.cpp
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#include "ClasHolder.h"


ClasHolder::ClasHolder(Loger* loger) {
	loger->Log(3,"Inladen van gegevens");

	display    		= new Display(loger);
	arduinoCom 		= new Arduino_Com();
	sound      		= new Sound();

	sensors			= new Sensors(loger);
	vc				= new VC();

	for(int a=48;a!=57;a++){							// herhaal 10 keer
		joystick[a].init(a);						// koppel joystick aan
	}												// hierdoor kunnen er tot 10 joysticks aangekopeld worden

	sleeper			= new Sleeper;					//


}

void ClasHolder::Update(){
	sensors->Update();
	vc->Update();

}

void ClasHolder::logic(){

}

void ClasHolder::Upgrade(){
	//arduinoCom->SetArmd(true);
}

void ClasHolder::Sync(){
	sleeper->Sleep();
}



ClasHolder::~ClasHolder() {
	delete display;
	delete arduinoCom;
	delete sound;

	delete sensors;
	delete vc;

}


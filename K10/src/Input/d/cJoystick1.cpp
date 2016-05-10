/*
  * cJoystick1.cpp
 *
 *  Created on: 17-feb.-2016
 *      Author: david12
 */

#include "cJoystick1.h"											// Haal te doen lijst op

       #include <pthread.h>										// Zorg ervoor dat je meerdere dingen teglijk kan
       #include <string.h>										// Werk met stukken tekst
       #include <stdio.h>										// Gebruik standaart I/O bibliotheek
       #include <stdlib.h>										// Gebruik statndaart bibliotheek
       #include <unistd.h>										// Maak gebruik van Unsignt INT's
       #include <errno.h>										// Maak weg vrij voor fautschrijven
       #include <ctype.h>										// Werk ook in C

cJoystick::cJoystick(){
	actif=false;
}

void cJoystick::init(char ID) {									// Bij opstarten
	active = false;												// zet actief op false
	joystick_fd = 0;											// zet dev nummer op null
	joystick_ev = new js_event();								// sla joystick zaken op
	joystick_st = new joystick_statee();						// Maak joystick input klaar
	const char* device=strcat("/dev/input/js",ID);
	std::cout << device <<std::endl;
	joystick_fd = open(device, O_RDONLY | O_NONBLOCK);	// Verbind Joystick
	if (joystick_fd > 0) {										// kontroleer op fauten.
		ioctl(joystick_fd, JSIOCGNAME(256), name);				// Haal joystick naam op
		ioctl(joystick_fd, JSIOCGVERSION, &version);			// Haal jaystick versie op
		ioctl(joystick_fd, JSIOCGAXES, &axes);					// Haal hoeveelhijd assen op
		ioctl(joystick_fd, JSIOCGBUTTONS, &buttons);			// haal hoeveelhijd knoppen op
		std::cout << "   Name: " << name << std::endl;			// zeg naam
		std::cout << "Version: " << version << std::endl;		// zeg vertie
		std::cout << "   Axes: " << (int)axes << std::endl;		// zeg aantal assen
		std::cout << "Buttons: " << (int)buttons << std::endl;	// zeg knoppen
		joystick_st->axis.reserve(axes);						// koppel assen aan
		joystick_st->button.reserve(buttons);					// koppel knoppen aan
		active = true;											// zet actief aan
		pthread_create(&thread, 0, &cJoystick::loop, this);		// start controle draat op
		actif=true;

	}
}

cJoystick::~cJoystick() {										// als er afgesloten wordt
	if (joystick_fd > 0) {										// als joystick aangesloten is
		active = false;											// zet actief uit
		pthread_join(thread, 0);								// wacht tot draad klaar is
		close(joystick_fd);										// sluit verbing joystick
	}
	delete joystick_st;											// verwijder stuk geheugen voor joystick
	delete joystick_ev;											// verwijder stuk geheugen voor joystick
	joystick_fd = 0;											// zet geheugen hier op null
}

void* cJoystick::loop(void *obj) {								// doe op aparte draad
	while (reinterpret_cast<cJoystick *>(obj)->active)			// blijf doen tot afsluiten gevraagt
		reinterpret_cast<cJoystick *>(obj)->readEv();			// haal nieuwe bewegingen op
}

void cJoystick::readEv() {
	int bytes = read(joystick_fd, joystick_ev, sizeof(*joystick_ev));	// lees gebeurtenis
	if (bytes > 0) {													// als gebeurtenis echt is
		joystick_ev->type &= ~JS_EVENT_INIT;							// krijg soort gebeurtenis
		if (joystick_ev->type & JS_EVENT_BUTTON) {						// is knop?
			joystick_st->button[joystick_ev->number] = joystick_ev->value;
		}																// Zet knop juist
		if (joystick_ev->type & JS_EVENT_AXIS) {						// is as?
			joystick_st->axis[joystick_ev->number] = joystick_ev->value;// Zet as juist
		}
	}
}

joystick_positione cJoystick::joystickPosition(int n) {				// vraag positie joystick - as
	joystick_positione pos;											// maak geheugen vrij

	if (n > -1 && n < axes) {										// als as niet te klijn is
		int i0 = n*2, i1 = n*2+1;									// doe wiskunde om te bepalen waar
		float x0 = joystick_st->axis[i0]/32767.0f,					// de joystick is
				y0 = -joystick_st->axis[i1]/32767.0f;				//
		float x  = x0 * sqrt(1 - pow(y0, 2)/2.0f),
				y  = y0 * sqrt(1 - pow(x0, 2)/2.0f);

		pos.x = x0;
		pos.y = y0;

		pos.theta = atan2(y, x);
		pos.r = sqrt(pow(y, 2) + pow(x, 2));
	} else {
		pos.theta = pos.r = pos.x = pos.y = 0.0f;					// bevestig vars
	}
	return pos;														// zet terug
}

bool cJoystick::buttonPressed(int n) {								//vraag knop op
	return n > -1 && n < buttons ? joystick_st->button[n] : 0;		//geef knop terug
}

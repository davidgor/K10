/*
 * cJoystick1.h
 *
 *  Created on: 17-feb.-2016
 *      Author: david12
 */

#ifndef D_CJOYSTICK1_H_					// controleer bestaan
#define D_CJOYSTICK1_H_					// zeg wie ik ben

#ifndef JOYSTICK_H						// controleer bestaan
#define JOYSTICK_H						// zeg wie ik ben

#include <iostream>						// vraag scrijfsysteem
#include <fcntl.h>						// file control options
#include <pthread.h>					// gebruik draad
#include <math.h>						// gebruik wiskunde
#include <linux/joystick.h>				// gebruik linux joystick gebruik
#include <vector>						// maak gebruik van vector
#include <unistd.h>						// maak gebruik van Unsignd int's
#include "../../Loger/Loger.h"

struct joystick_positione {				// maak strukt aan
	float theta, r, x, y;				// waar we 4 komma getalen gebruiken
};

struct joystick_statee {				// sla hier joystick staat op
	std::vector<signed short> button;	// gebruik knoppen
	std::vector<signed short> axis;		// gebruik assen
};

class cJoystick {
  private:
	pthread_t thread;					// maak geheugen voor draad vrij
	bool active;						// maak geheugen bit vrij
	int joystick_fd;					// maak geheugen byte vrij
	js_event *joystick_ev;				// sla joystick event op
	joystick_statee *joystick_st;		// sla joystick staat op
	__u32 version;						// maak 32 bit varialbe aan
	__u8 axes;							// maak 8 bit variable aan
	__u8 buttons;						// maak 8 bit variable aan
	char name[256];						// maak geheugen voor 256 karackters vrij
	bool actif;

  protected:
  public:
	cJoystick();						// voer uit in begin
	void init(char);
	~cJoystick();						// voer uit op einde
	static void* loop(void* obj);		// blijf herhalen
	void readEv();						// lees gegevens
	joystick_positione joystickPosition(int n);
        bool buttonPressed(int n);		// haal gegevens op
};

#endif

#endif /* D_CJOYSTICK1_H_ */

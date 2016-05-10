/*
 * ClasHolder.h
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#ifndef SRC_CLASHOLDER_H_
#define SRC_CLASHOLDER_H_

#include "Loger/Loger.h"

#include "Output/ArduinoCom/ArduinoCom.h"
#include "Output/Display/Display.h"
#include "Output/Sound/Sound.h"

#include "Input/Joystick/Joystick.h"
#include "Input/d/cJoystick1.h"
#include "Input/Sensors/Sensors.h"
#include "Input/Visual_Core/VC.h"

#include "Functions/Sleeper.h"

class ClasHolder {
public:
	ClasHolder(Loger*);

	void Update (void);
	void logic(void);
	void Upgrade(void);
	void Sync   (void);

	virtual ~ClasHolder();

private:
	Arduino_Com* 	arduinoCom;
	Display*     	display;
	Sound*       	sound;

	cJoystick   	joystick[10];
	Sensors*	 	sensors;
	VC*				vc;

	Sleeper*		sleeper;

};

#endif /* SRC_CLASHOLDER_H_ */

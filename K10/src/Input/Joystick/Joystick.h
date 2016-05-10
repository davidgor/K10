//============================================================================
// Name        : Joystick.h
// Author      : David Gorrebeeck
// Version     : 0.1
// Copyright   : GPL
// Description : K9 software om hond te controleeren
//============================================================================

#ifndef INPUT_JOYSTICK_JOYSTICK_H_
#define INPUT_JOYSTICK_JOYSTICK_H_

#include "../../Loger/Loger.h"

class Joystick {
public:
	Joystick(Loger*);
	int GetPos(void);
	virtual ~Joystick();
};

#endif /* INPUT_JOYSTICK_JOYSTICK_H_ */

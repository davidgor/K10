/*
 * Sensors.h
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#ifndef SRC_INPUT_SENSORS_SENSORS_H_
#define SRC_INPUT_SENSORS_SENSORS_H_

#include "../../Loger/Loger.h"

class Sensors {
public:
	Sensors(Loger*);

	void Update();

	virtual ~Sensors();


	// Getters and Setters

	int getXmov() const {
		return Xmov;
	}

	int getXrot() const {
		return Xrot;
	}

	int getYmov() const {
		return Ymov;
	}

	int getYrot() const {
		return Yrot;
	}

	int getZmov() const {
		return Zmov;
	}

	int getZrot() const {
		return Zrot;
	}

private:
	int Xrot,Yrot,Zrot;
	int Xmov,Ymov,Zmov;
};

#endif /* SRC_INPUT_SENSORS_SENSORS_H_ */

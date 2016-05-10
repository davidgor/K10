/*
 * ArduinoCom.h
 *
 *  Created on: 18-feb.-2016
 *      Author: david12
 */

#ifndef ARDUINOCOM_H_
#define ARDUINOCOM_H_

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

class Arduino_Com {
public:
	Arduino_Com();

	void SetMotor(int,int);
	int  GetMotor(int);

	void SetArmd (bool);
	bool GetArmd (void);

	static void* Looper(void *obj);
	bool Reconect(void);

	void OnArduinoDisconect(void);

	char* GetInput(FILE*);

	virtual ~Arduino_Com();
};

#endif /* ARDUINOCOM_H_ */

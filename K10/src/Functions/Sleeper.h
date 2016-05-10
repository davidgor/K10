/*
 * Sleeper.h
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#ifndef SRC_FUNCTIONS_SLEEPER_H_
#define SRC_FUNCTIONS_SLEEPER_H_

#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <ctime>

class Sleeper {
public:
	void Sleep(void);

private:
	std::clock_t start;
};

#endif /* SRC_FUNCTIONS_SLEEPER_H_ */

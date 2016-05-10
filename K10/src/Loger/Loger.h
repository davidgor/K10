/*
 * Loger.h
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#ifndef SRC_LOGER_LOGER_H_
#define SRC_LOGER_LOGER_H_

#include <iostream>

using namespace std;

class Loger {
public:
	Loger();

	void Log(int,string);
	/*
	 * -1 = Panic
	 * 0  = Fatal
	 * 1  = Error
	 * 2  = Warn
	 * 3  = Info
	 * 4  = Debug
	 * 5  = Trace
	 */

	virtual ~Loger();
};

#endif /* SRC_LOGER_LOGER_H_ */

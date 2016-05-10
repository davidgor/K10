/*
 * Display.h
 *
 *  Created on: 26-dec.-2015
 *      Author: david12
 */

#ifndef OUTPUT_DISPLAY_DISPLAY_H_
#define OUTPUT_DISPLAY_DISPLAY_H_


#include <stdint.h>
#include "../../Loger/Loger.h"

class Display {
public:
	Display(Loger*);
	void SetPixel(int,int,uint16_t);

	// Teken functies
	void SetHome ();
	void SetStop ();
	void SetTerug();
	void SetOke  ();
	void SetLoop ();
	void Clear   ();
	void green   ();
	void red     ();

	//voer uit voor destructie
	virtual ~Display();
};

#endif /* OUTPUT_DISPLAY_DISPLAY_H_ */

/*
 * TSS.h
 *
 *  Created on: 10-mrt.-2016
 *      Author: david12
 */

#ifndef SRC_OUTPUT_DISPLAY_TEXTSCROLLERSHOWER_TSS_H_
#define SRC_OUTPUT_DISPLAY_TEXTSCROLLERSHOWER_TSS_H_

#include <stdint.h>

class TSS {
public:
	TSS();
	void SetInt(int,uint16_t,uint16_t*[8][8]);
	virtual ~TSS();
};

#endif /* SRC_OUTPUT_DISPLAY_TEXTSCROLLERSHOWER_TSS_H_ */

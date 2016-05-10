/*
 * Sleeper.cpp
 *
 *  Created on: 22-mrt.-2016
 *      Author: david12
 */

#include "Sleeper.h"


void Sleeper::Sleep(){

	double duration = (( std::clock() - start ) / (double) CLOCKS_PER_SEC)*1000;
													// controleer verstreken tijd
		if(duration>=50){							// zijn er al 50 ms voorbij
			std::cout<< "warning: tick took to long : " << duration << "ms" << std::endl;
		}											// schrijf faut naar log
		else{										//anders
			usleep((50.0-duration)*1000.0);			// Wacht voor overige tijd
		}
		start=std::clock();							// Sla clock tijd op
		return;										// KLAAR

}


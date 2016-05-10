/*
 * Objecten.cpp
 *
 *  Created on: 28-mrt.-2016
 *      Author: david12
 */

#include "Objecten.h"

Objecten::Objecten(int ID,int soort,int pID,int gegevens[]) {
	this->ID    =ID;
	this->soort =soort;
	this->pID	=pID;
	this->data  =gegevens;
}

Objecten::~Objecten() {
	delete data;
}


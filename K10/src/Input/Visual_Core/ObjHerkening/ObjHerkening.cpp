/*
 * ObjHerkening.cpp
 *
 *  Created on: 27-mrt.-2016
 *      Author: david12
 */

#include "ObjHerkening.h"
#include <iostream>

ObjHerkening::ObjHerkening() {
	cascade=new CascadeClassifier[2];
	for(int a=0;a!=2;a++){
		cascade[a].load(cascadeNaam[a]);
	}

}

vector<Rect> ObjHerkening::Scan(Mat afb,int sC){

	vector<Rect> loc;

    cascade[sC].detectMultiScale( afb, loc, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE,
            Size(85,85) );

    return loc;
}

ObjHerkening::~ObjHerkening() {
	delete[] cascade;
}


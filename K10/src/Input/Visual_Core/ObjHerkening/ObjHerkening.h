/*
 * ObjHerkening.h
 *
 *  Created on: 27-mrt.-2016
 *      Author: david12
 */

#ifndef VISUAL_CORE_OBJHERKENING_OBJHERKENING_H_
#define VISUAL_CORE_OBJHERKENING_OBJHERKENING_H_


#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;
using namespace cv;

class ObjHerkening {
public:
	ObjHerkening();
	vector<Rect> Scan(Mat,int);
	virtual ~ObjHerkening();

private:
	CascadeClassifier* cascade;
	string cascadeNaam[2] ={
			"./HC/haarcascade_frontalface_alt.xml",
			"./HC/haarcascade_fullbody.xml"
	};

};

#endif /* VISUAL_CORE_OBJHERKENING_OBJHERKENING_H_ */

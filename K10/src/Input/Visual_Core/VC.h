/*
 * VC.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: david12
 */

#ifndef VISUAL_CORE_VC_H_
#define VISUAL_CORE_VC_H_

#define X_RES		1920
#define Y_RES		1080
#define X_DOTS		32
#define Y_DOTS		32

#define MIN_SAMPLES 12		// minimum aantal pixels die veranderen
							// voor er beweging word opgemerkt
#define MAX_SLEEP   50		// maximum aantal ms slaaptijd

#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/ml/ml.hpp"

#include "Objecten/Objecten.h"
#include "ObjHerkening/ObjHerkening.h"

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;
using namespace cv;


class VC {
public:
	VC();

	void Update(void);

	virtual ~VC();

	char map[X_DOTS][Y_DOTS];
private:
	bool enabled=false;
	bool error  =false;

	long tickcount=0;

	CvCapture* capture = 0;
    string inputName;

    Mat OudeAfbeelding;

    ObjHerkening* objH;

    void   CleanBuffer	(void);
    Mat    GetImage  	(void);
    bool** GetMoving 	(Mat);
    void   PicScan		(Mat,int);
    int**  GetBlock  	(bool[][Y_DOTS]);
};

#endif /* VISUAL_CORE_VC_H_ */

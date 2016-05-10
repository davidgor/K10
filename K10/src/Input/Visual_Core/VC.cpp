/*
 * VC.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: david12
 */

#include "VC.h"



VC::VC() {
	std::cout << "INFO: Starten van visuele kern\n";

    objH=new ObjHerkening();

    std::vector<std::vector<cv::Point> > contours;
	capture = cvCaptureFromCAM( inputName.empty() ? 0 : inputName.c_str()[0] - '0' );
	if(!capture){
		cout << "error:can not conect to camra" << endl;
		error=true;
		return;
	}

	OudeAfbeelding=this->GetImage();

	for(int a=0;a!=X_DOTS;a++)
		for(int b=0;b!=Y_DOTS;b++){
			map[a][b]=0;
		}

	enabled=true;
	error=false;
}

void VC::Update(){
	this->CleanBuffer();
    Mat frame=this->GetImage();
	cv::imshow("pici",frame);
    if(tickcount%5){

    }

    tickcount++;
/*
	Mat fg;

	subtract(frame, OudeAfbeelding, fg);

	bool** wit=this->GetMoving(fg);

	Mat nef;

	nef.create(fg.rows,fg.cols,1);

	for (int z1=0;z1!=32;z1++)
		for (int z2=0;z2!=32;z2++)
			for(int y=0; y<nef.cols/32; y++)
				for(int x=0; x<nef.rows/32; x++){
					if(wit[z1][z2])
						nef.at<uchar>(x+z1*nef.rows/32,y+z2*nef.cols/32)=100;
					else
						nef.at<uchar>(x+z1*nef.rows/32,y+z2*nef.cols/32)=250;
				}*/




    this->PicScan(frame,0);



}

void VC::CleanBuffer(){
	for(int a=0;a!=X_DOTS;a++)
		for(int b=0;b!=Y_DOTS;b++)
			map[a][b]=0;
}

Mat VC::GetImage(){
	Mat frame;
	cv::cvtColor((Mat)cvQueryFrame(capture),frame,CV_RGB2GRAY);
	return frame;
}

void VC::PicScan(Mat frame,int ID){

	vector<Rect> data= objH->Scan(frame,ID);

    Point center;
    int i=0;

    for( vector<Rect>::const_iterator r = data.begin(); r != data.end(); r++, i++ )
    {
        for(int a=16;a<r->width-16;a=a+16)
            for(int b=0;b<r->height;b=b+16){
            	map[(int)((b+r->y)/16)][(int)((a+r->x)/16)]=i+1;

            }
    }
}

bool** VC::GetMoving(Mat fg){
	bool** result;
	result=new bool*[32];
	for(int a=0;a!=32;a++)
		result[a]=new bool[32];


	int wit[32][32];
	int zwart[32][32];

	for (int z1=0;z1!=32;z1++){
		for (int z2=0;z2!=32;z2++){

			wit[z1][z2]=0;
			zwart[z1][z2]=0;


			//TODO change to subsampeling
			for(int y=0; y<fg.rows/32; y++)
				for(int x=0; x<fg.cols/32; x++){
					if(abs(fg.at<uchar>(x+z1*fg.rows/32,y+z2*fg.cols/32))>MIN_SAMPLES)
						wit[z1][z2]++;
					else
						zwart[z1][z2]++;
				}
			if(wit[z1][z2]>8)
				result[z1][z2]=true;
			else
				result[z1][z2]=false;
		}
	}

	return result;
}

int** VC::GetBlock(bool[][X_DOTS]){
	int** result;
	result=new int*[32];
	for(int a=0;a!=32;a++)
		result[a]=new int[32];



	return result;
}



VC::~VC() {
	std::cout << "INFO: Stoppen van visuele kern\n";
	cvReleaseCapture( &capture );
    cvDestroyAllWindows();
    delete objH;
}


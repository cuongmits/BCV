#include <cv.h> //for IplImage
/*
#include <stdio.h>
#include <ctype.h>
#include <math.h>*/

class BackgroundSubtraction
{
	//IplImage *bgImage;
public:
	int record10s();
	int getBackgroundImage();
	int colorBackgroundSubtraction();
}; //Note: need ";" here!
#include "stdafx.h" //need to add this: fatal error C1010: unexpected end of file while looking for precompiled header. Did you forget to add '#include "stdafx.h"' to your source?
#include "BackgroundSubtraction.h" //header
#include <iostream> //for cout
#include <cv.h> //for IplImage, CvCapture
#include <highgui.h> //for Video capture

using namespace std;	//for cout
using namespace cv;		//

//return 1 - default camera error
//return 0 - OK
int BackgroundSubtraction::record10s()
{
	cvNamedWindow( "Camera #0", CV_WINDOW_AUTOSIZE );	//create new window with NAME and SIZE
	CvCapture* capture = cvCreateCameraCapture(0);		//capture camera #0
	if(!capture) return 1;								//return -1 while camera problem

	double fps = 25;
	CvVideoWriter* writer = cvCreateVideoWriter(
		"../Debug/record5s.avi",
		CV_FOURCC('M','J','P','G'),	
		fps,
		cvSize(640, 480),
		true
	);

	IplImage* frame;												//declare frame (image)
	double startDuration = static_cast<double>(cv::getTickCount());	//number of clock cycles since computer started
	while(1) {								//loop 
		frame = cvQueryFrame( capture );	//get sequential frame
		if( !frame ) break;					//if no more frame then exit
		cvShowImage( "Camera #0", frame );	//else: show it in window
		char c = cvWaitKey(15);				//wait 15ms is likely real playing time in Window Media Player
		if( c == 27 ) break;				//if ESC key pressed, then break
		
		double time = (static_cast<double>(cv::getTickCount())-startDuration)/cv::getTickFrequency(); //devide with number of cycles per seconds to get time in second
		cout << time << "\n";

		if (time>=5) { //5s
			break;							//exit from loop
		}

		cvWriteFrame(writer, frame);
	}
	
	cvReleaseVideoWriter(&writer);
	cvReleaseCapture( &capture );			//release video file variable
	cvDestroyWindow( "Camera #0" );			//release window

	return 0;
}

//return 1 - default camera error
//return 0 - OK
int BackgroundSubtraction::getBackgroundImage()
{
	cvNamedWindow( "Camera #0", CV_WINDOW_AUTOSIZE );	//create new window with NAME and SIZE
	CvCapture* capture = cvCreateCameraCapture(0);		//capture camera #0
	if(!capture) return 1;								//return -1 while camera problem
	IplImage* frame;									//declare frame (image)
	double startDuration = static_cast<double>(cv::getTickCount());	//number of clock cycles since computer started
	while(1) {								//loop 
		frame = cvQueryFrame( capture );	//get sequential frame
		if( !frame ) break;					//if no more frame then exit
		cvShowImage( "Camera #0", frame );	//else: show it in window
		char c = cvWaitKey(15);				//wait 15ms is likely real playing time in Window Media Player
		if( c == 27 ) break;				//if ESC key pressed, then break
		double time = (static_cast<double>(cv::getTickCount())-startDuration)/cv::getTickFrequency(); //devide with number of cycles per seconds to get time in second
		cout << time << "\n";
		if (time>=5) { //5s
			cvNamedWindow("Capture Image", CV_WINDOW_AUTOSIZE);	//new window with name "Capture Image"
			cvShowImage("Capture Image", frame);				//Show captured image
			//cv::imwrite("C:\\Users\\Keon\\Documents\\Visual Studio 2008\\Projects\\test\\Debug\\capturedImage.JPG", frame); 	//save it (C++)
			//cvSaveImage("capturedImage.jpg", frame); 			//save in APP/test/Debug/capturedImage.jpg (simple C)
			cvSaveImage("../Debug/capturedImage.jpg", frame); 	//save in APP/Debug/capturedImage.jpg
			cvWaitKey(0);						//wait for any key
			cvDestroyWindow("Capture Image"); 	//release window
			break;								//exit from loop
		}
	}
	cvReleaseCapture( &capture );			//release video file variable
	cvDestroyWindow( "Camera #0" );			//release window

	return 0;
}

int BackgroundSubtraction::colorBackgroundSubtraction()
{
	namedWindow("Camera #0", CV_WINDOW_AUTOSIZE);			//create new window with NAME and SIZE
	namedWindow("Background Image", CV_WINDOW_AUTOSIZE);	//create new window with NAME and SIZE
	namedWindow("Background Subtraction", CV_WINDOW_AUTOSIZE);
	//IplImage* backgroundImage = cvLoadImage("C:\\Users\\Keon\\Documents\\Visual Studio 2008\\Projects\\test\\Debug\\capturedImage.JPG");
	Mat backgroundImage = imread("C:\\Users\\Keon\\Documents\\Visual Studio 2008\\Projects\\test\\Debug\\capturedImage.jpg");
	imshow("Background Image", backgroundImage);

	VideoCapture capture(0);			//default camera
	if(!capture.isOpened()) return 1;	//return -1 while camera problem
	Mat subtractedImage;				// = cvCreateImage(cvSize(640, 480), 8, 3);
	//double startDuration = static_cast<double>(cv::getTickCount());	//number of clock cycles since computer started
	while(1) {							//loop 
		Mat frame;
		capture >> frame;
		//if( !frame ) break;			//if no more frame then exit - no need
		imshow( "Camera #0", frame );	//else: show it in window

		//cvSub(frame, backgroundImage, subtractedImage);
		//cvtColor( frame, frame, CV_BGR2GRAY );
		
		//imshow("Background Subtraction", subtractedImage);
		

		char c = cvWaitKey(15);			//wait 15ms is likely real playing time in Window Media Player
		if( c == 27 ) break;			//if ESC key pressed, then break
		double time = (static_cast<double>(cv::getTickCount())-startDuration)/cv::getTickFrequency(); //devide with number of cycles per seconds to get time in second
		cout << time << "\n";
	}
	cvReleaseCapture( &capture );		//release video file variable
	cvDestroyWindow( "Camera #0" );	//release window

	return 0;
}
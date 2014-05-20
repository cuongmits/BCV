// BCV.cpp : Defines the entry point for the console application.
/*
Tasks:
1. Background Subtraction
2. Skeletonization analysing & comparing
3. Special points searching
4. Trajectory building
5. Movement Correction System building
*/

#include "stdafx.h"

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>
#include <string>

//1
#include "BackgroundSubtraction.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	while (1) 
	{
		system("cls");
		cout << "0. Initialization \n";
		cout << "0.1. Record Video for 10s \n";
		cout << "1. Get Background Image \n";
		cout << "2.1. Backgound Subtraction (Color - Color) -> Binary Image \n";
		cout << "2.2. Backgound Subtraction (Grey - Grey) -> Binary Image \n";
		cout << "3.1. Threshold: Color => Binary Image \n";
		cout << "3.2. Threshold: Grey => Binary Image \n";
		cout << "2. Skeletonization Analysing \n";
		cout << "3. Special Points Searching \n";
		cout << "4. Trajectory Building \n";
		cout << "5. Movement Correction System \n";
		cout << "Please enter command (Q-quit): ";
		/*char inputKey;
		cin >> inputKey;*/
		std::string inputKey;
		cin >> inputKey;
		cout << "-------------------------------------\n";
		if (inputKey=="0") {
			cout << "0. Initialization \n";
		} else if (inputKey=="01") {
			cout << "0.1. Record Video for 10s \n";
			BackgroundSubtraction bg;
			bg.record10s();
		} else if (inputKey=="1") {
			cout << "1. Get Background Image \n";
			BackgroundSubtraction bg;
			bg.getBackgroundImage();
		} else if (inputKey=="21") {
		} else if (inputKey=="22") {
		} else if (inputKey=="31") {
		} else if (inputKey=="32") {
		} else if (inputKey=="99") {
		} else if (inputKey=="q" || inputKey=="Q" || inputKey=="quit") {
			return 0;
		} else {
			cout << "Input key must be number from 1 to N or Quit\n";
			system("PAUSE");
		}
	}
	return 0;
}


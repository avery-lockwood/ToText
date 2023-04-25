#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include "ToTxt.h"
#include <fstream>
#include <algorithm>


using namespace std;
using namespace cv;
/*
command formed of: name of function used
-edge + "inputs for canny & dilation" = detect edges (inputs uptional, if none then defaults are used
-image + "/imagepath"
-script + "/scriptpath"
-video + "/vidpath"

to do:
add bool canny to all functions 
add canny input parameters to all functions
add if statement around canny function
 pass functions 0 if no input has been specified for canny (initialize to zero and change only if 

 example command:
 -imgScript -image "C:\Users\benlo\Desktop\ToText\ToText\Resources\BarryBBenson.jpg" -script "C:\Users\benlo\Desktop\ToText\ToText\Resources\beeMovieScript.txt"
*/



int main() {

	string command;
	string func;
	string imgPath;
	string scriptPath;
	string vidPath;
	bool can = false;
	int can1 = 50;
	int can2 = 40;
	int dil1 = 5;
	int dil2 = 5;
	int x;
	int y;

	cout << "type -list to list available commands";
	cin >> command;


	//command = "-imgScript -image "C:/Users/benlo/Desktop/ToText/ToText/Resources/BarryBBenson.jpg" -script "C:/Users/benlo/Desktop/ToText/ToText/Resources/beeMovieScript.txt" -x 100 -y 40";
	stringstream commandStream(command);
	string currentCmd;
	commandStream >> currentCmd;
	string frame;
		int Sx = 10;
		int Sy = 10;


	//string imgScript(string path, string scriptPath);
	
	commandStream >> currentCmd;
	func = currentCmd;
	commandStream >> currentCmd;

		if (currentCmd == "-image") {
			commandStream >> currentCmd;
			string imgPath = currentCmd;
			cout << imgPath;

		}
		else if (currentCmd == "-script") {
			commandStream >> currentCmd;
			string scriptPath = currentCmd;
			cout << scriptPath;
		}
		else if (currentCmd == "-edge") {
			bool canny = true;
		}
		else if (currentCmd == "-x") {
			commandStream >> currentCmd;
			Sx = stoi(currentCmd);
		}
		else if (currentCmd == "-y") {
			commandStream >> currentCmd;
			Sy = stoi(currentCmd);
		}
		else {
			cout << currentCmd << " is not a valig argument for imgScript";
		}

		imgPath.erase(remove(imgPath.begin(), imgPath.end(), '"'), imgPath.end());

		scriptPath.erase(remove(scriptPath.begin(), scriptPath.end(), '"'), scriptPath.end());

		frame = imgScript(imgPath, scriptPath, Sx, Sy);
	
	//else
	//{
	//	cout << "somthing went wrong";
	//}
	
	cout << frame;



}
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include "ToTxt.h"
#include <fstream>
#include <algorithm>


using namespace std;
using namespace cv;


int main() {


	string path = "Resources/anvil.png";
	string scriptPath = "Resources/scrpt.txt";
	int y = 24;
	int x = 101;
	cout << imgTxtWithScript(path,scriptPath, x, y);
}

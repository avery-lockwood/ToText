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
	string path;
	string scriptPath;
	int x;
	int y;

	cout << "enter the path of the image file (ex: `Resources/anvil.png`)" << endl;
	cin >> path;

	cout << "enter the path of the .txt script file (ex: `Resources/scrpt.txt`)" << endl;
	cin >> scriptPath;

	cout << "enter the width of the image you would like to generate" << endl;
	cin >> x;

	cout << "enter the height of the image you would like to generate" << endl;
	cin >> y;

	path.erase(remove(path.begin(), path.end(), '"'), path.end());
	scriptPath.erase(remove(scriptPath.begin(), scriptPath.end(), '"'), scriptPath.end());

	cout << imgScript(path,scriptPath, x, y);

	cout << endl << endl << "press enter to exit...";
	cin.ignore();
}

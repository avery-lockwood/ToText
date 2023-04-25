#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include "ToTxt.h"


using namespace std;
using namespace cv;

wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void ExtKey() {

	Sleep(1000);
	INPUT ip;
	// ...
		// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the "A" key
	ip.ki.wVk = 0x1B; // virtual-key code for the "esc" key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));
}

string imgTxt(string path, int Sx, int Sy) {

	Mat img = imread(path);
	Mat  re;
	//Mat blur, canny;


	//GaussianBlur(img, blur, Size(7, 7), 5, 0);

	//Canny(blur, canny, 25, 25);

	resize(img, re, Size(Sx, Sy), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' +rand() % 40;
				frame += cch;
			}
			else {
				frame += " ";
			}
		}
		frame += '\n';
	}

	return frame;

}

string imgTxt2(string path, int Sx, int Sy) {

	Mat img = imread(path);
	Mat  re;
	//Mat blur, canny;


	//GaussianBlur(img, blur, Size(7, 7), 5, 0);

	//Canny(blur, canny, 25, 25);

	resize(img, re, Size(Sx, Sy), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 26;
				frame += cch;
			}
			else {
				frame += "  ";
			}
		}
		frame += '\n';
	}

	return frame;

}

string imgScript(string path, string scriptPath, int Sx, int Sy) {

	path.erase(remove(path.begin(), path.end(), '"'), path.end());

	scriptPath.erase(remove(scriptPath.begin(), scriptPath.end(), '"'), scriptPath.end());

	Mat img = imread(path);

	string content;
	ifstream input_file(scriptPath, ifstream::in);

	if (!input_file.is_open()) {
		cout << "failed to open " << scriptPath << '\n';
		return "failed";
	}
	else {

		Mat  re;

		//Mat blur, canny;

		//GaussianBlur(img, blur, Size(7, 7), 5, 0);

		//Canny(blur, canny, 25, 25);

		resize(img, re, Size(Sx, Sy), 0, 0, 1);

		string frame;

		char cch;

		for (int y = 0; y < Sy; y++) {
			for (int x = 0; x < Sx; x++) {
				unsigned char* p = re.ptr(y, x);
				if (p[0] < 200) {
					cch = input_file.get();
					while (cch == '\n' || cch == ' ' || cch == '\t') {
						cch = input_file.get();
					}

					frame += cch;

				}
				else {
					frame += " ";
				}
			}
			frame += '\n';
		}

		return frame;
		input_file.close();
	}

}

string CannyTxt(string path, int Sx, int Sy) {
	Mat img = imread(path);
	Mat re, blur, canny, dil;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	GaussianBlur(img, blur, Size(7, 7), 5, 0);

	Canny(blur, canny, 25, 25);
	dilate(canny, dil, kernel);
	resize(canny, re, Size(Sy, Sx), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 26;
				frame += cch;
			}
			else {
				frame += " ";
			}
		}
		frame += '\n';
	}

	return frame;

}

String VidTxt(Mat re,int Sx, int Sy) {
	


	

	//ofstream myfile;
	//myfile.open(path2 + name + ".txt");

	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 150;
				frame += cch;
			}
			else {
				frame += " ";
			}

		}
		frame += '\n';
	}

	return frame;
}

String list(){
	return "-edge + \"inputs for canny & dilation\" = detect edges (inputs uptional, if none then defaults are used"
		"-image + \"/imagepath\""
		"-script + \"/scriptpath\""
		"-video + \"/vidpath\"";
}




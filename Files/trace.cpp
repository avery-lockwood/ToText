#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void show(Mat img) {
	imshow("your shtipost:", img);
	waitKey(5000);
}
		
void main() {

	string path;

	string path2;

	string name;

	Mat blur, canny, dilated;
	
	
	int cann1 = 50;

	int cann2 = 55;

	int dil = 3;




	cout << "image path: \n";

	cin >> path;

	//cout << "input canny variable 1, then canny variable 2, then dilation amount";

	//cin >> cann1;

	//cin >> cann2;
	
	//cin >> dil;

	Mat kernel = getStructuringElement(MORPH_RECT, Size(dil, dil));

	Mat img = imread(path);

	GaussianBlur(img, blur, Size(7, 7), 5, 0);

	Canny(blur, canny, cann1, cann2);

	dilate(canny, dilated, kernel);

	thread first(show, dilated);

	//imshow("your shtipost:", img);

	//cout << "destination path: \n";

	//cin >> path2;

	//cout << "name: \n";
	
	//cin >> name;

	string fullPath = "C:/Users/benlo/Desktop/folder/test8.bmp";

	imwrite(fullPath, dilated);

	first.join();

}


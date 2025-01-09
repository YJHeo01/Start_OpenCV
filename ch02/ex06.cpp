#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void clickMouse(int event, int x, int y, int falgs, void* param) {
	Mat& img = *(Mat*)(param);
	if (event == EVENT_LBUTTONDOWN) circle(img, Point(x, y), 100, Scalar(255, 0, 0), 10);
	if (event == EVENT_RBUTTONDOWN) rectangle(img, Point(x, y), Point(x + 100, y + 100), Scalar(0, 0, 255), 10);
	imshow("image", img);
}

int main() {
	Mat image = Mat(600, 800, CV_8UC3, Scalar(0, 0, 0));
	imshow("image", image);
	setMouseCallback("image", clickMouse, &image);
	waitKey(0);
	return(0);
}

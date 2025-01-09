#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
int red, green, blue, radius;
int drawing = false;

void on_tracker(int, void*) {

}

void drawCircle(int event, int x, int y, int, void* param) {
	switch (event) {
		case EVENT_LBUTTONDOWN:
			drawing = true;
			break;
		case EVENT_MOUSEMOVE:
			if (drawing) circle(img, Point(x, y), 3, Scalar(blue, green, red), radius);
			break;
		case EVENT_LBUTTONUP:
			drawing = false;
			break;
		default:
			break;
	}
	imshow("img", img);
}

int main() {
	img = imread("c:/images/lenna.png");
	if (img.empty()) { cout << "영상을 읽을 수 없습니다." << endl; return -1; }
	namedWindow("img", 1);
	imshow("img", img);
	setMouseCallback("img", drawCircle);
	createTrackbar("R", "img", &red, 255, on_tracker);
	createTrackbar("G", "img", &green, 255, on_tracker);
	createTrackbar("B", "img", &blue, 255, on_tracker);
	createTrackbar("S", "img", &radius, 100, on_tracker);
	waitKey(0);
	return(0);
}

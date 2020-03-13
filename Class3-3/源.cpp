#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
string window_name = "binaryMat";
void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}
int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;
	srcMat = imread("D:\\a\\a.jpg");
	if (!srcMat.data)
	{
		cout << "Ê§°Ü" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, COLOR_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("thresgold",
		window_name,
		&lowTh,
		maxTh,
		threshod_Mat,
		&gryMat);
	waitKey(0);
	return 0;

}
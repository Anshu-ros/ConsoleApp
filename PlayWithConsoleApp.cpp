#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
	int main()
{
    VideoCapture cap(1); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
		system("pause");
        return -1;
    }
	double dwidth= cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dheight= cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout<<"Frame size:"<<dwidth<<"x"<<dheight<<endl;
	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE);
	system("pause");
	while (1)
	{
		Mat frame;
		bool bSuccess=cap.read(frame);
		if(!bSuccess)
		{
			cout<<"cannot read a frame from video stream"<<endl;
			break;
		}
		imshow("MyVideo",frame);
		if(waitKey(30)==27)
		{
			cout<<"esc key is pressed by user"<<endl;
			break;
		}
	}
	return 0;
}


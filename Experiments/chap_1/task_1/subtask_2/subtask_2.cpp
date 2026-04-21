#include <iostream>
#include <opencv2/opencv.hpp>
#include "equalizeHistLocal.hpp"

using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat img = imread("1-2.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "错误：无法加载图像，请检查路径是否正确。\n";
        return -1;
    }
    
    // 处理图像：局部直方图均衡化
    cout << "请输入局部窗口大小（奇数）: \n";
    int winSize = 0;
    cin >> winSize;
    if (winSize % 2 == 0) {
        cout << "错误：请输入奇数！\n";
        return -1;
    }
    Mat processed_img = equalizeHistLocal(img, 256, winSize);
    
    // 显示图像
    namedWindow("Processed Image", WINDOW_AUTOSIZE);
    imshow("Processed Image", processed_img);
    waitKey(0);
    destroyAllWindows();
    string s = "Processed Image (winSize = ";
    s = s + to_string(winSize);
    s = s + " ).jpg";
    imwrite(s, processed_img);

    return 0;
}
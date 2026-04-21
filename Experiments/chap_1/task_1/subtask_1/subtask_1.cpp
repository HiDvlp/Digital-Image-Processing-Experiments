// subtask_1：全局直方图均衡化
#include <iostream>
#include <opencv2/opencv.hpp>
#include "equalizeHist.hpp"
#include <string>

using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat image = imread("1-2.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "错误：无法加载图像，请检查路径是否正确。\n";
        return -1;
    }
    
    // 处理图像：全局直方图均衡化
    Mat processed_image = equalizeHist(image);
    
    // 显示图像
    namedWindow("Processed Image", WINDOW_AUTOSIZE);
    imshow("Processed Image", processed_image);
    waitKey(0);
    destroyAllWindows();
    imwrite("Processed Image.jpg", processed_image);
    return 0;
}
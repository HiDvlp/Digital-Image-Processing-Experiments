#include <opencv2/opencv.hpp>
// 使用直方图统计量增强局部图像
cv::Mat localHistEnhance(const cv::Mat& img, double k0, double k1, double k2, double k3, double C, int winSize=3);
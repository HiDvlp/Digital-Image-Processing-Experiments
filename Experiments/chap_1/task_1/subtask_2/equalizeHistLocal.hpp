#include <opencv2/opencv.hpp>
// 局部直方图均衡化
cv::Mat equalizeHistLocal(cv::Mat img, int L=256, int winSize=3);
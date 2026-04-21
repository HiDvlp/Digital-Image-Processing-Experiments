#include <opencv2/opencv.hpp>
// 局部直方图均衡化
cv::Mat equalizeHistLocal(cv::Mat img, int L=256, int winSize=3) {
    int M = img.rows;
    int N = img.cols;
    int half = winSize / 2;
    cv::Mat result = img.clone();
    double scalar = (L-1.0) / (winSize*winSize);

    for (int i = half; i <= M-1-half; ++i) {
        for (int j = half; j <= N-1-half; ++j) {
            int hist[L] = {0};
            // 统计局部直方图
            for (int k = i-half; k <= i+half; ++k) {
                for (int l = j-half; l <=j+half; ++l) {                
                    uchar p = img.at<uchar>(k, l);
                    ++hist[p];                    
                }
            }            
            // 局部直方图均衡化
            int sum = 0;
            uchar center = img.at<uchar>(i, j);
            for (int k = 0; k <= center; ++k) {
                sum += hist[k];
            }
            result.at<uchar>(i, j) = cv::saturate_cast<uchar>(sum*scalar);
        }
    }

    return result;
}
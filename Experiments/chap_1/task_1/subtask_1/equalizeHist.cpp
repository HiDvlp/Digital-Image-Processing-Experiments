// equalizeHist: 全局直方图均衡化
#include <opencv2/opencv.hpp>

cv:: Mat equalizeHist(cv::Mat img, int L=256) {
    int M = img.rows;
    int N = img.cols;
    
    // 统计全局直方图
    int hist[L] = {0};
    for (int i = 0; i < M; ++i) {
        const uchar* row = img.ptr<uchar>(i);
        for (int j = 0; j < N; ++j) {
            ++hist[row[j]];
        }
    }

    // 建立灰度映射表
    cv::Mat lutTable(1, L, CV_8UC1);
    double scale = (L-1.0) / (M * N);
    int sum = 0;
    for (int i = 0; i < L; ++i) {
        sum += hist[i];
        lutTable.at<uchar>(0, i) = cv::saturate_cast<uchar>(scale * sum);
    }
    
    // 实现灰度映射
    cv::Mat result;
    cv::LUT(img, lutTable, result);

    return result;
}
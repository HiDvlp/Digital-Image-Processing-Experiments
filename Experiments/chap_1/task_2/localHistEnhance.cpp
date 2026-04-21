#include <opencv2/opencv.hpp>

// 使用直方图统计量增强局部图像
cv::Mat localHistEnhance(const cv::Mat& img, double k0, double k1, double k2, double k3, double C, int winSize=3) {
    int M = img.rows;
    int N = img.cols;
    // 统计全局灰度分布直方图并归一化
    int hist[256] = {0};
    for (int i = 0; i < M; ++i) {
        const uchar* row_ptr = img.ptr<uchar>(i);
        for (int j = 0; j < N; ++j) {
            ++hist[row_ptr[j]];
        }
    }
    double histNormal[256] = {0};
    double scale = 1.0 / (M * N);
    for (int i = 0; i < 256; ++i) {
        histNormal[i] = hist[i] * scale;
    }
    // 统计全局灰度均值及方差
    double mG = 0.0;
    double mr2G = 0.0;
    double sigma2G = 0.0;
    for (int i = 0; i < 256; ++i) {
        mG += i*histNormal[i];
        mr2G += i*i*histNormal[i];
    }
    sigma2G = mr2G - mG * mG;

    cv::Mat result = img.clone();

    int half = winSize / 2;
    // 定义阈值
    const double k0mG = k0 * mG;
    const double k1mG = k1 * mG;
    const double k2_2_s2G = k2 * k2 * sigma2G;
    const double k3_2_s2G = k3 * k3 * sigma2G;

    for (int i = half; i <= M-1-half; ++i) {
        for (int j = half; j <= N-1-half; ++j) {
            // 统计局部灰度均值及方差
            double sum_r = 0.0;
            double sum_r2 = 0.0;
            for (int i0 = -half; i0 <= half; ++i0) {
                const uchar* row_ptr = img.ptr<uchar>(i+i0);
                for (int j0 = -half; j0 <= half; ++j0) {
                    uchar r = row_ptr[j+j0];
                    sum_r += r;
                    sum_r2 += r*r;
                }
            }
            double mSxy = sum_r / (winSize*winSize);
            double sigma2Sxy = sum_r2 / (winSize*winSize) - mSxy * mSxy;
            // 局部增强
            if (mSxy >= k0mG && mSxy <= k1mG && sigma2Sxy >= k2_2_s2G && sigma2Sxy <= k3_2_s2G) {
                result.at<uchar>(i, j) = cv::saturate_cast<uchar>(img.at<uchar>(i, j) * C);
            }
        }
    }
    
    return result;
}
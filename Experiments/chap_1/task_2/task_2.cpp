#include <opencv2/opencv.hpp>
#include "localHistEnhance.hpp"
#include <string>
#include <format>

int main() {
    // 读取图像
    cv::Mat img = cv::imread("1-1.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "错误：无法加载图像，请检查路径是否正确。\n";
        return -1;
    }
    // 处理图像
    double k0 = 0.0;
    double k1 = 1.0;
    double k2 = 0.0;
    double k3 = 1.0;
    double C = 1.0;
    int winSize = 3;
    std::cout << "请输入参数设定值：\nk0 = \n";
    std::cin >> k0;
    std::cout << "k1 = \n";
    std::cin >> k1;
    std::cout << "k2 = \n";
    std::cin >> k2;
    std::cout << "k3 = \n";
    std::cin >> k3;
    std::cout << "C = \n";
    std::cin >> C;
    cv::Mat processed_img = localHistEnhance(img, k0, k1, k2, k3, C, winSize);
    std::cout << "winSize = \n";
    std::cin >> winSize;

    // 显示图像
    cv::namedWindow("Processed Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Processed Image", processed_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    // 保存图像
    std::string s = cv::format("Processed Image (k0 = %.2f, k1 = %.2f, k2 = %.2f, k3 = %.2f, C = %.2f, winSize = %d).jpg", k0, k1, k2, k3, C, winSize);
    cv::imwrite(s, processed_img);

    return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat image = imread("Fan Zhendong.jpg");
    // 检查图像是否成功加载
    if (image.empty()) {
        cout << "错误：无法加载图像，请检查路径是否正确。\n";        
    }
    // 显示图像
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    // 等待按键
    waitKey(0);
    // 关闭窗口
    destroyAllWindows();
    
    // 保存图像
    bool isSaved = imwrite("saved_image.jpg", image);
    if (isSaved) {
        cout << "图像保存成功！\n";
    } else {
        cout << "图像保存失败！\n";
    }
    
    // 获取图像属性
    int width = image.cols; // 图像宽度
    int height = image.rows; // 图像高度
    int channels = image.channels(); // 图像通道数

    cout << "图像宽度：" << width << "\n";
    cout << "图像高度：" << height << "\n";
    cout << "图像通道数：" << channels << "\n";

    // 访问像素值（BGR格式）
    Vec3b pixel = image.at<Vec3b>(100, 100); // 获取(100, 100)位置的像素值
    cout << "B: " << (int)pixel[0] << ", G: " << (int)pixel[1] << ", R: " << (int)pixel[2] << "\n";
    // cout << "B: " << pixel[0] << ", G: " << pixel[1] << ", R: " << pixel[2] << "\n";

    // 修改像素值（BGR格式）
    // for (int i = 0; i < image.rows; i++) {
    //     for (int j = 0; j < image.cols; j++) {
    //         image.at<Vec3b>(i, j) = Vec3b(255, 0, 0);
    //     }
    // }
    image.at<Vec3b>(0, 0) = Vec3b(255, 0, 0);
    imshow("Modified Image", image);
    waitKey(0);
    destroyAllWindows();

    // 转换为灰度图像
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    imshow("Gray Image", grayImage);
    waitKey(0);
    destroyAllWindows();

    // 图像的复制与克隆
    // 复制图像
    Mat copiedImage = image.clone();
    // 修改复制的图像
    circle(copiedImage, Point(100, 100), 50, Scalar(0, 255, 0), 2); // 在复制的图像上画一个圆
    imshow("Copied Image", copiedImage);
    waitKey(0);
    destroyAllWindows();

    // 图像的几何变换
    Mat rotatedImage;
    Point2f center(image.cols / 2, image.rows / 2); // 旋转中心
    double angle = 45;
    double scale = 1.0;
    Mat rotationMatrix = getRotationMatrix2D(center, angle, scale);
    warpAffine(image, rotatedImage, rotationMatrix, image.size());
    imshow("Rotated Image", rotatedImage);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
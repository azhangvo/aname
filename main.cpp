#include <opencv2/opencv.hpp>

int main() {
    cv::Mat mat(400, 400, CV_32F);

    cv::circle(mat, cv::Point(200, 200), 150, cv::Scalar(255, 0, 0), -1);

    cv::imshow("Window", mat);

    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

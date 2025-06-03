#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 로드
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // 이미지 정보 출력
    std::cout << "크기: " << img.cols << " x " << img.rows << std::endl;  // 너비 × 높이
    std::cout << "채널 수: " << img.channels() << std::endl;              // 3채널이면 BGR

    // 특정 픽셀의 색상 값 읽기 (주의: (y, x) 순서임)
    cv::Vec3b pixel = img.at<cv::Vec3b>(100, 100);  // 100행, 100열의 픽셀
    std::cout << "픽셀 (100,100)의 BGR 값 → "
        << "B: " << static_cast<int>(pixel[0]) << ", "
        << "G: " << static_cast<int>(pixel[1]) << ", "
        << "R: " << static_cast<int>(pixel[2]) << std::endl;

    return 0;
}
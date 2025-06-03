#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 로드
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // Grayscale 변환
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // 이미지 저장 (성공 여부 반환됨)
    bool success = cv::imwrite("../../resources/gray_output.jpg", gray);
    if (success)
        std::cout << "이미지 저장 완료: gray_output.jpg" << std::endl;
    else
        std::cerr << "이미지 저장 실패!" << std::endl;

    return 0;
}
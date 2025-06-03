#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 로드
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // BGR 컬러 이미지를 Grayscale로 변환
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);  // 변환 코드: BGR → GRAY

    // 결과 출력
    cv::imshow("02 - Grayscale 이미지", gray);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
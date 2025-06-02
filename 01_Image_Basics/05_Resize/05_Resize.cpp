#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. 이미지 읽기 (경로는 ../../resources/image.webp)
    cv::Mat img = cv::imread("../../resources/image.webp");

    // 2. 유효성 검사: 파일이 없거나 손상된 경우
    if (img.empty()) {
        std::cerr << "❌ 이미지를 불러올 수 없습니다. 경로를 확인하세요!" << std::endl;
        return -1;
    }

    // 3. 비율 기반 리사이즈 (0.5배 축소)
    cv::Mat halfSizeImg;
    cv::resize(img, halfSizeImg, cv::Size(), 0.5, 0.5);  // 가로, 세로 비율 각각 50%

    // 4. 절대 크기 리사이즈 (300x300으로 강제 설정)
    cv::Mat fixedSizeImg;
    cv::resize(img, fixedSizeImg, cv::Size(300, 300));  // cv::Size(width, height)

    // 5. 출력
    cv::imshow("05 - 원본 이미지", img);
    cv::imshow("05 - 절반 크기 이미지 (비율 기반)", halfSizeImg);
    cv::imshow("05 - 300x300 이미지 (절대 크기)", fixedSizeImg);

    // 6. 키 입력 대기 후 종료
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. 이미지 불러오기
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "❌ 이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // 2. 밝기/명암 조절
    // alpha: 명암(contrast) 계수, beta: 밝기(brightness) 변화값
    double alpha = 1.0;   // 기본은 1.0 (명암 그대로 유지)
    int beta = 50;        // 밝기 +50 증가

    cv::Mat brightImg;
    img.convertTo(brightImg, -1, alpha, beta);  // dst = src * alpha + beta

    // 3. 어둡게 만들기 (beta 음수)
    cv::Mat darkImg;
    img.convertTo(darkImg, -1, alpha, -50);  // 밝기 -50

    // 4. 명암 높이기 (alpha > 1.0)
    cv::Mat highContrast;
    img.convertTo(highContrast, -1, 1.5, 0);  // 명암 1.5배

    // 5. 출력
    cv::imshow("08 - 원본", img);
    cv::imshow("08 - 밝기 +50", brightImg);
    cv::imshow("08 - 밝기 -50", darkImg);
    cv::imshow("08 - 명암 1.5배", highContrast);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
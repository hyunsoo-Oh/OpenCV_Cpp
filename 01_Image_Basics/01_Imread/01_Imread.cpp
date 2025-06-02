#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 파일을 불러옵니다 (상대 경로 또는 절대 경로 지정 가능)
    cv::Mat img = cv::imread("../../resources/image.webp");

    // 파일이 제대로 로드되지 않았을 경우 예외 처리
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다! 경로를 확인하세요." << std::endl;
        return -1;
    }

    // OpenCV 윈도우에 이미지 출력
    cv::imshow("01 - 원본 이미지", img);

    // 아무 키나 입력될 때까지 대기 (0이면 무한 대기)
    cv::waitKey(0);

    // 모든 OpenCV 윈도우 종료
    cv::destroyAllWindows();

    return 0;
}

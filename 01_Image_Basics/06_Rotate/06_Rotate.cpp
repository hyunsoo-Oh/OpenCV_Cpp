#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. 이미지 불러오기
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "❌ 이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // 2. 시계 방향 90도 회전
    cv::Mat rotatedCW;
    cv::rotate(img, rotatedCW, cv::ROTATE_90_CLOCKWISE);  // 오른쪽으로 90도

    // 3. 반시계 방향 90도 회전
    cv::Mat rotatedCCW;
    cv::rotate(img, rotatedCCW, cv::ROTATE_90_COUNTERCLOCKWISE);  // 왼쪽으로 90도

    // 4. 180도 회전
    cv::Mat rotated180;
    cv::rotate(img, rotated180, cv::ROTATE_180);  // 상하 반전 + 좌우 반전

    // 5. 이미지 출력
    cv::imshow("06 - 원본 이미지", img);
    cv::imshow("06 - 시계 방향 90도", rotatedCW);
    cv::imshow("06 - 반시계 방향 90도", rotatedCCW);
    cv::imshow("06 - 180도 회전", rotated180);

    // 6. 키 입력 대기 및 종료
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

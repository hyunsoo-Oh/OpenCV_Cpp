#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. 이미지 불러오기
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "❌ 이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // 2. 관심 영역 정의 (ROI)
    // Rect(x, y, width, height) → 시작 위치와 크기
    // (100, 100) 위치부터 200x200 영역을 자름
    cv::Rect roi(150, 100, 250, 200);

    // 3. ROI로 잘라낸 부분을 새로운 Mat로 생성
    cv::Mat cropped = img(roi);

    // 4. 잘라낸 부분을 복사해서 별도의 객체로 저장 (선택사항)
    cv::Mat copiedCropped;
    cropped.copyTo(copiedCropped);  // 원본 영향 없이 별도로 사용하고 싶을 때

    // 5. 출력
    cv::imshow("07 - 원본 이미지", img);
    cv::imshow("07 - 잘라낸 영역 (ROI)", cropped);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

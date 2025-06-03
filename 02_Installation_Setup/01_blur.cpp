#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. 이미지 파일 불러오기
    // 상대경로 기준: ../../resources/image.webp
    cv::Mat img = cv::imread("../../resources/image.webp");

    // 2. 파일이 정상적으로 로드되지 않은 경우 예외 처리
    if (img.empty()) {
        std::cerr << "? 이미지를 불러올 수 없습니다. 경로를 확인하세요!" << std::endl;
        return -1;
    }

    // 3. 평균 블러 (Box Blur)
    // 커널 크기: 5x5 -> 현재 픽셀을 포함한 주변 25픽셀의 평균값으로 대체
    cv::Mat blurImg;
    cv::blur(img, blurImg, cv::Size(5, 5));

    // 4. 가우시안 블러
    // 주변 픽셀을 가중 평균(중심에 가까운 값에 더 높은 가중치)하여 부드러운 흐림 효과를 생성
    cv::Mat gaussImg;
    cv::GaussianBlur(img, gaussImg, cv::Size(5, 5), 1.5);
    // cv::Size(5,5): 필터 커널 크기
    // 1.5: 시그마(Sigma) 값, 흐림 강도 제어

    // 5. 이미지 출력
    cv::imshow("01 - 원본 이미지", img);
    cv::imshow("01 - 평균 블러 (5x5)", blurImg);
    cv::imshow("01 - 가우시안 블러 (5x5)", gaussImg);

    // 6. 키 입력 대기 및 창 종료
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
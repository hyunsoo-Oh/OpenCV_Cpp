#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �̹��� �ε�
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�!" << std::endl;
        return -1;
    }

    // BGR �÷� �̹����� Grayscale�� ��ȯ
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);  // ��ȯ �ڵ�: BGR �� GRAY

    // ��� ���
    cv::imshow("02 - Grayscale �̹���", gray);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

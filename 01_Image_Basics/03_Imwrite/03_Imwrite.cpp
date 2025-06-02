#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �̹��� �ε�
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�!" << std::endl;
        return -1;
    }

    // Grayscale ��ȯ
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // �̹��� ���� (���� ���� ��ȯ��)
    bool success = cv::imwrite("../../resources/gray_output.jpg", gray);
    if (success)
        std::cout << "�̹��� ���� �Ϸ�: gray_output.jpg" << std::endl;
    else
        std::cerr << "�̹��� ���� ����!" << std::endl;

    return 0;
}

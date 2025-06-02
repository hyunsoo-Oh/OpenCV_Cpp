#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �̹��� �ε�
    cv::Mat img = cv::imread("../../resources/image.webp");
    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�!" << std::endl;
        return -1;
    }

    // �̹��� ���� ���
    std::cout << "ũ��: " << img.cols << " x " << img.rows << std::endl;  // �ʺ� �� ����
    std::cout << "ä�� ��: " << img.channels() << std::endl;              // 3ä���̸� BGR

    // Ư�� �ȼ��� ���� �� �б� (����: (y, x) ������)
    cv::Vec3b pixel = img.at<cv::Vec3b>(100, 100);  // 100��, 100���� �ȼ�
    std::cout << "�ȼ� (100,100)�� BGR �� �� "
        << "B: " << static_cast<int>(pixel[0]) << ", "
        << "G: " << static_cast<int>(pixel[1]) << ", "
        << "R: " << static_cast<int>(pixel[2]) << std::endl;

    return 0;
}

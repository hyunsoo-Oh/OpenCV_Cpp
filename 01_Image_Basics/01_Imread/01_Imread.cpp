#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �̹��� ������ �ҷ��ɴϴ� (��� ��� �Ǵ� ���� ��� ���� ����)
    cv::Mat img = cv::imread("../../resources/image.webp");

    // ������ ����� �ε���� �ʾ��� ��� ���� ó��
    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�! ��θ� Ȯ���ϼ���." << std::endl;
        return -1;
    }

    // OpenCV �����쿡 �̹��� ���
    cv::imshow("01 - ���� �̹���", img);

    // �ƹ� Ű�� �Էµ� ������ ��� (0�̸� ���� ���)
    cv::waitKey(0);

    // ��� OpenCV ������ ����
    cv::destroyAllWindows();

    return 0;
}

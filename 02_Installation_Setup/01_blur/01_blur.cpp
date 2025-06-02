#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. �̹��� ���� �ҷ�����
    // ����� ����: ../../resources/image.webp
    cv::Mat img = cv::imread("../../resources/image.webp");

    // 2. ������ ���������� �ε���� ���� ��� ���� ó��
    if (img.empty()) {
        std::cerr << "? �̹����� �ҷ��� �� �����ϴ�. ��θ� Ȯ���ϼ���!" << std::endl;
        return -1;
    }

    // 3. ��� �� (Box Blur)
    // Ŀ�� ũ��: 5x5 -> ���� �ȼ��� ������ �ֺ� 25�ȼ��� ��հ����� ��ü
    cv::Mat blurImg;
    cv::blur(img, blurImg, cv::Size(5, 5));

    // 4. ����þ� ��
    // �ֺ� �ȼ��� ���� ���(�߽ɿ� ����� ���� �� ���� ����ġ)�Ͽ� �ε巯�� �帲 ȿ���� ����
    cv::Mat gaussImg;
    cv::GaussianBlur(img, gaussImg, cv::Size(5, 5), 1.5);
    // cv::Size(5,5): ���� Ŀ�� ũ��
    // 1.5: �ñ׸�(Sigma) ��, �帲 ���� ����

    // 5. �̹��� ���
    cv::imshow("01 - ���� �̹���", img);
    cv::imshow("01 - ��� �� (5x5)", blurImg);
    cv::imshow("01 - ����þ� �� (5x5)", gaussImg);

    // 6. Ű �Է� ��� �� â ����
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

# 📘 OpenCV C++

## 🗂 커리큘럼 개요

| 학습 주제 | 주요 학습 내용 | 실습 및 과제 |
|-----------|----------------|---------------|
| 컴퓨터 비전 개요 및 영상 이해 | - 컴퓨터 비전이란<br>- 영상 표현 구조<br>- 영상 획득 방식<br>- 그레이스케일 & 컬러 영상 | 영상의 RGB, Grayscale 변환 실습 |
| OpenCV 설치 및 기본 사용 | - OpenCV 설치 (Windows/Linux)<br>- 기본 프로젝트 구성<br>- 주요 함수 (imshow, imread 등) | HelloCV 구현, OpenCV 환경 셋업 |
| OpenCV 주요 클래스 이해 | - `Point`, `Size`, `Rect`, `Mat`, `Scalar`, `Vec` 등<br>- 행렬 구조 이해 및 조작 | `Mat` 클래스 사용한 이미지 행렬 분석 |
| 영상 입출력 및 기본 처리 | - 카메라/동영상 파일 처리<br>- 기본 그리기 함수<br>- 키/마우스 이벤트 처리 | 실시간 카메라 출력 및 마우스 이벤트 적용 |
| 영상 밝기/명암비/히스토그램 | - 밝기/명암 조절<br>- 히스토그램 평활화 & 스트레칭<br>- 트랙바 연동 | 트랙바로 밝기 조절, 히스토그램 시각화 |
| 산술 및 논리 연산, 필터링 | - 영상 간 연산<br>- 블러링, 샤프닝, 잡음 제거<br>- 필터 마스크 적용 | 평균, 가우시안, 언샤프 마스크 적용 비교 |
| 기하학적 변환 | - 어파인/투시 변환<br>- 회전, 이동, 확대, 전단, 대칭 | 다양한 변환 실습 및 시각적 비교 |
| 에지 검출 및 형태 검출 | - 미분, 그래디언트<br>- Canny, 허프 변환<br>- 직선/원 검출 | 이미지에서 직선, 원 검출 실습 |
| 컬러 영상 처리 및 이진화 | - 색공간 변환 (HSV 등)<br>- 채널 분리<br>- 이진화 & 모폴로지 연산 | 색상 범위 기반 객체 추출, 팽창/침식 |
| 객체 검출 기초 및 지역 특징점 | - 템플릿 매칭<br>- 코너 검출<br>- 특징점 추출 및 매칭 | SIFT/ORB 기반 이미지 매칭 실습 |
| 머신 러닝 & 딥러닝 기초 | - k-NN, SVM<br>- CNN, GAN, Vision Transformer<br>- DNN 모듈 사용법 | 필기체 숫자 인식 모델 적용 |
| 고급 응용 및 실무 프로젝트 | - YOLO, EfficientDET, U-Net<br>- 이미지 생성 (StyleGAN 등)<br>- 의료/건설 분야 사례 분석 | 학습 모델 적용 및 최종 프로젝트 작성 |

## ⚙️ Directory.Build.props
```
<?xml version="1.0" encoding="utf-8"?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003">

	<PropertyGroup>
		<!-- OpenCV 경로 직접 지정 -->
		<OpenCVIncludeDir>D:\OpenCV\build\include</OpenCVIncludeDir>
		<OpenCVLibDir>D:\OpenCV\build\x64\vc16\lib</OpenCVLibDir>
	</PropertyGroup>

	<ItemDefinitionGroup>
		<ClCompile>
			<AdditionalIncludeDirectories>
				$(OpenCVIncludeDir);
				%(AdditionalIncludeDirectories)
			</AdditionalIncludeDirectories>
		</ClCompile>
		<Link>
			<AdditionalLibraryDirectories>
				$(OpenCVLibDir);
				%(AdditionalLibraryDirectories)
			</AdditionalLibraryDirectories>
			<AdditionalDependencies>
				opencv_world4110d.lib;
				%(AdditionalDependencies)
			</AdditionalDependencies>
		</Link>
	</ItemDefinitionGroup>

</Project>
```

## ⚙️ OpenCV C++ 설치 방법

### 🪟 Windows (MSVC + CMake + OpenCV prebuilt)

OpenCV 공식 사이트에서 Windows용 zip 파일 다운로드

예: opencv-4.8.0-windows.exe 설치 → C:\opencv에 압축 해제

Visual Studio에서 프로젝트 설정:

Include 디렉토리: C:\opencv\build\include

Library 디렉토리: C:\opencv\build\x64\vc16\lib

추가 종속성: opencv_world480.lib

실행 파일과 동일한 폴더에 opencv_world480.dll 복사

### 🐧 Linux (Ubuntu 기준)
```
sudo apt update && sudo apt install -y \
    build-essential cmake git pkg-config \
    libjpeg-dev libpng-dev libtiff-dev \
    libavcodec-dev libavformat-dev libswscale-dev \
    libv4l-dev v4l-utils \
    libgtk-3-dev libcanberra-gtk* \
    libatlas-base-dev gfortran \
    libxvidcore-dev libx264-dev libopenblas-dev liblapack-dev libhdf5-dev

# 소스 다운로드
mkdir ~/opencv_build && cd ~/opencv_build

# OpenCV와 Extra 모듈
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv && git checkout 4.8.0
cd ../opencv_contrib && git checkout 4.8.0

# 빌드 디렉토리 생성 및 설정
cd ~/opencv_build
mkdir build && cd build

# CMake 구성
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
      -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON \
      -D BUILD_TESTS=OFF -D BUILD_EXAMPLES=OFF \
      ../opencv

# 빌드 및 설치
make -j$(nproc)
sudo make install
sudo ldconfig
```
### 🍓 Raspberry Pi (Raspberry Pi OS 기준)
```
# 필수 의존성 설치
sudo apt update && sudo apt install -y \
    build-essential cmake git pkg-config \
    libjpeg-dev libpng-dev libtiff-dev \
    libavcodec-dev libavformat-dev libswscale-dev \
    libv4l-dev v4l-utils \
    libgtk-3-dev libcanberra-gtk* \
    libatlas-base-dev gfortran \
    libxvidcore-dev libx264-dev libopenblas-dev liblapack-dev libhdf5-dev

# 소스 다운로드 및 빌드 (위와 동일)
mkdir ~/opencv_build && cd ~/opencv_build
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv && git checkout 4.8.0
cd ../opencv_contrib && git checkout 4.8.0

mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
      -D ENABLE_NEON=ON -D ENABLE_VFPV3=ON \
      -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON \
      -D BUILD_TESTS=OFF -D BUILD_EXAMPLES=OFF \
      ../opencv

make -j$(nproc)
sudo make install
sudo ldconfig
```
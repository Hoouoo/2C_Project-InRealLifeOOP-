#ifndef SPEEDINGCAM_H
#define SPEEDINGCAM_H
#include "Camera.h"


class SpeedingCam :virtual public Camera {  // 과속카메라의 정보를 담고있는 클래스, virtual 키워드를 사용하여 카메라 클래스를 가상 상속
public:
	SpeedingCam();  // 기본생성자
	int Carspeed; // 과속 카메라가 포착한 자동차 속도  rand를 통해 임의로 값을 입력받음
	bool Overspeed();  // 과속 확인
	bool SchoolzoneCam();  // 어린이 보호구역 과속카메라 제한속도 30
	bool DowntownroadCam(); // 시내도로 보호구역 과속카메라  제한속도 40
	bool NationalroadCam(); // 국도 과속카메라 제한속도 80
	bool SpeedwayCam();  // 고속화도로 과속카메라 제한속도 90
	bool HighwayCam(); // 고속도로 과속카메라 제한속도 100
	virtual ~SpeedingCam(); // 가상함수로 소멸자를 선언하여 파생클래스의 소멸자와 기본클래스의 소멸자를 모두 실행
};
#endif
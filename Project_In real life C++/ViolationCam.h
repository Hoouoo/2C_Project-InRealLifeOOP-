#ifndef VIOLATIONCAM_H
#define VIOLATIONCAM_H

#include "Camera.h"
class ViolationCam :virtual public Camera{  // 위반카메라의 정보를 담는 클래스, virtual 키워드를 사용하여 카메라 클래스 가상 상속
public:
	ViolationCam();  // 기본 생성자
	int Carstatus;  // 자동차가 정지했는지 움직이는지 확인하기 위한 변수( 0이면 정지, 1이면 움직임)
	bool Move();  // 위반 여부를 확인해주는 핵심함수
	bool SignalCam();  // 신호 위반 카메라
	bool ParkingCam();  // 주정차 위반 카메라
	virtual ~ViolationCam(); // 가상함수로 소멸자를 선언하여 파생클래스의 소멸자와 기본클래스의 소멸자를 모두 실행
};
#endif
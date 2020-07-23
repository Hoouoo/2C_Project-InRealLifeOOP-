#ifndef SIGNALSPEEDINGCAM_H
#define SIGNALSPEEDINGCAM_H
#include "SpeedingCam.h"
#include "ViolationCam.h"

class SignalSpeedingCam : public SpeedingCam, public ViolationCam {// 신호과속 단속카메라는 과속카메라 클래스 + 신호위반 카메라 클래스를 다중 상속
public:
	SignalSpeedingCam();  // 기본 생성자
	int Signal30SpeedControlCam();  // 제한속도 30 신호과속단속카메라, 리턴 값 1: 과속, 2: 신호위반
	int Signal40SpeedControlCam();  // 제한속도 40 신호과속단속카메라, 리턴 값 1: 과속, 2: 신호위반
	virtual ~SignalSpeedingCam(); // 가상함수로 소멸자를 선언하여 파생클래스의 소멸자와 기본클래스의 소멸자를 모두 실행
};
#endif

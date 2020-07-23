#include "SignalSpeedingCam.h"

SignalSpeedingCam::SignalSpeedingCam() {
	srand((unsigned)time(NULL)); // 자동차의 속도를 랜덤으로 받기 위해 선언
}

int SignalSpeedingCam::Signal30SpeedControlCam() { // 제한속도 30 신호과속 단속 카메라
	if (SchoolzoneCam() == true) {// 과속인 경우
		setName("신호위반 및 과속단속 카메라(제한속도:30)");// 과속카메라 이름 재정의
		setLimit(30);  // 제한속도 재정의
		return 2;// 2 = 과속
	}
	else if (SignalCam() == true ) {// 신호위반인경우
		setName("신호위반 및 과속단속 카메라(제한속도:30)");// 과속카메라 이름 재정의
		setLimit(0);  // 제한 값 재정의
		return 1;// 1 = 신호위반
	}
	else {
		setName("신호위반 및 과속단속 카메라(제한속도:30)");// 과속카메라 이름 재정의
		setLimit(30);  // 제한속도 재정의
		return 0;
	}

}

int SignalSpeedingCam::Signal40SpeedControlCam() {  // 제한속도 30 신호과속 단속 카메라
	if (DowntownroadCam() == true) {// 과속인 경우
		setName("신호위반 및 과속단속 카메라(제한속도:40)");// 과속카메라 이름 재정의
		setLimit(40);  // 제한속도 재정의
		return 2;// 2 = 과속
	}
	else if (SignalCam() == true) {// 신호위반인경우
		setName("신호위반 및 과속단속 카메라(제한속도:40)");// 과속카메라 이름 재정의
		setLimit(0);  // 제한 시간 재정의
		return 1;// 1 = 신호위반
	}
	else {
		setName("신호위반 및 과속단속 카메라(제한속도:40)");// 과속카메라 이름 재정의
		setLimit(40);  // 제한속도 재정의
		return 0;
	}

}

SignalSpeedingCam::~SignalSpeedingCam(){}
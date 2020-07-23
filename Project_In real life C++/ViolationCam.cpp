#include "ViolationCam.h"

ViolationCam::ViolationCam() {
	srand((unsigned)time(NULL)); // 자동차의 이동 정보를 랜덤으로 받기 위해 선언, 0이면 정지 1이면 움직임
	Carstatus = 0;
}

bool ViolationCam::Move() {
	if (Carstatus > getLimit())  // 자동차의 상태가 0이아니면
		return true;  // 움직인걸로 판단 
	else
		return false;
}

bool ViolationCam::SignalCam() {
	setName("신호위반카메라");
	Carstatus = rand() % 5 - 3;  // 0이면 정지, 1이면 신호위반으로 판단, 너무 많은 신호위반이 나오지 않게 하기 위해 범위를 -3 ~ 1로 지정
	setLimit(0);  // 제한속도를 0으로 두어 0을 넘으면 신호위반
	if (Move() == true)
		return true;  // 위반
	else
		return false;

}

bool ViolationCam::ParkingCam() {
	setName("주정차위반카메라");
	Carstatus = rand() % 10;  // 0~9 분의 임의의 값을 받으며, 5이상의 값이 나오면 주정차 위반
	setLimit(5);  // 최대 주정차할 수 있는 시간을 5분으로 세팅
	if (Move() == true) 
		return true;  // 위반
	else
		return false;  
}

ViolationCam::~ViolationCam() {}
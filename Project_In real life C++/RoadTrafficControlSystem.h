#ifndef ROADCONTROLSYSTEM_H
#define ROADCONTROLSYSTEM_H
#include "SignalSpeedingCam.h"

class  RoadTrafficControlSystem{
	SignalSpeedingCam* SignalSpeedingCamList;  // 다중 상속받은 신호 과속클래스를 객체로 사용
	void info(int num = 0);  // 설치된 단속 카메라의 종류 및 정보, 디폴트 매개변수를 사용
	void speedingPenaltylist();  // 과속한 속도에 따른 벌금 및 범칙금을 나타내는 기준표
	void speedingPenalize(int nowspeed, int idxnum);  // 과속시 패널티 기준표를 토대로 범칙금 처리 함수 int nowspeed = (SignalSpeedingCam + listnum)->Carspeed, idxnum = SignalSpeedingCam 객체의 배열 인덱스
	void signalspeedingStatus(int select3_num);  // 신호 위반 및 과속 단속처리 함수
	void speedingStatus(int select_num); // speedingPenalize를 이용하여 과속 단속처리함수
	void violationStatus(int select2_num);// 신호 및 주정차 위반 단속처리함수
public:
	RoadTrafficControlSystem();  // 기본생성자
	void start();  // 시스템 실행
	~RoadTrafficControlSystem();  // 소멸자
};

#endif
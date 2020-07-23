#ifndef ROADCONTROLSYSTEM_H
#define ROADCONTROLSYSTEM_H
#include "SignalSpeedingCam.h"

class  RoadTrafficControlSystem{
	SignalSpeedingCam* SignalSpeedingCamList;  // ���� ��ӹ��� ��ȣ ����Ŭ������ ��ü�� ���
	void info(int num = 0);  // ��ġ�� �ܼ� ī�޶��� ���� �� ����, ����Ʈ �Ű������� ���
	void speedingPenaltylist();  // ������ �ӵ��� ���� ���� �� ��Ģ���� ��Ÿ���� ����ǥ
	void speedingPenalize(int nowspeed, int idxnum);  // ���ӽ� �г�Ƽ ����ǥ�� ���� ��Ģ�� ó�� �Լ� int nowspeed = (SignalSpeedingCam + listnum)->Carspeed, idxnum = SignalSpeedingCam ��ü�� �迭 �ε���
	void signalspeedingStatus(int select3_num);  // ��ȣ ���� �� ���� �ܼ�ó�� �Լ�
	void speedingStatus(int select_num); // speedingPenalize�� �̿��Ͽ� ���� �ܼ�ó���Լ�
	void violationStatus(int select2_num);// ��ȣ �� ������ ���� �ܼ�ó���Լ�
public:
	RoadTrafficControlSystem();  // �⺻������
	void start();  // �ý��� ����
	~RoadTrafficControlSystem();  // �Ҹ���
};

#endif
#ifndef SIGNALSPEEDINGCAM_H
#define SIGNALSPEEDINGCAM_H
#include "SpeedingCam.h"
#include "ViolationCam.h"

class SignalSpeedingCam : public SpeedingCam, public ViolationCam {// ��ȣ���� �ܼ�ī�޶�� ����ī�޶� Ŭ���� + ��ȣ���� ī�޶� Ŭ������ ���� ���
public:
	SignalSpeedingCam();  // �⺻ ������
	int Signal30SpeedControlCam();  // ���Ѽӵ� 30 ��ȣ���Ӵܼ�ī�޶�, ���� �� 1: ����, 2: ��ȣ����
	int Signal40SpeedControlCam();  // ���Ѽӵ� 40 ��ȣ���Ӵܼ�ī�޶�, ���� �� 1: ����, 2: ��ȣ����
	virtual ~SignalSpeedingCam(); // �����Լ��� �Ҹ��ڸ� �����Ͽ� �Ļ�Ŭ������ �Ҹ��ڿ� �⺻Ŭ������ �Ҹ��ڸ� ��� ����
};
#endif

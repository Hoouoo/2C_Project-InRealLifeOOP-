#ifndef SPEEDINGCAM_H
#define SPEEDINGCAM_H
#include "Camera.h"


class SpeedingCam :virtual public Camera {  // ����ī�޶��� ������ ����ִ� Ŭ����, virtual Ű���带 ����Ͽ� ī�޶� Ŭ������ ���� ���
public:
	SpeedingCam();  // �⺻������
	int Carspeed; // ���� ī�޶� ������ �ڵ��� �ӵ�  rand�� ���� ���Ƿ� ���� �Է¹���
	bool Overspeed();  // ���� Ȯ��
	bool SchoolzoneCam();  // ��� ��ȣ���� ����ī�޶� ���Ѽӵ� 30
	bool DowntownroadCam(); // �ó����� ��ȣ���� ����ī�޶�  ���Ѽӵ� 40
	bool NationalroadCam(); // ���� ����ī�޶� ���Ѽӵ� 80
	bool SpeedwayCam();  // ���ȭ���� ����ī�޶� ���Ѽӵ� 90
	bool HighwayCam(); // ��ӵ��� ����ī�޶� ���Ѽӵ� 100
	virtual ~SpeedingCam(); // �����Լ��� �Ҹ��ڸ� �����Ͽ� �Ļ�Ŭ������ �Ҹ��ڿ� �⺻Ŭ������ �Ҹ��ڸ� ��� ����
};
#endif
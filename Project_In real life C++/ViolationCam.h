#ifndef VIOLATIONCAM_H
#define VIOLATIONCAM_H

#include "Camera.h"
class ViolationCam :virtual public Camera{  // ����ī�޶��� ������ ��� Ŭ����, virtual Ű���带 ����Ͽ� ī�޶� Ŭ���� ���� ���
public:
	ViolationCam();  // �⺻ ������
	int Carstatus;  // �ڵ����� �����ߴ��� �����̴��� Ȯ���ϱ� ���� ����( 0�̸� ����, 1�̸� ������)
	bool Move();  // ���� ���θ� Ȯ�����ִ� �ٽ��Լ�
	bool SignalCam();  // ��ȣ ���� ī�޶�
	bool ParkingCam();  // ������ ���� ī�޶�
	virtual ~ViolationCam(); // �����Լ��� �Ҹ��ڸ� �����Ͽ� �Ļ�Ŭ������ �Ҹ��ڿ� �⺻Ŭ������ �Ҹ��ڸ� ��� ����
};
#endif
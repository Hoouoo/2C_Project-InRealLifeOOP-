#include "ViolationCam.h"

ViolationCam::ViolationCam() {
	srand((unsigned)time(NULL)); // �ڵ����� �̵� ������ �������� �ޱ� ���� ����, 0�̸� ���� 1�̸� ������
	Carstatus = 0;
}

bool ViolationCam::Move() {
	if (Carstatus > getLimit())  // �ڵ����� ���°� 0�̾ƴϸ�
		return true;  // �����ΰɷ� �Ǵ� 
	else
		return false;
}

bool ViolationCam::SignalCam() {
	setName("��ȣ����ī�޶�");
	Carstatus = rand() % 5 - 3;  // 0�̸� ����, 1�̸� ��ȣ�������� �Ǵ�, �ʹ� ���� ��ȣ������ ������ �ʰ� �ϱ� ���� ������ -3 ~ 1�� ����
	setLimit(0);  // ���Ѽӵ��� 0���� �ξ� 0�� ������ ��ȣ����
	if (Move() == true)
		return true;  // ����
	else
		return false;

}

bool ViolationCam::ParkingCam() {
	setName("����������ī�޶�");
	Carstatus = rand() % 10;  // 0~9 ���� ������ ���� ������, 5�̻��� ���� ������ ������ ����
	setLimit(5);  // �ִ� �������� �� �ִ� �ð��� 5������ ����
	if (Move() == true) 
		return true;  // ����
	else
		return false;  
}

ViolationCam::~ViolationCam() {}
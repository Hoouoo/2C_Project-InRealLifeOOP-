#include "SpeedingCam.h"


SpeedingCam::SpeedingCam() {
	srand((unsigned)time(NULL)); // �ڵ����� �ӵ��� �������� �ޱ� ���� ����
	Carspeed = 0;  // ��� ���� �ʱ�ȭ
}

bool SpeedingCam::Overspeed() {  // ���� Ȯ�� 
	if (Carspeed > getLimit())   // �� �ӵ��� ���Ѽӵ����� ũ��
		return true;  // ����
	else 
		return false;  // ���� X  
}

bool  SpeedingCam::SchoolzoneCam() {
	setName("��̺�ȣ����");  
	setLimit(30);  
	Carspeed = 10 + rand() % 41; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ��� ��ȣ������ �ڵ��� �ӷ��� ������ 10~50 ���� ����
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::DowntownroadCam() {
	setName("�ó�����");
	setLimit(40);
	Carspeed = 10 + rand() % 61; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� �ó������� �ڵ��� �ӷ��� ������ 10~70 ���� ����
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::NationalroadCam() {
	setName("����");
	setLimit(80);
	Carspeed = 10 + rand() % 111; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 10~120 ���� ����
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::SpeedwayCam() {
	setName("����ȭ����");
	setLimit(90);
	Carspeed = 10 + rand() % 131; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 10~140 ���� ����
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool  SpeedingCam::HighwayCam() {
	setName("��ӵ���");
	setLimit(100);
	Carspeed = 10 + rand() % 171; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 0~180 ���� ����
		if (Overspeed() == true)
		return true;
	else
		return false;
}

SpeedingCam::~SpeedingCam() {}
#include "SignalSpeedingCam.h"

SignalSpeedingCam::SignalSpeedingCam() {
	srand((unsigned)time(NULL)); // �ڵ����� �ӵ��� �������� �ޱ� ���� ����
}

int SignalSpeedingCam::Signal30SpeedControlCam() { // ���Ѽӵ� 30 ��ȣ���� �ܼ� ī�޶�
	if (SchoolzoneCam() == true) {// ������ ���
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:30)");// ����ī�޶� �̸� ������
		setLimit(30);  // ���Ѽӵ� ������
		return 2;// 2 = ����
	}
	else if (SignalCam() == true ) {// ��ȣ�����ΰ��
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:30)");// ����ī�޶� �̸� ������
		setLimit(0);  // ���� �� ������
		return 1;// 1 = ��ȣ����
	}
	else {
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:30)");// ����ī�޶� �̸� ������
		setLimit(30);  // ���Ѽӵ� ������
		return 0;
	}

}

int SignalSpeedingCam::Signal40SpeedControlCam() {  // ���Ѽӵ� 30 ��ȣ���� �ܼ� ī�޶�
	if (DowntownroadCam() == true) {// ������ ���
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:40)");// ����ī�޶� �̸� ������
		setLimit(40);  // ���Ѽӵ� ������
		return 2;// 2 = ����
	}
	else if (SignalCam() == true) {// ��ȣ�����ΰ��
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:40)");// ����ī�޶� �̸� ������
		setLimit(0);  // ���� �ð� ������
		return 1;// 1 = ��ȣ����
	}
	else {
		setName("��ȣ���� �� ���Ӵܼ� ī�޶�(���Ѽӵ�:40)");// ����ī�޶� �̸� ������
		setLimit(40);  // ���Ѽӵ� ������
		return 0;
	}

}

SignalSpeedingCam::~SignalSpeedingCam(){}
#include "Car.h"


Car::Car() {
	srand((unsigned)time(NULL));
	Speed = 0;
	Car_num = new string[7];
}

int Car::randSpeed(int num) {
	switch (num) {
	case 1: {  // ��� ��ȣ����
		Speed = 10 + rand() % 41; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ��� ��ȣ������ �ڵ��� �ӷ��� ������ 10~50 ���� ����
		return Speed;
		break;
	}
	case 2: { // �ó�����
		Speed = 10 + rand() % 61; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� �ó������� �ڵ��� �ӷ��� ������ 10~70 ���� ����
		return Speed;
		break;
	}
	case 3: {  // ����
		Speed = 10 + rand() % 111; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 10~120 ���� ����
		return Speed;

		break;
	}
	case 4: {  // ���ȭ����
		Speed = 10 + rand() % 131; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 10~140 ���� ����
		return Speed;

		break;
	}
	case 5: {
		Speed = 10 + rand() % 171; // ����ġ�� ������ ���̳����� ���� �����ϱ� ���� ������ �ڵ��� �ӷ��� ������ 10~180 ���� ����
		return Speed;
		break;
	}
	}
}

void Car::randCar_num() {
	int random = rand() % 10;

	for(int idx=0; idx<2; idx++){  // �ڵ����� ��ȣ�� XX�� XXXX �� �����̹Ƿ� �� �α��ڴ� �����Է�
		int random1 = rand() % 10;
		Car_num[idx] = to_string(random1);
	}

	Car_num[2]= to_string(random); // �ѱۺκ�
	switch (random) {
	case 0: {
		Car_num[2] = "��";
		break;
	}
	case 1: {
		Car_num[2] = "��";
		break;
	}
	case 2: {
		Car_num[2] = "��";
		break;
	}
	default: {
		Car_num[2] = to_string(random); // �ѱۺκ�
		break;
	}
	}

	for (int idx = 3; idx < 7; idx++) {
		int random2 = rand() % 10;
		Car_num[idx] = to_string(random2);
	}
	for (int idx = 0; idx < 7; idx++)
		cout << Car_num[idx];
}

Car::~Car() {
	delete [] Car_num;
}
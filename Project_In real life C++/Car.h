#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Car
{
public:
	int Speed; // �ڵ����� �ӵ�
	string *Car_num;  // �ڵ����� ��ȣ
	Car(); // �⺻������
	void randCar_num();  // �ڵ��� ��ȣ�� ���Ƿ� ���ϴ� �Լ�
	int randSpeed(int num);  // �ڵ����� �ӵ��� ���Ƿ� �ο��ϴ� �Լ�
	~Car();
};

#endif

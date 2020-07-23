#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Camera {
	string name;  //ī�޶� �̸�
	int limit; // ī�޶��� ���Ѽӵ� �� ī�޶��� ���� ��
protected:  // �� �Է°� ������ ���� Ŭ������ �����ϵ��� ��ȣ
	void setName(string name);  // ī�޶� �̸� setter
	void setLimit(int limit);  // ���Ѽӵ� setter

public:
	Camera();  //  �⺻������
	string getName();  // ī�޶� �̸� getter;
	int getLimit();  // ���Ѽӵ� getter
	virtual ~Camera();  // �����Լ��� �Ҹ��ڸ� �����Ͽ� �Ļ�Ŭ������ �Ҹ��ڿ� �⺻Ŭ������ �Ҹ��ڸ� ��� ����
};

#endif
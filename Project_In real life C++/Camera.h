#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Camera {
	string name;  //카메라 이름
	int limit; // 카메라의 제한속도 및 카메라의 제한 값
protected:  // 값 입력과 수정은 관련 클래스만 가능하도록 보호
	void setName(string name);  // 카메라 이름 setter
	void setLimit(int limit);  // 제한속도 setter

public:
	Camera();  //  기본생성자
	string getName();  // 카메라 이름 getter;
	int getLimit();  // 제한속도 getter
	virtual ~Camera();  // 가상함수로 소멸자를 선언하여 파생클래스의 소멸자와 기본클래스의 소멸자를 모두 실행
};

#endif
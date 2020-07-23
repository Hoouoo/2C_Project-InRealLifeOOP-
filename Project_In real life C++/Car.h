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
	int Speed; // 자동차의 속도
	string *Car_num;  // 자동차의 번호
	Car(); // 기본생성자
	void randCar_num();  // 자동차 번호를 임의로 정하는 함수
	int randSpeed(int num);  // 자동차의 속도를 임의로 부여하는 함수
	~Car();
};

#endif

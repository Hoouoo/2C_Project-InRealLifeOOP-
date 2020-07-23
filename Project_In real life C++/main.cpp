#include "Car.h"


int main() {
	Car test;
	cout << "차량의 속도 : " << test.randSpeed(1) << endl;
	cout << "단속 된 차량 번호 : "; 
	test.randCar_num();
}
#include "Car.h"


Car::Car() {
	srand((unsigned)time(NULL));
	Speed = 0;
	Car_num = new string[7];
}

int Car::randSpeed(int num) {
	switch (num) {
	case 1: {  // 어린이 보호구역
		Speed = 10 + rand() % 41; // 지나치게 과속이 많이나오는 것을 방지하기 위해 어린이 보호구역의 자동차 속력의 범위를 10~50 으로 받음
		return Speed;
		break;
	}
	case 2: { // 시내도로
		Speed = 10 + rand() % 61; // 지나치게 과속이 많이나오는 것을 방지하기 위해 시내도로의 자동차 속력의 범위를 10~70 으로 받음
		return Speed;
		break;
	}
	case 3: {  // 국도
		Speed = 10 + rand() % 111; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 10~120 으로 받음
		return Speed;

		break;
	}
	case 4: {  // 고속화도로
		Speed = 10 + rand() % 131; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 10~140 으로 받음
		return Speed;

		break;
	}
	case 5: {
		Speed = 10 + rand() % 171; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 10~180 으로 받음
		return Speed;
		break;
	}
	}
}

void Car::randCar_num() {
	int random = rand() % 10;

	for(int idx=0; idx<2; idx++){  // 자동차의 번호판 XX가 XXXX 의 형태이므로 앞 두글자는 숫자입력
		int random1 = rand() % 10;
		Car_num[idx] = to_string(random1);
	}

	Car_num[2]= to_string(random); // 한글부분
	switch (random) {
	case 0: {
		Car_num[2] = "가";
		break;
	}
	case 1: {
		Car_num[2] = "나";
		break;
	}
	case 2: {
		Car_num[2] = "다";
		break;
	}
	default: {
		Car_num[2] = to_string(random); // 한글부분
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
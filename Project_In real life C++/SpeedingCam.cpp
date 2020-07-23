#include "SpeedingCam.h"


SpeedingCam::SpeedingCam() {
	srand((unsigned)time(NULL)); // 자동차의 속도를 랜덤으로 받기 위해 선언
	Carspeed = 0;  // 멤버 변수 초기화
}

bool SpeedingCam::Overspeed() {  // 과속 확인 
	if (Carspeed > getLimit())   // 차 속도가 제한속도보다 크면
		return true;  // 과속
	else 
		return false;  // 과속 X  
}

bool  SpeedingCam::SchoolzoneCam() {
	setName("어린이보호구역");  
	setLimit(30);  
	Carspeed = 10 + rand() % 41; // 지나치게 과속이 많이나오는 것을 방지하기 위해 어린이 보호구역의 자동차 속력의 범위를 10~50 으로 받음
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::DowntownroadCam() {
	setName("시내도로");
	setLimit(40);
	Carspeed = 10 + rand() % 61; // 지나치게 과속이 많이나오는 것을 방지하기 위해 시내도로의 자동차 속력의 범위를 10~70 으로 받음
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::NationalroadCam() {
	setName("국도");
	setLimit(80);
	Carspeed = 10 + rand() % 111; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 10~120 으로 받음
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool SpeedingCam::SpeedwayCam() {
	setName("과속화도로");
	setLimit(90);
	Carspeed = 10 + rand() % 131; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 10~140 으로 받음
	if (Overspeed() == true)
		return true;
	else
		return false;
}

bool  SpeedingCam::HighwayCam() {
	setName("고속도로");
	setLimit(100);
	Carspeed = 10 + rand() % 171; // 지나치게 과속이 많이나오는 것을 방지하기 위해 국도의 자동차 속력의 범위를 0~180 으로 받음
		if (Overspeed() == true)
		return true;
	else
		return false;
}

SpeedingCam::~SpeedingCam() {}
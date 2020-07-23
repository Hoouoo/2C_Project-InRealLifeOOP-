#include "RoadTrafficControlSystem.h"


RoadTrafficControlSystem::RoadTrafficControlSystem() {
	cout << "====================== 도로교통 관제 시스템입니다 ====================== " << endl;

	SignalSpeedingCamList = new SignalSpeedingCam[9];
	SignalSpeedingCamList->SchoolzoneCam();
	(SignalSpeedingCamList + 1)->DowntownroadCam();
	(SignalSpeedingCamList + 2)->NationalroadCam();
	(SignalSpeedingCamList + 3)->SpeedwayCam();
	(SignalSpeedingCamList + 4)->HighwayCam();
	(SignalSpeedingCamList + 5 )->SignalCam();
	(SignalSpeedingCamList + 6)->ParkingCam();
	(SignalSpeedingCamList + 7)->Signal30SpeedControlCam();
	(SignalSpeedingCamList + 8)->Signal40SpeedControlCam();
}

void RoadTrafficControlSystem::info(int num) {  // 설치된 카메라의 정보 출력
	if (num == 1) {  // num 값이 1이면 과속카메라 정보 출력
		for (int idx = 0; idx < 5; idx++) {
			cout << ">> [" << idx + 1 << "] " << (SignalSpeedingCamList + idx)->getName() << " ( 제한속도 : " << (SignalSpeedingCamList + idx)->getLimit() << " )" << endl;
		}
	}
	else if (num == 2) {  // num값이 2면 신호,주정차 위반 카메라 정보 출력
		for (int idx2= 5; idx2 < 7; idx2++) {
			cout << ">> [" << idx2 - 4 << "] " << (SignalSpeedingCamList + idx2)->getName() << endl;
		}
	}
	else if (num == 3) {
		for (int idx3 = 7; idx3 < 9; idx3++) {
			cout << ">> [" << idx3 - 6 << "] " << (SignalSpeedingCamList + idx3)->getName() << endl;
		}
	}

	else {
		int count = 0;  
		for (int idx = 0; idx < 5; idx++) {
			cout << ">> [" << idx + 1 << "] " << (SignalSpeedingCamList + idx)->getName() << " ( 제한속도 : " << (SignalSpeedingCamList + idx)->getLimit() << " )" << endl;
			count++;
		}
		for (int idx4 = 5; idx4 < 9; idx4++) {
			cout << ">> [" << idx4 + 1 << "] " << (SignalSpeedingCamList + idx4)->getName() << endl;
			count++;
		}
		cout << endl << "[NOTICE] 현재 설치된 카메라의 종류는 총 "<<count << "개 입니다." << endl;
	}
}

void RoadTrafficControlSystem::speedingPenaltylist() {  // 패널티 기준표 출력
	cout << "========================================================================" << endl;
	cout << "\t\t   [초과 속도에 따른 범칙금 및 벌점 기준표]" << endl << endl;
	cout << "\t'20km/h'이하 초과 시 \t   범칙금 40,000원  |  벌점 0점" << endl;
	cout << "'20km/h' 초과 '40km/h'이하 초과 시 범칙금 70,000원  |  벌점 15점" << endl;
	cout << "'40km/h' 초과 '60km/h'이하 초과 시 범칙금 100,000원 |  벌점 30점" << endl;
	cout << "\t'60km/h' 초과 시 \t   범칙금 130,000원 |  벌점 60점" << endl;
}

void RoadTrafficControlSystem::speedingPenalize(int nowspeed, int idxnum) {  // 패널티 기준표를 토대로 범칙금 처리 함수
	// nowspeed = (SignalSpeedingCamList + select_num)->Carspeed, idxnum = SignalSpeedingCamList 객체의 배열 인덱스
	if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 20 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) >= 0)
		cout << "[NOTICE] 범칙금 40,000원" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 20 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 40)
		cout << "[NOTICE] 범칙금 70,000원  |  벌점 15점" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 40 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 60)
		cout << "[NOTICE] 범칙금 100,000원 |  벌점 30점" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 60)
		cout << "[NOTICE] 범칙금 130,000원  |  벌점 60점" << endl;
}


void RoadTrafficControlSystem::speedingStatus(int select_num) {  //과속에 대한 벌점 및 범칙금 
	// select_num을 입력받아 각 구역별 과속 카메라를 선택하고, 선택한 과속카메라에 대한 판단
	switch (select_num) { 
		case 0: {
			if ((SignalSpeedingCamList + select_num)->SchoolzoneCam() == true) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 0);  // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리
			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}

		case 1: {
			if ((SignalSpeedingCamList + select_num)->DowntownroadCam() == true) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 1);  // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리

			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 2: {
			if ((SignalSpeedingCamList + select_num)->NationalroadCam() == true) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 2); // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리
			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 3: {
			if ((SignalSpeedingCamList + select_num)->SpeedwayCam() == true) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 3); // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리
			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 4: {
			if ((SignalSpeedingCamList + select_num)->HighwayCam() == true) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 4); // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리

			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 7: {  // 신호위반 및 과속카메라 부분
			if ((SignalSpeedingCamList + select_num)->Signal30SpeedControlCam() == 2) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 7); // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리

			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 8: {  // 신호위반 및 과속카메라 부분
			if ((SignalSpeedingCamList + select_num)->Signal40SpeedControlCam() == 2) {
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h 과속입니다." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 8); // 현재 자동차 속도 값과 인덱스 값을 매개 변수로 입력 받아 speedingPenalize 함수 처리

			}
			else
				cout << "[NOTICE] 과속카메라에 포착된 자동차의 속력 : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		default:
			break;
	}
}

void RoadTrafficControlSystem::violationStatus(int select2_num) {  // 신호 및 주정차 위반에 대한 벌점 및 범칙금
	// select2_num를 입력받아 각 구역별 카메라를 선택하고, 선택한 카메라에 대한 판단

	switch (select2_num) {
		case 5: { // 배열의 5 ~ 6번째 인덱스 값이 신호 및 주정차 위반 인덱스 이므로 
			if ((SignalSpeedingCamList + select2_num)->SignalCam() == true) {
				cout << "[CAUTION] 신호 위반 포착" << endl;
				cout << "[NOTICE] 범칙금 60,000원 | 벌점 15점" << endl;
			}
			else
				cout << "[NOTICE] 이상없음 " << endl;
			break;
		}
		case 6: {
			cout <<"[!]" << (SignalSpeedingCamList + select2_num)->getLimit() << "분 이상 주정차시 위반 대상입니다." << endl;
			if ((SignalSpeedingCamList + select2_num)->ParkingCam() == true) {
				cout << "[CAUTION] 주정차 위반 포착" << endl;
				cout << "[NOTICE] 범칙금 40,000원" << endl;
			}
			else
				cout << "[NOTICE] 이상없음 " << endl;
			break;
		}
		case 7: {
			if ((SignalSpeedingCamList + select2_num)->Signal30SpeedControlCam() == 1) {
				cout << "[CAUTION] 신호 위반 포착" << endl;
				cout << "[NOTICE] 범칙금 60,000원 | 벌점 15점" << endl;
			}
			else
				cout << "[NOTICE] 이상없음 " << endl;
			break;
		}
		case 8: {
			if ((SignalSpeedingCamList + select2_num)->Signal40SpeedControlCam() == 1) {
				cout << "[CAUTION] 신호 위반 포착" << endl;
				cout << "[NOTICE] 범칙금 60,000원 | 벌점 15점" << endl;
			}
			else
				cout << "[NOTICE] 이상없음 " << endl;
			break;
		}
		default:
			break;
	}
}

void RoadTrafficControlSystem::signalspeedingStatus(int select3_num) {  // 신호 위반 및 과속 단속에 대한 벌점 및 범칙금
		// select3_num를 입력받아 각 구역별 카메라를 선택하고, 선택한 카메라에 대한 판단

	switch (select3_num) {
		case 7: {
			cout << "[과속정보]" << endl;
				speedingStatus(7);
			cout <<endl<< "[신호위반정보]" << endl;
				violationStatus(7);
				break;
		}
		case 8: {
			cout << "[과속정보]" << endl;
			speedingStatus(8);
			cout <<endl << "[신호위반정보]" << endl;
			violationStatus(8);
			break;
		}

	}

}

void RoadTrafficControlSystem::start() {
	int select;
	while (true) {
		cout << "========================================================================" << endl;
		cout << "\t\t   << 실행할 메뉴를 선택해 주세요. >>" << endl << endl;
			cout << ">> 1 : 설치된 카메라 목록" << endl;
			cout << ">> 2 : 과속카메라 현황" << endl;
			cout << ">> 3 : 신호 및 주정차 위반 카메라 현황" << endl;
			cout << ">> 4 : 신호과속단속 카메라 현황" << endl;
			cout << ">> 5 : 종료" << endl;
			cout << "========================================================================" << endl;
			cout << "INPUT : ";
			cin >> select;
			switch (select) {
			case 1: {
				system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
				cout << "========================================================================" << endl;
				cout << "\t\t   [현재 설치된 카메라 리스트]" << endl << endl;
				info();  // 디폴트 매개변수로 인해 info(0)으로 처리하여 에러가 발생하지 않음
				break;
			}

			case 2: {
				system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
				int select2=0;
				GO2:
				speedingPenaltylist();
				cout << "========================================================================" << endl;
				cout << "\t\t   << 확인할 구역을 선택해 주세요. >>" << endl << endl;
				info(1);
				cout << "========================================================================" << endl;
				cout << "INPUT : ";
				cin >> select2;
				if (select2 == 1)  // 1번이 선택된 경우
					speedingStatus(0);  // 객체배열의 첫 번째 인덱스의 과속 단속
				else if (select2 == 2)  // 2번이 선택된 경우
					speedingStatus(1);  // 객체배열의 두 번째 인덱스의 과속 단속
				else if (select2 == 3)
					speedingStatus(2);
				else if (select2 == 4)
					speedingStatus(3);
				else if (select2 == 5)
					speedingStatus(4);
				else {
					if (!cin) {  // 숫자 이외의 값이 입력된 경우
						cin.clear();  // failbit 초기화
						cin.ignore(INT_MAX, '\n');  // 입력받은 버퍼값 초기화
						system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
						cout << "[ERROR] 숫자를 입력해주세요." << endl;
						goto GO2;  // 이외의 값 입력시 다시입력
					}
					system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
					cout << "[ERROR] 1~5 범위의 숫자를 입력해주세요" << endl;
					goto GO2;  // 이외의 값 입력시 다시입력
				}
				break;
			}
			case 3: {
				int select3=0;
				system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
				GO3:
				cout <<  "========================================================================" << endl;
				cout << "\t\t   << 확인할 구역을 선택해 주세요. >>" << endl << endl;
				info(2);
				cout << "========================================================================" << endl;
				cout << "INPUT : ";
				cin >> select3;
				if (select3 == 1)
					violationStatus(5);
				else if (select3 == 2)
					violationStatus(6);
				else {
					if (!cin) {  // 숫자 이외의 값이 입력된 경우
						cin.clear();  // failbit 초기화
						cin.ignore(INT_MAX, '\n');  // 입력받은 버퍼값 초기화
						system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
						cout << "[ERROR] 숫자를 입력해주세요." << endl;
						goto GO3;  // 이외의 값 입력시 다시입력
					}
					system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
					cout << "[ERROR] 1~2 범위의 숫자를 입력해주세요" << endl;
					goto GO3;  // 이외의 값 입력시 다시입력
				}
				break;
			}
			case 4:{
				int select4 = 0;
				system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
			GO4:
				cout << "========================================================================" << endl;
				cout << "\t\t   << 확인할 구역을 선택해 주세요. >>" << endl << endl;
				info(3);
				cout << "========================================================================" << endl;
				cout << "INPUT : ";
				cin >> select4;
				if (select4 == 1) {
					signalspeedingStatus(7);
				}
				else if (select4 == 2)
					signalspeedingStatus(8);
				else {
					if (!cin) {  // 숫자 이외의 값이 입력된 경우
						cin.clear();  // failbit 초기화
						cin.ignore(INT_MAX, '\n');  // 입력받은 버퍼값 초기화
						system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
						cout << "[ERROR] 숫자를 입력해주세요." << endl;
						goto GO4;  // 이외의 값 입력시 다시입력
					}
					system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
					cout << "[ERROR] 1~2 범위의 숫자를 입력해주세요" << endl;
					goto GO4;  // 이외의 값 입력시 다시입력
				}
				break;
			}
			case 5:
				goto EXIT;
			default: {
				if (!cin) {  // 숫자 이외의 값이 입력된 경우
					cin.clear();  // failbit 초기화
					cin.ignore(INT_MAX, '\n');  // 입력받은 버퍼값 초기화
					system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
					cout << "[ERROR] 숫자를 입력해주세요." << endl;
					continue;
				}
				system("cls"); // 화면에 출력된 내용들을 모두 지워주는 함수
				cout << "[ERROR] 1~5 범위의 숫자를 입력해주세요" << endl;
				continue;
			}
		}
	}
	EXIT:
		return;
}

RoadTrafficControlSystem::~RoadTrafficControlSystem(){
	if(SignalSpeedingCamList)
		delete[] SignalSpeedingCamList;
}
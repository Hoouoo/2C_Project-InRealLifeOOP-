#include "RoadTrafficControlSystem.h"


RoadTrafficControlSystem::RoadTrafficControlSystem() {
	cout << "====================== ���α��� ���� �ý����Դϴ� ====================== " << endl;

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

void RoadTrafficControlSystem::info(int num) {  // ��ġ�� ī�޶��� ���� ���
	if (num == 1) {  // num ���� 1�̸� ����ī�޶� ���� ���
		for (int idx = 0; idx < 5; idx++) {
			cout << ">> [" << idx + 1 << "] " << (SignalSpeedingCamList + idx)->getName() << " ( ���Ѽӵ� : " << (SignalSpeedingCamList + idx)->getLimit() << " )" << endl;
		}
	}
	else if (num == 2) {  // num���� 2�� ��ȣ,������ ���� ī�޶� ���� ���
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
			cout << ">> [" << idx + 1 << "] " << (SignalSpeedingCamList + idx)->getName() << " ( ���Ѽӵ� : " << (SignalSpeedingCamList + idx)->getLimit() << " )" << endl;
			count++;
		}
		for (int idx4 = 5; idx4 < 9; idx4++) {
			cout << ">> [" << idx4 + 1 << "] " << (SignalSpeedingCamList + idx4)->getName() << endl;
			count++;
		}
		cout << endl << "[NOTICE] ���� ��ġ�� ī�޶��� ������ �� "<<count << "�� �Դϴ�." << endl;
	}
}

void RoadTrafficControlSystem::speedingPenaltylist() {  // �г�Ƽ ����ǥ ���
	cout << "========================================================================" << endl;
	cout << "\t\t   [�ʰ� �ӵ��� ���� ��Ģ�� �� ���� ����ǥ]" << endl << endl;
	cout << "\t'20km/h'���� �ʰ� �� \t   ��Ģ�� 40,000��  |  ���� 0��" << endl;
	cout << "'20km/h' �ʰ� '40km/h'���� �ʰ� �� ��Ģ�� 70,000��  |  ���� 15��" << endl;
	cout << "'40km/h' �ʰ� '60km/h'���� �ʰ� �� ��Ģ�� 100,000�� |  ���� 30��" << endl;
	cout << "\t'60km/h' �ʰ� �� \t   ��Ģ�� 130,000�� |  ���� 60��" << endl;
}

void RoadTrafficControlSystem::speedingPenalize(int nowspeed, int idxnum) {  // �г�Ƽ ����ǥ�� ���� ��Ģ�� ó�� �Լ�
	// nowspeed = (SignalSpeedingCamList + select_num)->Carspeed, idxnum = SignalSpeedingCamList ��ü�� �迭 �ε���
	if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 20 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) >= 0)
		cout << "[NOTICE] ��Ģ�� 40,000��" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 20 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 40)
		cout << "[NOTICE] ��Ģ�� 70,000��  |  ���� 15��" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 40 && (nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) <= 60)
		cout << "[NOTICE] ��Ģ�� 100,000�� |  ���� 30��" << endl;
	else if ((nowspeed - (SignalSpeedingCamList + idxnum)->getLimit()) > 60)
		cout << "[NOTICE] ��Ģ�� 130,000��  |  ���� 60��" << endl;
}


void RoadTrafficControlSystem::speedingStatus(int select_num) {  //���ӿ� ���� ���� �� ��Ģ�� 
	// select_num�� �Է¹޾� �� ������ ���� ī�޶� �����ϰ�, ������ ����ī�޶� ���� �Ǵ�
	switch (select_num) { 
		case 0: {
			if ((SignalSpeedingCamList + select_num)->SchoolzoneCam() == true) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 0);  // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��
			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}

		case 1: {
			if ((SignalSpeedingCamList + select_num)->DowntownroadCam() == true) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 1);  // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��

			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 2: {
			if ((SignalSpeedingCamList + select_num)->NationalroadCam() == true) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 2); // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��
			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 3: {
			if ((SignalSpeedingCamList + select_num)->SpeedwayCam() == true) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 3); // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��
			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 4: {
			if ((SignalSpeedingCamList + select_num)->HighwayCam() == true) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 4); // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��

			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 7: {  // ��ȣ���� �� ����ī�޶� �κ�
			if ((SignalSpeedingCamList + select_num)->Signal30SpeedControlCam() == 2) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 7); // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��

			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		case 8: {  // ��ȣ���� �� ����ī�޶� �κ�
			if ((SignalSpeedingCamList + select_num)->Signal40SpeedControlCam() == 2) {
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
				cout << "[CAUTION]" << (SignalSpeedingCamList + select_num)->Carspeed - (SignalSpeedingCamList + select_num)->getLimit() << "km/h �����Դϴ�." << endl;
				speedingPenalize((SignalSpeedingCamList + select_num)->Carspeed, 8); // ���� �ڵ��� �ӵ� ���� �ε��� ���� �Ű� ������ �Է� �޾� speedingPenalize �Լ� ó��

			}
			else
				cout << "[NOTICE] ����ī�޶� ������ �ڵ����� �ӷ� : " << (SignalSpeedingCamList + select_num)->Carspeed << "km/h" << endl;
			break;
		}
		default:
			break;
	}
}

void RoadTrafficControlSystem::violationStatus(int select2_num) {  // ��ȣ �� ������ ���ݿ� ���� ���� �� ��Ģ��
	// select2_num�� �Է¹޾� �� ������ ī�޶� �����ϰ�, ������ ī�޶� ���� �Ǵ�

	switch (select2_num) {
		case 5: { // �迭�� 5 ~ 6��° �ε��� ���� ��ȣ �� ������ ���� �ε��� �̹Ƿ� 
			if ((SignalSpeedingCamList + select2_num)->SignalCam() == true) {
				cout << "[CAUTION] ��ȣ ���� ����" << endl;
				cout << "[NOTICE] ��Ģ�� 60,000�� | ���� 15��" << endl;
			}
			else
				cout << "[NOTICE] �̻���� " << endl;
			break;
		}
		case 6: {
			cout <<"[!]" << (SignalSpeedingCamList + select2_num)->getLimit() << "�� �̻� �������� ���� ����Դϴ�." << endl;
			if ((SignalSpeedingCamList + select2_num)->ParkingCam() == true) {
				cout << "[CAUTION] ������ ���� ����" << endl;
				cout << "[NOTICE] ��Ģ�� 40,000��" << endl;
			}
			else
				cout << "[NOTICE] �̻���� " << endl;
			break;
		}
		case 7: {
			if ((SignalSpeedingCamList + select2_num)->Signal30SpeedControlCam() == 1) {
				cout << "[CAUTION] ��ȣ ���� ����" << endl;
				cout << "[NOTICE] ��Ģ�� 60,000�� | ���� 15��" << endl;
			}
			else
				cout << "[NOTICE] �̻���� " << endl;
			break;
		}
		case 8: {
			if ((SignalSpeedingCamList + select2_num)->Signal40SpeedControlCam() == 1) {
				cout << "[CAUTION] ��ȣ ���� ����" << endl;
				cout << "[NOTICE] ��Ģ�� 60,000�� | ���� 15��" << endl;
			}
			else
				cout << "[NOTICE] �̻���� " << endl;
			break;
		}
		default:
			break;
	}
}

void RoadTrafficControlSystem::signalspeedingStatus(int select3_num) {  // ��ȣ ���� �� ���� �ܼӿ� ���� ���� �� ��Ģ��
		// select3_num�� �Է¹޾� �� ������ ī�޶� �����ϰ�, ������ ī�޶� ���� �Ǵ�

	switch (select3_num) {
		case 7: {
			cout << "[��������]" << endl;
				speedingStatus(7);
			cout <<endl<< "[��ȣ��������]" << endl;
				violationStatus(7);
				break;
		}
		case 8: {
			cout << "[��������]" << endl;
			speedingStatus(8);
			cout <<endl << "[��ȣ��������]" << endl;
			violationStatus(8);
			break;
		}

	}

}

void RoadTrafficControlSystem::start() {
	int select;
	while (true) {
		cout << "========================================================================" << endl;
		cout << "\t\t   << ������ �޴��� ������ �ּ���. >>" << endl << endl;
			cout << ">> 1 : ��ġ�� ī�޶� ���" << endl;
			cout << ">> 2 : ����ī�޶� ��Ȳ" << endl;
			cout << ">> 3 : ��ȣ �� ������ ���� ī�޶� ��Ȳ" << endl;
			cout << ">> 4 : ��ȣ���Ӵܼ� ī�޶� ��Ȳ" << endl;
			cout << ">> 5 : ����" << endl;
			cout << "========================================================================" << endl;
			cout << "INPUT : ";
			cin >> select;
			switch (select) {
			case 1: {
				system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
				cout << "========================================================================" << endl;
				cout << "\t\t   [���� ��ġ�� ī�޶� ����Ʈ]" << endl << endl;
				info();  // ����Ʈ �Ű������� ���� info(0)���� ó���Ͽ� ������ �߻����� ����
				break;
			}

			case 2: {
				system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
				int select2=0;
				GO2:
				speedingPenaltylist();
				cout << "========================================================================" << endl;
				cout << "\t\t   << Ȯ���� ������ ������ �ּ���. >>" << endl << endl;
				info(1);
				cout << "========================================================================" << endl;
				cout << "INPUT : ";
				cin >> select2;
				if (select2 == 1)  // 1���� ���õ� ���
					speedingStatus(0);  // ��ü�迭�� ù ��° �ε����� ���� �ܼ�
				else if (select2 == 2)  // 2���� ���õ� ���
					speedingStatus(1);  // ��ü�迭�� �� ��° �ε����� ���� �ܼ�
				else if (select2 == 3)
					speedingStatus(2);
				else if (select2 == 4)
					speedingStatus(3);
				else if (select2 == 5)
					speedingStatus(4);
				else {
					if (!cin) {  // ���� �̿��� ���� �Էµ� ���
						cin.clear();  // failbit �ʱ�ȭ
						cin.ignore(INT_MAX, '\n');  // �Է¹��� ���۰� �ʱ�ȭ
						system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
						cout << "[ERROR] ���ڸ� �Է����ּ���." << endl;
						goto GO2;  // �̿��� �� �Է½� �ٽ��Է�
					}
					system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
					cout << "[ERROR] 1~5 ������ ���ڸ� �Է����ּ���" << endl;
					goto GO2;  // �̿��� �� �Է½� �ٽ��Է�
				}
				break;
			}
			case 3: {
				int select3=0;
				system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
				GO3:
				cout <<  "========================================================================" << endl;
				cout << "\t\t   << Ȯ���� ������ ������ �ּ���. >>" << endl << endl;
				info(2);
				cout << "========================================================================" << endl;
				cout << "INPUT : ";
				cin >> select3;
				if (select3 == 1)
					violationStatus(5);
				else if (select3 == 2)
					violationStatus(6);
				else {
					if (!cin) {  // ���� �̿��� ���� �Էµ� ���
						cin.clear();  // failbit �ʱ�ȭ
						cin.ignore(INT_MAX, '\n');  // �Է¹��� ���۰� �ʱ�ȭ
						system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
						cout << "[ERROR] ���ڸ� �Է����ּ���." << endl;
						goto GO3;  // �̿��� �� �Է½� �ٽ��Է�
					}
					system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
					cout << "[ERROR] 1~2 ������ ���ڸ� �Է����ּ���" << endl;
					goto GO3;  // �̿��� �� �Է½� �ٽ��Է�
				}
				break;
			}
			case 4:{
				int select4 = 0;
				system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
			GO4:
				cout << "========================================================================" << endl;
				cout << "\t\t   << Ȯ���� ������ ������ �ּ���. >>" << endl << endl;
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
					if (!cin) {  // ���� �̿��� ���� �Էµ� ���
						cin.clear();  // failbit �ʱ�ȭ
						cin.ignore(INT_MAX, '\n');  // �Է¹��� ���۰� �ʱ�ȭ
						system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
						cout << "[ERROR] ���ڸ� �Է����ּ���." << endl;
						goto GO4;  // �̿��� �� �Է½� �ٽ��Է�
					}
					system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
					cout << "[ERROR] 1~2 ������ ���ڸ� �Է����ּ���" << endl;
					goto GO4;  // �̿��� �� �Է½� �ٽ��Է�
				}
				break;
			}
			case 5:
				goto EXIT;
			default: {
				if (!cin) {  // ���� �̿��� ���� �Էµ� ���
					cin.clear();  // failbit �ʱ�ȭ
					cin.ignore(INT_MAX, '\n');  // �Է¹��� ���۰� �ʱ�ȭ
					system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
					cout << "[ERROR] ���ڸ� �Է����ּ���." << endl;
					continue;
				}
				system("cls"); // ȭ�鿡 ��µ� ������� ��� �����ִ� �Լ�
				cout << "[ERROR] 1~5 ������ ���ڸ� �Է����ּ���" << endl;
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
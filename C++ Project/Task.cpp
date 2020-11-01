#include "Task.h"
#include "Depression.h"
#include "Insomnia.h"
#include "Patient.h"
#include "Mentalunease.h"
#include "Schizophrenia.h"
#include <iostream>
#include <map>
#include <windows.h>
#include <Conio.h>

#define WIDTH	80
#define HEIGHT	25

#define DAY_COUNT 100000
multimap<string, Patient*> patientMap;
typedef multimap<string, Patient*>::iterator patientIt;


void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void task() {



	gotoxy((WIDTH - 65) / 2, 1);
	cout << "===============================================================" << endl;
	gotoxy((WIDTH - 22) / 2, 2);
	cout << "��Ʈ ���ź��� ���α׷�" << endl;
	gotoxy((WIDTH - 65) / 2, 3);
	cout << "===============================================================" << endl;

	int sel;


	gotoxy((WIDTH - 36) / 2, 5); cout << "������������������������������������������������������������������������" << endl;
	gotoxy(20, 6); cout << "  ��                                  ��" << endl;
	gotoxy(20, 7); cout << "  ��         1. ȯ�� ����             ��" << endl;
	gotoxy(20, 8); cout << "  ��                                  ��" << endl;
	gotoxy(20, 9); cout << "  ��         2. ȯ�� ��� ����        ��" << endl;
	gotoxy(20, 10); cout << "  ��                                  ��" << endl;
	gotoxy(20, 11); cout << "  ��         3. ȯ�� �˻�             ��" << endl;
	gotoxy(20, 12); cout << "  ��                                  ��" << endl;
	gotoxy(20, 13); cout << "  ��         4. ȯ�� ���� ����        ��" << endl;
	gotoxy(20, 14); cout << "  ��                                  ��" << endl;
	gotoxy(20, 15); cout << "  ��         5. ȯ�� ����             ��" << endl;
	gotoxy(20, 16); cout << "  ��                                  ��" << endl;
	gotoxy(20, 17); cout << "  ��         6. ȯ�� �Խ�             ��" << endl;
	gotoxy(20, 18); cout << "  ��                                  ��" << endl;
	gotoxy(20, 19); cout << "  ��         7. ���� ��Ȳ ����        ��" << endl;
	gotoxy(20, 20); cout << "  ��                                  ��" << endl;
	gotoxy(20, 21); cout << "  ��         8. ���α׷� ����         ��" << endl;
	gotoxy(20, 22); cout << "  ��                                  ��" << endl;
	gotoxy(20, 23); cout << "  ������������������������������������������������������������������������" << endl;

	gotoxy(21, 24); cout << "  <<���Ͻô� ������ �Է��ϼ���>> : ";
	
	gotoxy(56, 24); cin >> sel;
	cout << endl;
	system("cls");

	switch (sel) {
	case 1:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ����>>>>>>> " << endl << endl;
		addPatient();
		break;
	case 2:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ��� ���� >>>>>>>> " << endl << endl;
		viewPatient();
		break;
	case 3:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ���� �˻�>>>>>>>> " << endl << endl;
		searchPatient();
		break;

	case 4:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ���� ����>>>>>>>> " << endl << endl;
		editPatient();
		break;
	case 5:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ��� >>>>>>>> " << endl << endl;
		deletePatient();
		break;
	case 6:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� �Կ� >>>>>>> " << endl << endl;
		assignRoom();
		break;
	case 7:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<ȯ�� ���� ��Ȳ >>>>>>> " << endl << endl;
		checkRoom();
		break;
	case 8:
		exit(0);
	}
}

void addPatient() {
	int sel;
	string name;
	int age;
	string ID_NUM;
	string symptom;

	cout << "================================================================================" << endl;
	cout << endl;
	cout << "�̸� (�޴��� ���� = 0 �Է�) >> ";
	cin >> name;
	if (name == "0") { system("cls"); return; }
	cout << "���� >> ";
	cin >> age;
	cout << "�ֹε�Ϲ�ȣ >> ";
	cin >> ID_NUM;
	cout << "���� >> ";
	getchar(); getline(cin, symptom);
	cout << "���� ���� : 1. ����� , 2. �Ҹ���, 3. ������, 4. �����Ҿ�>> ";
	cin >> sel;
	cout << "���� �����Ǿ����ϴ�." << endl << endl;
	cout << endl;

	if (sel == 1) {
		Depression* dep = new Depression(name, age, ID_NUM, symptom);
		dep->checkSymptom();
		dep->seeDr();
		dep->Drug();
		patientMap.insert(make_pair("�����", dep));
	}
	else if (sel == 2) {
		Insomnia* insom = new Insomnia(name, age, ID_NUM, symptom);
		insom->checkSymptom();
		insom->seeDr();
		insom->Drug();
		patientMap.insert(make_pair("�Ҹ���", insom));
	}
	else if (sel == 3) {
		Schizophrenia* schiz = new Schizophrenia(name, age, ID_NUM, symptom);
		schiz->checkSymptom();
		schiz->seeDr();
		schiz->Drug();
		patientMap.insert(make_pair("������", schiz));
	}
	else if (sel == 4) {
		Mentalunease* mental = new Mentalunease(name, age, ID_NUM, symptom);
		mental->checkSymptom();
		mental->seeDr();
		mental->Drug();
		patientMap.insert(make_pair("�����Ҿ�", mental));
	}

	clearScreen();
}

void viewPatient() {
	multimap<string, Patient*> ::iterator Pit;
	int sel;
	cout << "1 .��ü ���� ȯ�� ���� / 2 .���� ���� ȯ�� ���� �Է� >>";
	cin >> sel;
	if (sel == 1) {
		for (Pit = patientMap.begin(); Pit != patientMap.end(); ++Pit) {

			Patient* patient = Pit->second;
			cout << Pit->first << "\n";

			cout << "�̸� : " << patient->Name << endl;
			cout << "���� : " << patient->Age << endl;
			cout << "���� : " << patient->sex << endl;
			cout << "��� : " << patient->money << endl;
			cout << "���� : " << patient->symptom << endl;
			cout << "ȣ�� : " << patient->roomNum << endl;
			cout << "---------------------------------" << endl;

		}
		cout << endl;
		clearScreen();
	}if (sel == 2) {
	FIRST:
		string ill;
		cout << "�˻��� ������ �Է��ϼ���(�޴��� ���� = 0 �Է�) >>";

		cin >> ill;
		cout << endl << endl;
		if (ill == "0") { system("cls"); return; }
		pair<patientIt, patientIt> result = patientMap.equal_range(ill);

		if (result.first == result.second) {
			cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
			goto FIRST;
		}
		else {
			
			for (Pit = patientMap.begin(); Pit != patientMap.end(); ++Pit) {
				if (Pit->first == ill) {
					Patient* patient = Pit->second;
					cout << Pit->first << "\n";

					cout << "�̸� : " << patient->Name << endl;
					cout << "���� : " << patient->Age << endl;
					cout << "���� : " << patient->sex << endl;
					cout << "��� : " << patient->money << endl;
					cout << "���� : " << patient->symptom << endl;
					cout << "ȣ�� : " << patient->roomNum << endl;
					cout << "---------------------------------" << endl;
				}
			}
			cout << endl;
			clearScreen();
		}
		
		
	}
}

void deletePatient() {
FIRST:
	string ill;
	cout << "������ ȯ���� ������ �Է��ϼ���(�޴��� ���� = 0 �Է�) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "������ ȯ���� �̸��� �Է��ϼ��� >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {
				cout << name << "���� ������ �����߽��ϴ�." << endl << endl;
				patientMap.erase(it);
				break;
			}
		}
	}
	clearScreen();
}

void searchPatient() {
FIRST:
	string ill;
	cout << "ã���� ȯ���� ������ �Է��ϼ��� (�޴��� ���� = 0 �Է�) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }                       //multimap<string, Patient*>::iterator
	pair<patientIt, patientIt> result = patientMap.equal_range(ill); //�ݺ��� �� �� ���۰� ���� ����Ŵ
	//key ���� �ش��ϴ� ������ ������ pair ��ü�� ��ȯ
	//pair ��ü�� first�� key ���� �ش��ϴ� ������ ù��° �ݺ���
	//pair ��ü�� second�� key ���� �ش��ϴ� ������ ������ ������ "����" �ݺ��� ��ȯ 

	if (result.first == result.second) { // first~second(������ �������) ���� ã�� �� (�������� ���ٴ°�)	
		cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "ã���� ȯ���� �̸��� �Է��ϼ��� >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {
			//multimap<string, Patient*>::iterator it = result.first;

			if (it->second->Name == name) {//it �� �߷����� Patient ��ü�� ������� Name == name �� �Ǹ�
				Patient* patient = it->second;
				cout << it->first << "\n";
				cout << "�̸� : " << patient->Name << endl;
				cout << "���� : " << patient->Age << endl;
				cout << "���� : " << patient->sex << endl;
				cout << "��� : " << patient->money << endl;
				cout << "���� : " << patient->symptom << endl << "---------------------------------" << endl;
				break;
			}
		}
	}
	clearScreen();
}
void editPatient() {
	int sel;
	string name;
	int age;
	string ID_NUM;
	string symptom;
	int money;
FIRST:
	string ill;
	cout << "ã���� ȯ���� ������ �Է��ϼ��� (�޴��� ���� = 0 �Է�) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "ã���� ȯ���� �̸��� �Է��ϼ��� >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {
				Patient* patient = it->second;
				cout << it->first << "\n";

				cout << "�̸� : " << patient->Name << endl;
				cout << "���� : " << patient->Age << endl;
				cout << "���� : " << patient->sex << endl;
				cout << "��� : " << patient->money << endl;
				cout << "���� : " << patient->symptom << endl << "---------------------------------" << endl;

				cout << " << ������ ������ �Է��ϼ��� >>" << endl;;
				cout << "�̸� >> ";
				cin >> name;
				cout << "���� >>";
				cin >> age;
				cout << "��� >>";
				cin >> money;
				patient->Name = name;
				patient->Age = age;
				patient->money = money;
				cout << endl << endl;
				cout << "���� �Ϸ� �Ǿ����ϴ�." << endl << endl;
				break;
			}
		}
	}
	clearScreen();
}

void checkRoom() {
	int room;
	string name;
	int day;

FIRST:
	string ill;
	cout << "ã���� ȯ���� ������ �Է��ϼ��� (�޴��� ���� = 0 �Է�) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
		goto FIRST;
	}	
	else {
		gotoxy(5, 5); cout << "����������������������������������������������������������" << endl;
		gotoxy(5, 6); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 7); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 8); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 9); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(5, 10); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(5, 11); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 12); cout << "����������������������������������������������������������" << endl;


		gotoxy(38, 5); cout << "����������������������������������������������������������" << endl;
		gotoxy(38, 6); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 7); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 8); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 9); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(38, 10); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(38, 11); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 12); cout << "����������������������������������������������������������" << endl;

		gotoxy(5, 21); cout << "����������������������������������������������������������" << endl;
		gotoxy(5, 22); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 23); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 24); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 25); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(5, 26); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(5, 27); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(5, 28); cout << "����������������������������������������������������������" << endl;

		gotoxy(38, 21); cout << "����������������������������������������������������������" << endl;
		gotoxy(38, 22); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 23); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 24); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 25); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(38, 26); cout << "�� ��     �� ��                 ��" << endl;
		gotoxy(38, 27); cout << "�� �������������� ��                 ��" << endl;
		gotoxy(38, 28); cout << "����������������������������������������������������������" << endl;
		
		for (patientIt it = result.first; it != result.second; it++) {
			Patient* patient = it->second;

				if (it->second->roomNum == 101 || it->second->roomNum == 201 ||
					it->second->roomNum == 301 || it->second->roomNum == 401) {
					gotoxy(17, 7); cout << "�̸� : " << patient->Name << endl;
					gotoxy(17, 8); cout << "���� : " << patient->Age <<"��" << endl;
					gotoxy(17, 9); cout << "���� : " << patient->sex << endl;
					gotoxy(17, 10); cout << "ȣ�� : " << patient->roomNum <<"ȣ"<< endl;
					gotoxy(17, 11); cout << "���� : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 102 || it->second->roomNum == 202 ||
					it->second->roomNum == 302 || it->second->roomNum == 402) {
					gotoxy(49, 7); cout << "�̸� : " << patient->Name << endl;
					gotoxy(49, 8); cout << "���� : " << patient->Age <<"��"<< endl;
					gotoxy(49, 9); cout << "���� : " << patient->sex << endl;
					gotoxy(49, 10); cout << "ȣ�� : " << patient->roomNum <<"ȣ" << endl;
					gotoxy(49, 11); cout << "���� : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 103 || it->second->roomNum == 203 ||
					it->second->roomNum == 303 || it->second->roomNum == 403) {
					gotoxy(17, 23); cout << "�̸� : " << patient->Name << endl;
					gotoxy(17, 24); cout << "���� : " << patient->Age <<"��"<< endl;
					gotoxy(17, 25); cout << "���� : " << patient->sex << endl;
					gotoxy(17, 26); cout << "ȣ�� : " << patient->roomNum <<"ȣ"<< endl;
					gotoxy(17, 27); cout << "���� : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 104 || it->second->roomNum == 204 ||
					it->second->roomNum == 304 || it->second->roomNum == 404) {
					gotoxy(49, 23); cout << "�̸� : " << patient->Name << endl;
					gotoxy(49, 24); cout << "���� : " << patient->Age <<"��"<< endl;
					gotoxy(49, 25); cout << "���� : " << patient->sex << endl;
					gotoxy(49, 26); cout << "ȣ�� : " << patient->roomNum <<"ȣ" << endl;
					gotoxy(49, 27); cout << "���� : " << patient->symptom << endl;
				
				}
			
		}

		clearScreen();
	}
}

void assignRoom() {
	int room;
	string name;
	int day;

FIRST:
	string ill;
	cout << "ã���� ȯ���� ������ �Է��ϼ���, (�޴��� ���� = 0 �Է�) >>";

	cin >> ill;
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);
	if (ill == "0") { system("cls"); return; }
	if (result.first == result.second) {
		cout << "�׷� ������ �����ϴ�, �ٽ� �Է��� �ּ���." << endl;
		goto FIRST;
	}
	else {
		cout << "�Կ��Ͻ� ȯ���� �̸��� �Է��ϼ��� >>";
		cin >> name;
		cout << endl;

		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {

				Patient* patient = it->second;
			REEDIT:
				cout << it->second->Name << "�� �Կ��� ȣ���� �Է��� �ּ��� >>" << "\n";
				cin >> room;
				for (patientIt it = result.first; it != result.second; it++) {

					if (it->second->roomNum != room) {
						cout << name << "�� �󸶳� �Կ��Ͻʴϱ�? >> " << endl;
						cin >> day;
						patient->roomNum = room;
						patient->money = day * DAY_COUNT;
						cout << "��� = " << patient->money << "���� ��Ź �帳�ϴ�." << endl << endl;

						cout << patient->roomNum << "ȣ\n" << patient->Name <<" ��"
							<< endl << patient->Age <<  "��" << endl << "���� : "<< patient->symptom << endl;
						cout << "�Խ� �Ϸ� �Ǿ����ϴ�." << endl << endl;
						break;
					}
					else {
						cout << room << "ȣ�� �ٸ� ȯ�ڰ� ������Դϴ� �ٽ� �Է� ��Ź�帳�ϴ�>> " << endl;
						goto REEDIT;
					}
				}
			}
		}
		clearScreen();
	}

}
void clearScreen() {
	getchar();
	getchar();
	system("cls");
}



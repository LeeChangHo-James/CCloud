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
	cout << "綠お 薑褐煽錳 Щ煎斜極" << endl;
	gotoxy((WIDTH - 65) / 2, 3);
	cout << "===============================================================" << endl;

	int sel;


	gotoxy((WIDTH - 36) / 2, 5); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	gotoxy(20, 6); cout << "  弛                                  弛" << endl;
	gotoxy(20, 7); cout << "  弛         1. �素� 蕾熱             弛" << endl;
	gotoxy(20, 8); cout << "  弛                                  弛" << endl;
	gotoxy(20, 9); cout << "  弛         2. �素� 賅舒 爾晦        弛" << endl;
	gotoxy(20, 10); cout << "  弛                                  弛" << endl;
	gotoxy(20, 11); cout << "  弛         3. �素� 匐儀             弛" << endl;
	gotoxy(20, 12); cout << "  弛                                  弛" << endl;
	gotoxy(20, 13); cout << "  弛         4. �素� 薑爾 熱薑        弛" << endl;
	gotoxy(20, 14); cout << "  弛                                  弛" << endl;
	gotoxy(20, 15); cout << "  弛         5. �素� 餉薯             弛" << endl;
	gotoxy(20, 16); cout << "  弛                                  弛" << endl;
	gotoxy(20, 17); cout << "  弛         6. �素� 殮褒             弛" << endl;
	gotoxy(20, 18); cout << "  弛                                  弛" << endl;
	gotoxy(20, 19); cout << "  弛         7. 煽翕 鼻�� 爾晦        弛" << endl;
	gotoxy(20, 20); cout << "  弛                                  弛" << endl;
	gotoxy(20, 21); cout << "  弛         8. Щ煎斜極 謙猿         弛" << endl;
	gotoxy(20, 22); cout << "  弛                                  弛" << endl;
	gotoxy(20, 23); cout << "  戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

	gotoxy(21, 24); cout << "  <<錳ж衛朝 機鼠蒂 殮溘ж撮蹂>> : ";
	
	gotoxy(56, 24); cin >> sel;
	cout << endl;
	system("cls");

	switch (sel) {
	case 1:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 蕾熱>>>>>>> " << endl << endl;
		addPatient();
		break;
	case 2:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 賅舒 爾晦 >>>>>>>> " << endl << endl;
		viewPatient();
		break;
	case 3:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 薑爾 匐儀>>>>>>>> " << endl << endl;
		searchPatient();
		break;

	case 4:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 薑爾 熱薑>>>>>>>> " << endl << endl;
		editPatient();
		break;
	case 5:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 黴錳 >>>>>>>> " << endl << endl;
		deletePatient();
		break;
	case 6:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 殮錳 >>>>>>> " << endl << endl;
		assignRoom();
		break;
	case 7:
		gotoxy((WIDTH - 30) / 2, 1);
		cout << " <<<<<<<�素� 煽翕 鼻�� >>>>>>> " << endl << endl;
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
	cout << "檜葷 (詭景煎 陛晦 = 0 殮溘) >> ";
	cin >> name;
	if (name == "0") { system("cls"); return; }
	cout << "釭檜 >> ";
	cin >> age;
	cout << "輿團蛔煙廓�� >> ";
	cin >> ID_NUM;
	cout << "隸鼻 >> ";
	getchar(); getline(cin, symptom);
	cout << "煽貲 霞欽 : 1. 辦選隸 , 2. 碳賊隸, 3. 褻⑷煽, 4. 薑憮碳寰>> ";
	cin >> sel;
	cout << "薑鼻 蕾熱腎歷蝗棲棻." << endl << endl;
	cout << endl;

	if (sel == 1) {
		Depression* dep = new Depression(name, age, ID_NUM, symptom);
		dep->checkSymptom();
		dep->seeDr();
		dep->Drug();
		patientMap.insert(make_pair("辦選隸", dep));
	}
	else if (sel == 2) {
		Insomnia* insom = new Insomnia(name, age, ID_NUM, symptom);
		insom->checkSymptom();
		insom->seeDr();
		insom->Drug();
		patientMap.insert(make_pair("碳賊隸", insom));
	}
	else if (sel == 3) {
		Schizophrenia* schiz = new Schizophrenia(name, age, ID_NUM, symptom);
		schiz->checkSymptom();
		schiz->seeDr();
		schiz->Drug();
		patientMap.insert(make_pair("褻⑷煽", schiz));
	}
	else if (sel == 4) {
		Mentalunease* mental = new Mentalunease(name, age, ID_NUM, symptom);
		mental->checkSymptom();
		mental->seeDr();
		mental->Drug();
		patientMap.insert(make_pair("薑憮碳寰", mental));
	}

	clearScreen();
}

void viewPatient() {
	multimap<string, Patient*> ::iterator Pit;
	int sel;
	cout << "1 .瞪羹 煽翕 �素� 爾晦 / 2 .煽翕 滌煎 �素� 爾晦 殮溘 >>";
	cin >> sel;
	if (sel == 1) {
		for (Pit = patientMap.begin(); Pit != patientMap.end(); ++Pit) {

			Patient* patient = Pit->second;
			cout << Pit->first << "\n";

			cout << "檜葷 : " << patient->Name << endl;
			cout << "釭檜 : " << patient->Age << endl;
			cout << "撩滌 : " << patient->sex << endl;
			cout << "綠辨 : " << patient->money << endl;
			cout << "隸鼻 : " << patient->symptom << endl;
			cout << "�ˊ� : " << patient->roomNum << endl;
			cout << "---------------------------------" << endl;

		}
		cout << endl;
		clearScreen();
	}if (sel == 2) {
	FIRST:
		string ill;
		cout << "匐儀й 煽翕擊 殮溘ж撮蹂(詭景煎 陛晦 = 0 殮溘) >>";

		cin >> ill;
		cout << endl << endl;
		if (ill == "0") { system("cls"); return; }
		pair<patientIt, patientIt> result = patientMap.equal_range(ill);

		if (result.first == result.second) {
			cout << "斜楛 煽翕擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
			goto FIRST;
		}
		else {
			
			for (Pit = patientMap.begin(); Pit != patientMap.end(); ++Pit) {
				if (Pit->first == ill) {
					Patient* patient = Pit->second;
					cout << Pit->first << "\n";

					cout << "檜葷 : " << patient->Name << endl;
					cout << "釭檜 : " << patient->Age << endl;
					cout << "撩滌 : " << patient->sex << endl;
					cout << "綠辨 : " << patient->money << endl;
					cout << "隸鼻 : " << patient->symptom << endl;
					cout << "�ˊ� : " << patient->roomNum << endl;
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
	cout << "餉薯й �素睎� 煽貲擊 殮溘ж撮蹂(詭景煎 陛晦 = 0 殮溘) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "斜楛 煽貲擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "餉薯й �素睎� 檜葷擊 殮溘ж撮蹂 >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {
				cout << name << "椒曖 薑爾蒂 餉薯ц蝗棲棻." << endl << endl;
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
	cout << "瓊戲褒 �素睎� 煽貲擊 殮溘ж撮蹂 (詭景煎 陛晦 = 0 殮溘) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }                       //multimap<string, Patient*>::iterator
	pair<patientIt, patientIt> result = patientMap.equal_range(ill); //奩犒濠 и 誰 衛濛婁 部擊 陛葬霽
	//key 高縑 п渡ж朝 錳模曖 彰嬪蒂 pair 偌羹煎 奩��
	//pair 偌羹曖 first朝 key 高縑 п渡ж朝 錳模曖 羅廓簞 奩犒濠
	//pair 偌羹曖 second朝 key 高縑 п渡ж朝 錳模曖 葆雖虞 錳模曖 "棻擠" 奩犒濠 奩�� 

	if (result.first == result.second) { // first~second(葆雖虞 棻擠蹂模) 梱雖 瓊朝 醞 (偽嬴雖賊 橈棻朝匙)	
		cout << "斜楛 煽貲擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "瓊戲褒 �素睎� 檜葷擊 殮溘ж撮蹂 >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {
			//multimap<string, Patient*>::iterator it = result.first;

			if (it->second->Name == name) {//it 曖 嫦盟高檣 Patient 偌羹曖 詹幗滲熱 Name == name 檜 腎賊
				Patient* patient = it->second;
				cout << it->first << "\n";
				cout << "檜葷 : " << patient->Name << endl;
				cout << "釭檜 : " << patient->Age << endl;
				cout << "撩滌 : " << patient->sex << endl;
				cout << "綠辨 : " << patient->money << endl;
				cout << "隸鼻 : " << patient->symptom << endl << "---------------------------------" << endl;
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
	cout << "瓊戲褒 �素睎� 煽貲擊 殮溘ж撮蹂 (詭景煎 陛晦 = 0 殮溘) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "斜楛 煽貲擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
		goto FIRST;
	}
	else {
		string name;
		cout << "瓊戲褒 �素睎� 檜葷擊 殮溘ж撮蹂 >>";
		cin >> name;
		cout << endl;
		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {
				Patient* patient = it->second;
				cout << it->first << "\n";

				cout << "檜葷 : " << patient->Name << endl;
				cout << "釭檜 : " << patient->Age << endl;
				cout << "撩滌 : " << patient->sex << endl;
				cout << "綠辨 : " << patient->money << endl;
				cout << "隸鼻 : " << patient->symptom << endl << "---------------------------------" << endl;

				cout << " << 熱薑й 薑爾蒂 殮溘ж撮蹂 >>" << endl;;
				cout << "檜葷 >> ";
				cin >> name;
				cout << "釭檜 >>";
				cin >> age;
				cout << "綠辨 >>";
				cin >> money;
				patient->Name = name;
				patient->Age = age;
				patient->money = money;
				cout << endl << endl;
				cout << "熱薑 諫猿 腎歷蝗棲棻." << endl << endl;
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
	cout << "瓊戲褒 �素睎� 煽翕擊 殮溘ж撮蹂 (詭景煎 陛晦 = 0 殮溘) >>";

	cin >> ill;
	if (ill == "0") { system("cls"); return; }
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);

	if (result.first == result.second) {
		cout << "斜楛 煽翕擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
		goto FIRST;
	}	
	else {
		gotoxy(5, 5); cout << "旨收收收收收收收收收旬收收收收收收收收收收收收收收收收收旬" << endl;
		gotoxy(5, 6); cout << "早 旨收收收收收旬 早                 早" << endl;
		gotoxy(5, 7); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(5, 8); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(5, 9); cout << "早 早     早 早                 早" << endl;
		gotoxy(5, 10); cout << "早 早     早 早                 早" << endl;
		gotoxy(5, 11); cout << "早 曲收收收收收旭 早                 早" << endl;
		gotoxy(5, 12); cout << "曲收收收收收收收收收旭收收收收收收收收收收收收收收收收收旭" << endl;


		gotoxy(38, 5); cout << "旨收收收收收收收收收旬收收收收收收收收收收收收收收收收收旬" << endl;
		gotoxy(38, 6); cout << "早 旨收收收收收旬 早                 早" << endl;
		gotoxy(38, 7); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(38, 8); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(38, 9); cout << "早 早     早 早                 早" << endl;
		gotoxy(38, 10); cout << "早 早     早 早                 早" << endl;
		gotoxy(38, 11); cout << "早 曲收收收收收旭 早                 早" << endl;
		gotoxy(38, 12); cout << "曲收收收收收收收收收旭收收收收收收收收收收收收收收收收收旭" << endl;

		gotoxy(5, 21); cout << "旨收收收收收收收收收旬收收收收收收收收收收收收收收收收收旬" << endl;
		gotoxy(5, 22); cout << "早 旨收收收收收旬 早                 早" << endl;
		gotoxy(5, 23); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(5, 24); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(5, 25); cout << "早 早     早 早                 早" << endl;
		gotoxy(5, 26); cout << "早 早     早 早                 早" << endl;
		gotoxy(5, 27); cout << "早 曲收收收收收旭 早                 早" << endl;
		gotoxy(5, 28); cout << "曲收收收收收收收收收旭收收收收收收收收收收收收收收收收收旭" << endl;

		gotoxy(38, 21); cout << "旨收收收收收收收收收旬收收收收收收收收收收收收收收收收收旬" << endl;
		gotoxy(38, 22); cout << "早 旨收收收收收旬 早                 早" << endl;
		gotoxy(38, 23); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(38, 24); cout << "早 早收收收收收早 早                 早" << endl;
		gotoxy(38, 25); cout << "早 早     早 早                 早" << endl;
		gotoxy(38, 26); cout << "早 早     早 早                 早" << endl;
		gotoxy(38, 27); cout << "早 曲收收收收收旭 早                 早" << endl;
		gotoxy(38, 28); cout << "曲收收收收收收收收收旭收收收收收收收收收收收收收收收收收旭" << endl;
		
		for (patientIt it = result.first; it != result.second; it++) {
			Patient* patient = it->second;

				if (it->second->roomNum == 101 || it->second->roomNum == 201 ||
					it->second->roomNum == 301 || it->second->roomNum == 401) {
					gotoxy(17, 7); cout << "檜葷 : " << patient->Name << endl;
					gotoxy(17, 8); cout << "釭檜 : " << patient->Age <<"撮" << endl;
					gotoxy(17, 9); cout << "撩滌 : " << patient->sex << endl;
					gotoxy(17, 10); cout << "�ˊ� : " << patient->roomNum <<"��"<< endl;
					gotoxy(17, 11); cout << "隸鼻 : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 102 || it->second->roomNum == 202 ||
					it->second->roomNum == 302 || it->second->roomNum == 402) {
					gotoxy(49, 7); cout << "檜葷 : " << patient->Name << endl;
					gotoxy(49, 8); cout << "釭檜 : " << patient->Age <<"撮"<< endl;
					gotoxy(49, 9); cout << "撩滌 : " << patient->sex << endl;
					gotoxy(49, 10); cout << "�ˊ� : " << patient->roomNum <<"��" << endl;
					gotoxy(49, 11); cout << "隸鼻 : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 103 || it->second->roomNum == 203 ||
					it->second->roomNum == 303 || it->second->roomNum == 403) {
					gotoxy(17, 23); cout << "檜葷 : " << patient->Name << endl;
					gotoxy(17, 24); cout << "釭檜 : " << patient->Age <<"撮"<< endl;
					gotoxy(17, 25); cout << "撩滌 : " << patient->sex << endl;
					gotoxy(17, 26); cout << "�ˊ� : " << patient->roomNum <<"��"<< endl;
					gotoxy(17, 27); cout << "隸鼻 : " << patient->symptom << endl;
					
				}
				else if (it->second->roomNum == 104 || it->second->roomNum == 204 ||
					it->second->roomNum == 304 || it->second->roomNum == 404) {
					gotoxy(49, 23); cout << "檜葷 : " << patient->Name << endl;
					gotoxy(49, 24); cout << "釭檜 : " << patient->Age <<"撮"<< endl;
					gotoxy(49, 25); cout << "撩滌 : " << patient->sex << endl;
					gotoxy(49, 26); cout << "�ˊ� : " << patient->roomNum <<"��" << endl;
					gotoxy(49, 27); cout << "隸鼻 : " << patient->symptom << endl;
				
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
	cout << "瓊戲褒 �素睎� 煽翕擊 殮溘ж撮蹂, (詭景煎 陛晦 = 0 殮溘) >>";

	cin >> ill;
	pair<patientIt, patientIt> result = patientMap.equal_range(ill);
	if (ill == "0") { system("cls"); return; }
	if (result.first == result.second) {
		cout << "斜楛 煽翕擎 橈蝗棲棻, 棻衛 殮溘п 輿撮蹂." << endl;
		goto FIRST;
	}
	else {
		cout << "殮錳ж褒 �素睎� 檜葷擊 殮溘ж撮蹂 >>";
		cin >> name;
		cout << endl;

		for (patientIt it = result.first; it != result.second; it++) {

			if (it->second->Name == name) {

				Patient* patient = it->second;
			REEDIT:
				cout << it->second->Name << "椒 殮錳й �ˊШ� 殮溘п 輿撮蹂 >>" << "\n";
				cin >> room;
				for (patientIt it = result.first; it != result.second; it++) {

					if (it->second->roomNum != room) {
						cout << name << "椒 橡葆釭 殮錳ж褊棲梱? >> " << endl;
						cin >> day;
						patient->roomNum = room;
						patient->money = day * DAY_COUNT;
						cout << "綠辨 = " << patient->money << "陶睡 睡饕 萄董棲棻." << endl << endl;

						cout << patient->roomNum << "�αn" << patient->Name <<" 椒"
							<< endl << patient->Age <<  "撮" << endl << "隸鼻 : "<< patient->symptom << endl;
						cout << "殮褒 諫猿 腎歷蝗棲棻." << endl << endl;
						break;
					}
					else {
						cout << room << "�ㄣ� 棻艇 �素痚� 餌辨醞殮棲棻 棻衛 殮溘 睡饕萄董棲棻>> " << endl;
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



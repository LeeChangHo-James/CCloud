#include "Depression.h"
#include "Task.h"






Depression::Depression(string name, int age, string ID_NUM, string symptom) {
	this->sex = checkSex(ID_NUM);
	this->Name = name;
	this->Age = age;
	this->ID_NUM = ID_NUM;
	this->symptom = symptom;
	gotoxy(7, 11); cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
	gotoxy(7, 12); cout << "��               ��               ��               ��               ��" << endl;
	gotoxy(7, 13); cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
	gotoxy(7, 14); cout << "��               ��               ��               ��               ��" << endl;
	gotoxy(7, 15); cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
	gotoxy(14, 12); cout << "�̸�" << endl;
	gotoxy(13, 14); cout << this->Name << endl;
	gotoxy(30, 12); cout << "����" << endl;
	gotoxy(30, 14); cout << this->sex << endl;
	gotoxy(46, 12); cout << "����" << endl;
	gotoxy(47, 14); cout << this->Age << endl;
	gotoxy(62, 12); cout << "����" << endl;
	gotoxy(61, 14); cout << this->symptom << endl;
	cout << endl;
	cout << endl;
	cout << "================================================================================" << endl;
}
void Depression::seeDr() {

	cout << this->Name << "�� �ݰ����ϴ�. ��������� Dr.Kim �Դϴ�." << endl
		<< "����� ������ ���� �������?" << endl
		<< "�Կ������� ����ũ �������� �����ø� �ǰ�,"<<	endl;
	
}
void Depression::checkSymptom() {

	cout << "����� ȯ�� ����� �Դϴ�." << endl << endl;

}

void Depression::Drug() {
	cout << "���� ����Ƽ�������� 1��, �÷����ƾ 2�� ���� 30�п� ��ø� �˴ϴ�." << endl << endl;
}

string Depression::checkSex(string sex){
	auto it = sex.find("-1");
	if (it != string::npos) {
		return "����";
	}
	else
		return "����";
}

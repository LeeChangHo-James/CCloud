#include "Schizophrenia.h"
#include "Task.h"


Schizophrenia::Schizophrenia(string name, int age, string ID_NUM, string symptom) {
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
void Schizophrenia::seeDr() {
	cout << this->Name << "�� �ݰ����ϴ�. ���������� Dr.Jason �Դϴ�." << endl
		<< "������ ������ ���� �������?" << endl << "�Կ������� ����ũ �������� �����ø� �ǰ�," << endl;
	
}
void Schizophrenia::checkSymptom() {
	cout << "������ ȯ�� ����� �Դϴ�." << endl << endl;

}

void Schizophrenia::Drug() {
	cout << "���� ��Ÿ�� 1��, ������ 2�� ���� 30�п� ��ø� �˴ϴ�." << endl << endl;
}

string Schizophrenia::checkSex(string sex) {
	auto it = sex.find("-1");
	if (it != string::npos) {
		return "����";
	}
	else
		return "����";
}
#include "PsychiatricHospital.h"
#include <iostream>

#include <map>

using namespace std;



void PsychiatricHospital::PatientRegistration()
{

	int k;

	cout << "�̸� : " << endl;
	cin >> name;

	cout << "���� : " << endl;
	cin >> age;

	puts("�ֹι�ȣ : ");
	puts("��)999999-1111111");
	for (k = 0; k < 14; k++)
	{
		cin >> rrn[k];
	}
	rrn[14] = { };
	if (rrn[7] == '1')
		cout << "���� : ��" << endl;
	else if (rrn[7] == '2')
		cout << "���� : ��" << endl;
	else if (rrn[7] == '3')
		cout << "���� : ��" << endl;
	else if (rrn[7] == '4')
		cout << "���� : ��" << endl;
	else
		cout << "��������?" << endl;

	cout << "�ڵ�����ȣ : " << endl;
	cin >> pn;

	cout << "���� : " << endl;
	cin >> ward;

}

void PsychiatricHospital::AllPatients()
{
	
	cout << "�̸� : " << this->name << endl;
	cout << "���� : " << this->age << endl;
	cout << "�ֹε�Ϲ�ȣ : " << this->rrn << endl;
	cout << "�ڵ�����ȣ : " <<this->pn << endl;
	cout << "���� : " << this->ward << endl;
	
	
	cout << endl << endl;
}

void PsychiatricHospital::CareerReservation()
{
	
}
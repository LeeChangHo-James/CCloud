#include <iostream>
#include <string>
#include <conio.h>
#include "PsychiatricHospital.h"


using namespace std;


char Menu()
{
	cout << "1.ȯ�ڵ��" << endl;
	cout << "2.��ݼ���" << endl;
	cout << "3.ȯ����ü����" << endl;
	cout << "4.ȯ�ڰ˻�" << endl;
	cout << "5.���Ό��" << endl;
	cout << "6.��ݼ���" << endl;
	cout << "7.����Ȯ��" << endl;
	cout << "0.���α׷�����" << endl;
	return _getch();
}


void main()
{
	bool choice = true;
	PsychiatricHospital Pr;
	while (choice)
	{
		switch (Menu())
		{
		case '1':
			Pr.PatientRegistration();
			break;
		case '2':
			break;
		case '3':
			Pr.AllPatients();
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '0':
			choice = false;
			break;
		}
	}
}

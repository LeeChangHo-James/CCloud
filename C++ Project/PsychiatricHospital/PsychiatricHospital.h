/*
mentalunease �����Ҿ�
depression �����
insomnia �Ҹ���
schizophrenia ���źп�
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;


class PsychiatricHospital
{

protected:
	string name; // �̸�
	int age; // ����
	char rrn[14];
	int nrr; //�ֹε�Ϲ�ȣ : resident registration number
	string symptom; // ����
	string pn; // ���ѹ�v
	int ward; // ����


public:
	void PatientRegistration(); // ȯ�ڵ��
	//void PatientSearch(); // ȯ�ڰ˻�
	void AllPatients(); // ȯ����ü����
	//void PatientSearch(); // ȯ�ڰ˻�
	void CareerReservation(); // ���ο���
	//void ChargeStorage(); // ��ݼ���
	//void CheckSickroom(); // ����Ȯ��

};



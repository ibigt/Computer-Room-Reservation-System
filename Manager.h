#pragma once
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Manager : public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//ȥ�ع���
	void initVector();

public:
	
	vector<Student> vStu;

	vector<Teacher> vTea;

};
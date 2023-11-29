#pragma once
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
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

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int select, int id);

public:
	
	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

};
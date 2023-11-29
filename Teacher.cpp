#include <fstream>
#include <algorithm>
#include "Teacher.h"
#include "GlobalFile.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι��� (ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " ;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{

}

//���ԤԼ
void Teacher::validOrder()
{

}

//��ʼ������
void Teacher::initVector()
{
	ComputerRoom c;

	ifstream ifs_C;
	vCom.clear();


	ifs_C.open(COMPUTER_FILE, ios::in);
	if (!ifs_C.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (ifs_C >> c.m_ComId && ifs_C >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;
	ifs_C.close();

}
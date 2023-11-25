#include <fstream>
#include "Manager.h"
#include "GlobalFile.h"

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//����˺�  
void Manager::addPerson()
{
	int select = 0;
	string fileName;
	int id = 0;
	string name;
	string pwd;

	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	cout << "����������˺ŵ����ͣ�" ;

	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		cout << "������ѧ�ţ�" ;
		cin >> id;
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		cout << "�������ʦ��ţ�" ;
		cin >> id;
	}

	cout << "������������" ;
	cin >> name;
	cout << "���������룺" ;
	cin >> pwd;


	ofstream ofs;
	//ios::app ׷��д��ios::out Ϊд���ļ�
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");
	ofs.close();

}

//�鿴�˺�
void Manager::showPerson()
{
}

//�鿴������Ϣ
void Manager::showComputer()
{
}

//���ԤԼ��¼
void Manager::cleanFile()
{
}

//��ʼ������
void Manager::initVector()
{
	ifstream ifs;
	vStu.clear();
	vStu.clear();


	Student s;
	
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close(); 


	Teacher t;

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close(); 

}
#include <fstream>
#include <algorithm>
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
	int id = 0;
	int select = 0;

	string tip;
	string pwd;
	string name;
	string fileName;
	string errorTip;

	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	cout << "����������˺ŵ����ͣ�" ;

	cin >> select;


	if (select == 1)
	{
		fileName = STUDENT_FILE;
		errorTip = "ѧ�����ظ������������룡";
		tip =  "������ѧ�ţ�";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		errorTip = "ְ�����ظ������������룡";
		tip = "�������ʦ��ţ�";
	}

	while (true)
	{
		cout << tip;
		cin >> id;
		bool res = checkRepeat(select, id);

		if (res)
		{
			cout << errorTip << endl;
			cout << string(80, '-') << endl;
		}
		else
		{
			cout << "������������";
			cin >> name;
			cout << "���������룺";
			cin >> pwd;

			ofstream ofs;
			//ios::app ׷��д��ios::out Ϊд���ļ�
			ofs.open(fileName, ios::out | ios::app);
			ofs << id << " " << name << " " << pwd << endl;
			cout << "��ӳɹ���" << endl;

			system("pause");
			system("cls");
			ofs.close();

			//��ʼ������
			initVector();

			break;
		}

	}

}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << ", ������" << s.m_Name << "�� ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << ", ������" << t.m_Name << "�� ���룺" << t.m_Pwd << endl;
}

void printComputerRoom(ComputerRoom& c)
{
	cout << "�����źţ�" << c.m_ComId << ", ����������" << c.m_MaxNum << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	int select = 0;

	while (true)
	{
		cout << "1���鿴����ѧ��" << endl;
		cout << "2���鿴������ʦ" << endl;
		cout << "��ѡ��鿴���ݣ�";
		cin >> select;

		if (select == 1)
		{
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else 
		{
			cout << "ѡ�����������ѡ��" << endl;
		}

	}

	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showComputer()
{
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	Student s;
	Teacher t;
	ComputerRoom c;

	ifstream ifs_S;
	ifstream ifs_T;
	ifstream ifs_C;
	
	vStu.clear();
	vTea.clear();
	vCom.clear();

	ifs_S.open(STUDENT_FILE, ios::in);
	if (!ifs_S.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (ifs_S >> s.m_Id && ifs_S >> s.m_Name && ifs_S >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs_S.clear();
	

	ifs_T.open(TEACHER_FILE, ios::in);
	if (!ifs_T.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (ifs_T >> t.m_EmpId && ifs_T >> t.m_Name && ifs_T >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs_T.close();


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

bool Manager::checkRepeat(int select, int id)
{
	if (select == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}
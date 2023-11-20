#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;


/*
* ���������������û���ѡ�񣬽��벻ͬ����ݵ�¼
* void LoginIn(string fileName, int type)
* fileName  --- �������ļ���
* type      ---  ��¼�����  ��1����ѧ����2������ʦ��3�������Ա��
*/

//��¼����
void LoginIn(string fileName, int type)
{
	int id;
	string name;
	string pwd;

	int fId;
	string fName;
	string fPwd;

	Identity* person = nullptr;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}


	if (type == 1) 
	{
		//ѧ����¼
		cout << "���������ѧ�ţ�" ;
		cin >> id;
	}
	else if (type == 2) 
	{
		//��ʦ��¼
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	
	cout << "�������û�����" ;
	cin >> name;

	cout << "���������룺" ;
	cin >> pwd;


	if (type == 1) 
	{
		//ѧ����¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ�� " << name << " ��¼��֤�ɹ���" << endl;
				cout << string(30, '-') << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				return;
			}
		}
				
	}
	else if (type == 2) 
	{
		//��ʦ��¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ " << name << " ��¼��֤�ɹ���" << endl;
				cout << string(30, '-') << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}

	}
	else if(type == 3)
	{
		while (ifs >> fName && ifs >> fPwd)
		{
			//����Ա��½��֤
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա " << name << " ��¼��֤�ɹ���" << endl;
				cout << string(30, '-') << endl;
				//system("pause");
				system("cls");
				person = new Manager(name, pwd);
				return;
			}
		}

	}

	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity* person)
{
	while (true)
	{
		//����Ա�˵�
		person->operMenu();

		//����ָ��ǿת������ָ�룬���Ե���˽�нӿ�
		Manager* manager = (Manager*)person;

		int select;
		cin >> select;
		
		switch(select)
		{
			case 1:
			{
				cout << "����˺�" << endl;
				manager->addPerson();
				break;
			}
			case 2:
			{
				cout << "�鿴�˺�" << endl;
				manager->showPerson();
				break;
			}
			case 3:
			{
				cout << "�鿴����" << endl;
				manager->showComputer();
				break;
			}
			case 4:
			{
				cout << "���ԤԼ" << endl;
				manager->cleanFile();
				break;
			}
			default:
			{
				delete manager;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

int main() {

	int select = 0;

	cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";

	cin >> select;

	switch(select)
	{
		case 1:
			LoginIn(STUDENT_FILE, select);
			break;
		case 2:
			LoginIn(TEACHER_FILE, select);
			break;
		case 3:
			LoginIn(ADMIN_FILE, select);
			break;
		case 0:
		{
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");
			return 0;
		}
		default:
		{
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}
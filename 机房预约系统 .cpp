#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

/*
* �ڻ���ԤԼϵͳ.cpp�У����û���¼���ǹ���Ա����ӹ���Ա�˵��ӿ�
* ����ͬ�ķ�֧�ṩ����
* ����˺�
* �鿴�˺�
* �鿴����
* ���ԤԼ
* ע����¼
* ʵ��ע������
*/
void managerMenu(Identity* person)
{
	//����ָ��ǿת������ָ�룬���Ե���˽�нӿ�
	Manager* manager = (Manager*)person;

	while (true)
	{
		//����Ա�˵�
		//����ָ��ֱ�ӵ��ù����ӿ�
		person->operMenu();

		int select;
		cin >> select;

		switch (select)
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
			case 0:
			{
				delete manager;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "����ѡ�����������ѡ��" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}

	delete manager;
}


/*
* �ڻ���ԤԼϵͳ.cpp�У����û���¼����ѧ�������ѧ���˵��ӿ�
* ����ͬ�ķ�֧�ṩ����
* ����ԤԼ
* �鿴�ҵ�ԤԼ
* �鿴����ԤԼ
* ȡ��ԤԼ
* ע����¼
* ʵ��ע������
*/
void studentMenu(Identity* person)
{
	Student* stu = (Student*)person;

	while (true)
	{
		person->operMenu();

		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1:
			{
				cout << "����ԤԼ" << endl;
				stu->applyOrder();
				break;
			}
			case 2:
			{
				cout << "�鿴�ҵ�ԤԼ" << endl;
				stu->showMyOrder();
				break;
			}
			case 3:
			{
				cout << "�鿴����ԤԼ" << endl;
				stu->showAllOrder();
				break;
			}
			case 4:
			{
				cout << "ȡ��ԤԼ" << endl;
				stu->cancelOrder();
				break;
			}
			case 0:
			{
				delete stu;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "����ѡ�����������ѡ��" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		
	}

	delete stu;

}


/*
* �ڻ���ԤԼϵͳ.cpp�У����û���¼���ǽ�ʦ����ӽ�ʦ�˵��ӿ�
* ����ͬ�ķ�֧�ṩ����
* �鿴����ԤԼ
* ���ԤԼ
* ע����¼
* ʵ��ע������
*/
void teacherMenu(Identity* person)
{
	Teacher* tea = (Teacher*)person;

	while (true)
	{
		person->operMenu();

		int select = 0;
		cin >> select;
		
		switch (select)
		{
			case 1:
			{
				cout << "�鿴����ԤԼ" << endl;
				tea->showAllOrder();
				break;
			}
			case 2:
			{
				cout << "���ԤԼ" << endl;
				tea->validOrder();
				break;
			}
			case 0:
			{
				delete tea;
				cout << "ע���ɹ���" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "����ѡ�����������ѡ��" << endl;
				system("pause");
				system("cls");
				break;
			}

		}
		
	}

	delete tea;

}

/*
* ��¼����
* ���������������û���ѡ�񣬽��벻ͬ����ݵ�¼
* void LoginIn(string fileName, int type)
* fileName  --- �������ļ���
* type      ---  ��¼�����  ��1����ѧ����2������ʦ��3�������Ա��
*/

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
				cout << string(50, '-') << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ". ";
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}

				cout << endl << "ѧ�� " << name << " ��¼��֤�ɹ���" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
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
				cout << string(50, '-') << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ". ";
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}
				cout << endl << "��ʦ " << name << " ��¼��֤�ɹ���" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
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
				cout << string(50, '-') << endl;
				for(int i = 0; i < 6; i++)
				{
					cout << ". " ;
					std::this_thread::sleep_for(std::chrono::milliseconds(200)); 
				}
				cout << endl << "����Ա " << name << " ��¼��֤�ɹ���" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}

	}

	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {

	int select = 0;

	while (true)
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
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
		switch (select)
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
	}

	system("pause");

	return 0;
}
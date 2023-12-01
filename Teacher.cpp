#include <fstream>
#include <algorithm>
#include "Teacher.h"
#include "OrderFile.h"
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
	OrderFile of;
	if (of.m_orderNum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_orderNum; i++)
	{
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}

		cout << status << endl;

	}

	system("pause");
	system("cls");

}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_orderNum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}



	while (true)
	{
		int index = 1;
		vector<int> vec;
		cout << "����˵�ԤԼ��¼���£�" << endl;
		for (int i = 0; i < of.m_orderNum; i++)
		{
			if (of.m_orderData[i]["status"] == "1")
			{
				vec.push_back(i);
				cout << index++ << "��" << of.m_orderData[i]["stuName"];
				cout << " ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				cout << " ״̬�������" << endl;
			}
		}

		int select = 0;
		int ret = 0;

		cout << "��������˵�ԤԼ��¼(0������)��" ;
		cin >> select;

		if (select >= 0 && select <= vec.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��(1��ͨ�� 2����ͨ��)��" ;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[vec[select-1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[vec[select-1]]["status"] = "-1";
				}

				of.updateOrderFile();
				cout << "�����ϣ�" << endl;

				int ans = 0;
				cout << "�Ƿ��������(1���� 2����)��";
				cin >> ans;
				if (ans == 1)
				{
					system("cls");
					continue;
				}
				break;
			}
		}
		else
		{
			cout << "��������������ѡ��" << endl;
		}
	}

	system("pause");
	system("cls");

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
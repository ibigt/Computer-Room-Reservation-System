#include <fstream>
#include <algorithm>
#include "Student.h"
#include "OrderFile.h"
#include "GlobalFile.h"

//Ĭ�Ϲ��캯��
Student::Student() 
{
}

//�вι��캯��
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//�����˵�
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//����ԤԼ
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;

	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" ;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������룺" ;
	}

	cout << "1������" << endl;
	cout << "2������" << endl;
	cout << "����������ԤԼ��ʱ��Σ�" ;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������룺";
	}

	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;
	cout << "��ѡ�������" ;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룺";
	}

	cout << "ԤԼ�ɹ��������..." << endl;
	
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
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
		// int atoi(const char* str); ���ַ���ת��������
		// c_str()���ǽ�C++��stringת��Ϊ(const char*)C����ַ�������
		if (this->m_Id != atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			continue;
		}
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

//�鿴����ԤԼ
void Student::showAllOrder()
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_orderNum == 0)
	{
		cout << "������ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	int index = 1;
	vector<int> vec;
	cout << "����ԤԼ��¼���£�" << endl;
	for (int i = 0; i < of.m_orderNum; i++)
	{
		if (this->m_Id != atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			continue;
		}

		if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
		{
			vec.push_back(i);
			cout << index++ <<"��ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else
			{
				status += "ԤԼ�ɹ�";
			}
			cout << status << endl;
		}
	}

	cout << "������ȡ���ļ�¼(0������)��" ;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= vec.size())
		{
			if (select == 0)
			{
				break;
			}

			of.m_orderData[vec[select - 1]]["status"] = "0";
			of.updateOrderFile();
			cout << "��ȡ��ԤԼ" << endl;
			break;
		}
		else
		{
			cout << "�����������������룺" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ʼ������
void Student::initVector()
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

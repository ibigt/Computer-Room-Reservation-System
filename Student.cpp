#include "Student.h"

//Ĭ�Ϲ��캯��
Student::Student() 
{
}

//�вι��캯��
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = id;
	this->m_Pwd = pwd;
}

//�����˵�
void Student::operMenu()
{
	cout << "��ӭѧ��������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Student::applyOrder()
{

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{

}

//�鿴����ԤԼ
void Student::showAllOrder()
{

}

//ȡ��ԤԼ
void Student::cancelOrder()
{

}
#pragma once
#include "Identity.h"

using namespace std;

class Student : public Identity 
{
	public:

		//Ĭ�Ϲ��캯��
		Student();

		//�вι��캯��
		Student(int id, string name, string pwd);

		//�����˵�
		virtual void operMenu();

		//����ԤԼ
		void applyOrder();

		//�鿴�ҵ�ԤԼ
		void showMyOrder();

		//�鿴����ԤԼ
		void showAllOrder();

		//ȡ��ԤԼ
		void cancelOrder();

	public:
		int m_Id;

};

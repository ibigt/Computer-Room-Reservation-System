#pragma once
#include <iostream>
#include "Identity.h"

using namespace std;

class Teacher :Identity
{
	public:
		//Ĭ�Ϲ��캯��
		Teacher();

		//���ι��캯��
		Teacher(int id, string name, string pwd);

		//�����˵�
		virtual void operMenu();

		//�鿴����ԤԼ
		void showAllOrder();

		//���ԤԼ
		void validOrder();

	public:
		int m_EmpId;

};
#pragma once
#include "Identity.h"

using namespace std;

class Student : public Identity 
{
	public:

		//默认构造函数
		Student();

		//有参构造函数
		Student(int id, string name, string pwd);

		//操作菜单
		virtual void operMenu();

		//申请预约
		void applyOrder();

		//查看我的预约
		void showMyOrder();

		//查看所有预约
		void showAllOrder();

		//取消预约
		void cancelOrder();

	public:
		int m_Id;

};

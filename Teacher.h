#pragma once
#include "Identity.h"

using namespace std;

class Teacher : public Identity
{
	public:
		//默认构造函数
		Teacher();

		//含参构造函数
		Teacher(int id, string name, string pwd);

		//操作菜单
		virtual void operMenu();

		//查看所有预约
		void showAllOrder();

		//审核预约
		void validOrder();

	public:
		int m_EmpId;

};
#include <fstream>
#include <algorithm>
#include "Teacher.h"
#include "OrderFile.h"
#include "GlobalFile.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造 (职工编号，姓名，密码)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " ;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_orderNum == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_orderNum; i++)
	{
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}

		cout << status << endl;

	}
	system("pause");
	system("cls");

}

//审核预约
void Teacher::validOrder()
{

}

//初始化容器
void Teacher::initVector()
{
	ComputerRoom c;

	ifstream ifs_C;
	vCom.clear();


	ifs_C.open(COMPUTER_FILE, ios::in);
	if (!ifs_C.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	while (ifs_C >> c.m_ComId && ifs_C >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;
	ifs_C.close();

}
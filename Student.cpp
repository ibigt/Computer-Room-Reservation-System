#include <fstream>
#include <algorithm>
#include "Student.h"
#include "OrderFile.h"
#include "GlobalFile.h"

//默认构造函数
Student::Student() 
{
}

//有参构造函数
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//操作菜单
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： ";
}

//申请预约
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "请输入申请预约的时间：" ;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入：" ;
	}

	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	cout << "请输入申请预约的时间段：" ;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入：";
	}

	cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;
	cout << "请选择机房：" ;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入：";
	}

	cout << "预约成功！审核中..." << endl;
	
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

//查看我的预约
void Student::showMyOrder()
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
		// int atoi(const char* str); 将字符串转换成整数
		// c_str()就是将C++的string转化为(const char*)C风格字符串数组
		if (this->m_Id != atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			continue;
		}
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

//查看所有预约
void Student::showAllOrder()
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

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_orderNum == 0)
	{
		cout << "您暂无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	int index = 1;
	vector<int> vec;
	cout << "您得预约记录如下：" << endl;
	for (int i = 0; i < of.m_orderNum; i++)
	{
		if (this->m_Id != atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			continue;
		}

		if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
		{
			vec.push_back(i);
			cout << index++ <<"、预约日期：周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderData[i]["roomId"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else
			{
				status += "预约成功";
			}
			cout << status << endl;
		}
	}

	cout << "请输入取消的记录(0代表返回)：" ;
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
			cout << "已取消预约" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入：" << endl;
		}
	}
	system("pause");
	system("cls");
}

//初始化容器
void Student::initVector()
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

#include <fstream>
#include <algorithm>
#include "Manager.h"
#include "GlobalFile.h"

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： ";
}

//添加账号  
void Manager::addPerson()
{
	int id = 0;
	int select = 0;

	string tip;
	string pwd;
	string name;
	string fileName;
	string errorTip;

	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	cout << "请输入添加账号的类型：" ;

	cin >> select;


	if (select == 1)
	{
		fileName = STUDENT_FILE;
		errorTip = "学生号重复，请重新输入！";
		tip =  "请输入学号：";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		errorTip = "职工号重复，请重新输入！";
		tip = "请输入教师编号：";
	}

	while (true)
	{
		cout << tip;
		cin >> id;
		bool res = checkRepeat(select, id);

		if (res)
		{
			cout << errorTip << endl;
			cout << string(80, '-') << endl;
		}
		else
		{
			cout << "请输入姓名：";
			cin >> name;
			cout << "请输入密码：";
			cin >> pwd;

			ofstream ofs;
			//ios::app 追加写，ios::out 为写打开文件
			ofs.open(fileName, ios::out | ios::app);
			ofs << id << " " << name << " " << pwd << endl;
			cout << "添加成功！" << endl;

			system("pause");
			system("cls");
			ofs.close();

			//初始化容器
			initVector();

			break;
		}

	}

}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << ", 姓名：" << s.m_Name << "， 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << ", 姓名：" << t.m_Name << "， 密码：" << t.m_Pwd << endl;
}

void printComputerRoom(ComputerRoom& c)
{
	cout << "机房门号：" << c.m_ComId << ", 机房容量：" << c.m_MaxNum << endl;
}

//查看账号
void Manager::showPerson()
{
	int select = 0;

	while (true)
	{
		cout << "1、查看所有学生" << endl;
		cout << "2、查看所有老师" << endl;
		cout << "请选择查看内容：";
		cin >> select;

		if (select == 1)
		{
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else 
		{
			cout << "选择错误，请重新选择！" << endl;
		}

	}

	system("pause");
	system("cls");

}

//查看机房信息
void Manager::showComputer()
{
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	Student s;
	Teacher t;
	ComputerRoom c;

	ifstream ifs_S;
	ifstream ifs_T;
	ifstream ifs_C;
	
	vStu.clear();
	vTea.clear();
	vCom.clear();

	ifs_S.open(STUDENT_FILE, ios::in);
	if (!ifs_S.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	while (ifs_S >> s.m_Id && ifs_S >> s.m_Name && ifs_S >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs_S.clear();
	

	ifs_T.open(TEACHER_FILE, ios::in);
	if (!ifs_T.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	while (ifs_T >> t.m_EmpId && ifs_T >> t.m_Name && ifs_T >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为： " << vTea.size() << endl;
	ifs_T.close();


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

bool Manager::checkRepeat(int select, int id)
{
	if (select == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}
#include <fstream>
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
	int select = 0;
	string fileName;
	int id = 0;
	string name;
	string pwd;

	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	cout << "请输入添加账号的类型：" ;

	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		cout << "请输入学号：" ;
		cin >> id;
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		cout << "请输入教师编号：" ;
		cin >> id;
	}

	cout << "请输入姓名：" ;
	cin >> name;
	cout << "请输入密码：" ;
	cin >> pwd;


	ofstream ofs;
	//ios::app 追加写，ios::out 为写打开文件
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");
	ofs.close();

}

//查看账号
void Manager::showPerson()
{
}

//查看机房信息
void Manager::showComputer()
{
}

//清空预约记录
void Manager::cleanFile()
{
}

//初始化容器
void Manager::initVector()
{
	ifstream ifs;
	vStu.clear();
	vStu.clear();


	Student s;
	
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); 


	Teacher t;

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为： " << vTea.size() << endl;
	ifs.close(); 

}
#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;


/*
* 功能描述：根据用户的选择，进入不同的身份登录
* void LoginIn(string fileName, int type)
* fileName  --- 操作的文件名
* type      ---  登录的身份  （1代表学生、2代表老师、3代表管理员）
*/

//登录功能
void LoginIn(string fileName, int type)
{
	int id;
	string name;
	string pwd;

	int fId;
	string fName;
	string fPwd;

	Identity* person = nullptr;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}


	if (type == 1) 
	{
		//学生登录
		cout << "请输入你的学号：" ;
		cin >> id;
	}
	else if (type == 2) 
	{
		//教师登录
		cout << "请输入你的职工号：";
		cin >> id;
	}
	
	cout << "请输入用户名：" ;
	cin >> name;

	cout << "请输入密码：" ;
	cin >> pwd;


	if (type == 1) 
	{
		//学生登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生 " << name << " 登录验证成功！" << endl;
				cout << string(30, '-') << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				return;
			}
		}
				
	}
	else if (type == 2) 
	{
		//教师登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师 " << name << " 登录验证成功！" << endl;
				cout << string(30, '-') << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}

	}
	else if(type == 3)
	{
		while (ifs >> fName && ifs >> fPwd)
		{
			//管理员登陆验证
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员 " << name << " 登录验证成功！" << endl;
				cout << string(30, '-') << endl;
				//system("pause");
				system("cls");
				person = new Manager(name, pwd);
				return;
			}
		}

	}

	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity* person)
{
	while (true)
	{
		//管理员菜单
		person->operMenu();

		//父类指针强转成子类指针，可以调用私有接口
		Manager* manager = (Manager*)person;

		int select;
		cin >> select;
		
		switch(select)
		{
			case 1:
			{
				cout << "添加账号" << endl;
				manager->addPerson();
				break;
			}
			case 2:
			{
				cout << "查看账号" << endl;
				manager->showPerson();
				break;
			}
			case 3:
			{
				cout << "查看机房" << endl;
				manager->showComputer();
				break;
			}
			case 4:
			{
				cout << "清空预约" << endl;
				manager->cleanFile();
				break;
			}
			default:
			{
				delete manager;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

int main() {

	int select = 0;

	cout << "======================  欢迎来到机房预约系统  ====================="
		<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";

	cin >> select;

	switch(select)
	{
		case 1:
			LoginIn(STUDENT_FILE, select);
			break;
		case 2:
			LoginIn(TEACHER_FILE, select);
			break;
		case 3:
			LoginIn(ADMIN_FILE, select);
			break;
		case 0:
		{
			cout << "欢迎下一次使用！" << endl;
			system("pause");
			return 0;
		}
		default:
		{
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}
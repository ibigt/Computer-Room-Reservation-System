#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

/*
* 在机房预约系统.cpp中，当用户登录的是管理员，添加管理员菜单接口
* 将不同的分支提供出来
* 添加账号
* 查看账号
* 查看机房
* 清空预约
* 注销登录
* 实现注销功能
*/
void managerMenu(Identity* person)
{
	//父类指针强转成子类指针，可以调用私有接口
	Manager* manager = (Manager*)person;

	while (true)
	{
		//管理员菜单
		//子类指针直接调用公共接口
		person->operMenu();

		int select;
		cin >> select;

		switch (select)
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
			case 0:
			{
				delete manager;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "操作选择错误，请重新选择！" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}

	delete manager;
}


/*
* 在机房预约系统.cpp中，当用户登录的是学生，添加学生菜单接口
* 将不同的分支提供出来
* 申请预约
* 查看我的预约
* 查看所有预约
* 取消预约
* 注销登录
* 实现注销功能
*/
void studentMenu(Identity* person)
{
	Student* stu = (Student*)person;

	while (true)
	{
		person->operMenu();

		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1:
			{
				cout << "申请预约" << endl;
				stu->applyOrder();
				break;
			}
			case 2:
			{
				cout << "查看我的预约" << endl;
				stu->showMyOrder();
				break;
			}
			case 3:
			{
				cout << "查看所有预约" << endl;
				stu->showAllOrder();
				break;
			}
			case 4:
			{
				cout << "取消预约" << endl;
				stu->cancelOrder();
				break;
			}
			case 0:
			{
				delete stu;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "操作选择错误，请重新选择！" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		
	}

	delete stu;

}


/*
* 在机房预约系统.cpp中，当用户登录的是教师，添加教师菜单接口
* 将不同的分支提供出来
* 查看所有预约
* 审核预约
* 注销登录
* 实现注销功能
*/
void teacherMenu(Identity* person)
{
	Teacher* tea = (Teacher*)person;

	while (true)
	{
		person->operMenu();

		int select = 0;
		cin >> select;
		
		switch (select)
		{
			case 1:
			{
				cout << "查看所有预约" << endl;
				tea->showAllOrder();
				break;
			}
			case 2:
			{
				cout << "审核预约" << endl;
				tea->validOrder();
				break;
			}
			case 0:
			{
				delete tea;
				cout << "注销成功！" << endl;
				system("pause");
				system("cls");
				return;
			}
			default:
			{
				cout << "操作选择错误，请重新选择！" << endl;
				system("pause");
				system("cls");
				break;
			}

		}
		
	}

	delete tea;

}

/*
* 登录功能
* 功能描述：根据用户的选择，进入不同的身份登录
* void LoginIn(string fileName, int type)
* fileName  --- 操作的文件名
* type      ---  登录的身份  （1代表学生、2代表老师、3代表管理员）
*/

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
				cout << string(50, '-') << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ". ";
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}

				cout << endl << "学生 " << name << " 登录验证成功！" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
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
				cout << string(50, '-') << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ". ";
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}
				cout << endl << "教师 " << name << " 登录验证成功！" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
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
				cout << string(50, '-') << endl;
				for(int i = 0; i < 6; i++)
				{
					cout << ". " ;
					std::this_thread::sleep_for(std::chrono::milliseconds(200)); 
				}
				cout << endl << "管理员 " << name << " 登录验证成功！" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}

	}

	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {

	int select = 0;

	while (true)
	{
		cout << "======================  欢迎来到机房预约系统  =====================" << endl;
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
		switch (select)
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
	}

	system("pause");

	return 0;
}
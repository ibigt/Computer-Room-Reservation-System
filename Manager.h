#pragma once
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
using namespace std;

class Manager : public Identity
{
public:

	//默认构造
	Manager();

	//有参构造  管理员姓名，密码
	Manager(string name, string pwd);

	//选择菜单
	virtual void operMenu();

	//添加账号  
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//去重功能
	void initVector();

	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int select, int id);

public:
	
	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

};
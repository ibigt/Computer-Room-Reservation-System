#pragma once
#include <iostream>

using namespace std;

//身份抽象类
class Identity
{
	public:
		//纯虚函数（定义抽象类）
		virtual void operMenu() = 0;

	public:
		string m_Name;
		string m_Pwd;

};
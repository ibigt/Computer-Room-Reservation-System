#pragma once
#include <iostream>
#include <map>
using namespace std;

class OrderFile 
{
public:
	
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrderFile();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_orderNum;

};
#include <iostream>

using namespace std;

int main() {

	int select = 0;

	cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";

	cin >> select;

	switch(select)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
		{
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");
			return 0;
		}
		default:
		{
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Pipe
{
	string pipe_name = "0km";
	int pipe_lenght = 0;
	int pipe_diametr = 0;
};

struct Station
{
	string station_name = "";
	int station_workshop = 0;
	int station_work_workshop = 0;

};


int main()
{
	Pipe pipe0;
	Station station0;
	int num = 0;
	while (1) {
		cout << "Menu:" << endl;
		cout << "1. Add pipe" << endl;
		cout << "2. Add station" << endl;
		cout << "3. View objects" << endl;
		cout << "4. Edit pipe" << endl;
		cout << "5. Edit station" << endl;
		cout << "6. Save" << endl;
		cout << "7. Download" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the command: ";
		cin >> num;
	}
}
/*int main(int x)
{
	setlocale(LC_ALL, "Russian");
	cout << "����:\n";
	cout << "1. �������� �����\n2. �������� ��\n3. �������� ���� ��������\n4. ������������� �����\n5. ������������� ��\n6. ���������\n7. ���������\n0. �����\n";
	cout << "������� �������: ";
	cin >> x;

	if (x == 1)
		cout << "1 ������� ��������� �����";
	if (x == 2)
		cout << "2 ������� ��������� ��";
	if (x == 3)
		cout << "3 ������� ������������� ��� �������";
	if (x == 4)
		cout << "4 ������� ����������� �����";
	if (x == 5)
		cout << "5 ������� ����������� ��";
	if (x == 6)
		cout << "6 ������� ��������� ���������";
	if (x == 7)
		cout << "7 ������� ���������";
	if (x == 0)
		cout << "0 ������� - �����";
	return 0;
}
*/


/*int menu(int x)
{
	cout << "������� �������: ";
	cin >> x;
	if (x == 1)
		cout<<"1. ������� ��������� �����"
	cout << x;
	return 0;
}*/


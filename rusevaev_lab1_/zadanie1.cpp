#include <iostream>
#include <string>

using namespace std;

struct Pipe
{
	string pipe_name = "0km";
	int pipe_length = 0;
	int pipe_diametr = 0;
};

struct Station
{
	string station_name = "None";
	int station_workshop = 0;
	int station_work_workshop = 0;

};

Pipe Addpipe()
{
	Pipe new_pipe;
	cout << "Add a new pipe:" << endl;
	cout << "Enter the name: ";
	cin >> new_pipe.pipe_name;
	cout << "Enter the length of pipe (m): ";
	cin >> new_pipe.pipe_length;
	cout << "Enter the diametr of pipe (mm): ";
	cin >> new_pipe.pipe_diametr;
	return new_pipe;
}

void PrintAddpipe(Pipe new_pipe)
{
	cout << endl << "Info about your pipe..." << endl;
	cout << "Name: " << new_pipe.pipe_name << "\tLength: " << new_pipe.pipe_length
		<< "\tDiameter: " << new_pipe.pipe_diametr << endl;
}

Station Addstation()
{
	Station new_station;
	cout << "Add a new CS:" << endl;
	cout << "Enter the name: ";
	cin >> new_station.station_name;
	cout << "Number of workshops: ";
	cin >> new_station.station_workshop;
	cout << "Number of work workshops: ";
	cin >> new_station.station_work_workshop;
	return new_station;
}

void PrintAddstation(Station new_station)
{
	cout << endl << "Info about your CS..." << endl;
	cout << "Name: " << new_station.station_name << "\tWorkshops: " << new_station.station_workshop
		<< "\tActive workshops: " << endl;
}

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
		/*while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Try again";
			cin >> num;
		}
		*/
		switch (num);
		{
		case 1:
			pipe0 = Addpipe();
			PrintAddpipe(pipe0);
			break;
		}
		default:
			cout << endl << "There is no such command, please, try again" << endl;
	}
	return 0;
}
/*int main(int x)
{
	setlocale(LC_ALL, "Russian");
	cout << "Меню:\n";
	cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
	cout << "Введите команду: ";
	cin >> x;

	if (x == 1)
		cout << "1 команда добавляет трубу";
	if (x == 2)
		cout << "2 команда добавляет КС";
	if (x == 3)
		cout << "3 команда просматривает все объекты";
	if (x == 4)
		cout << "4 команда редактирует трубу";
	if (x == 5)
		cout << "5 команда редактирует КС";
	if (x == 6)
		cout << "6 команда сохраняет изменения";
	if (x == 7)
		cout << "7 команда загружает";
	if (x == 0)
		cout << "0 команда - выход";
	return 0;
}
*/


/*int menu(int x)
{
	cout << "Введите команду: ";
	cin >> x;
	if (x == 1)
		cout<<"1. Команда добавляет трубу"
	cout << x;
	return 0;
}*/


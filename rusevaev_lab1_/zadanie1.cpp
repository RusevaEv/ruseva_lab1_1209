#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pipe
{
	string pipe_name = "None";
	int pipe_length = 0;
	int pipe_diametr = 0;
	bool pipe_repair = false;
};

struct Station
{
	string station_name = "None";
	int station_workshop = 0;
	int station_work_workshop = 0;
	double station_efficiency = 0.0;
};

int check_int(int& int_data)
{
	cin >> int_data;
	while (cin.fail() || cin.peek() != '\n' || int_data <= 0)
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "\nEnter integrate data > 0!!\n";
		cin >> int_data;
	}
	return int_data;
}

double check_double(double& double_data)
{
	cin >> double_data;
	while (cin.fail() || cin.peek() != '\n' || double_data <= 0)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nEnter a double data > 0!!";
		cin >> double_data;
	}
	return double_data;
}

bool check_bool(bool& bool_data)
{
	cin >> bool_data;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nEnter a boolean data type\n";
		cin >> bool_data;
	}
	return bool_data;
}

int check_number_command(int& int_data)
{
	cin >> int_data;
	while (cin.fail() || cin.peek() != '\n' || int_data < 0 || int_data > 9)
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Enter number 0 to 9\n";
		cin >> int_data;
	}
	return int_data;
}

double check2_double(double& efficiency_data)
{
	cin >> efficiency_data;
	while (cin.fail() || cin.peek() != '\n' || (efficiency_data < 0.0) || (efficiency_data > 1.0))
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter an efficiency data from 0.0 to 1.0\n";
		cin >> efficiency_data;
	}
	return efficiency_data;
}

Pipe Addpipe()
{
	Pipe new_pipe;
	cout << "Add a new pipe:" << endl;
	cout << "Enter the name: ";
	cin.ignore();
	getline(cin, new_pipe.pipe_name);
	cout << "Enter the length of pipe (m): ";
	check_int(new_pipe.pipe_length);
	cout << "Enter the diametr of pipe (mm): ";
	check_int(new_pipe.pipe_diametr);
	cout << "Enter the repair status (0 or 1): ";
	check_bool(new_pipe.pipe_repair);
	return new_pipe;
}

void PrintAddpipe(Pipe new_pipe)
{
	cout << endl << "Info about your pipe:" << endl;
	if (new_pipe.pipe_name == "None")
	{
		cout << "No pipes\n";
	}
	else
		cout << "Name: " << new_pipe.pipe_name << "\tLength: " << new_pipe.pipe_length
		<< "\tDiameter: " << new_pipe.pipe_diametr << "\tRepair: " << new_pipe.pipe_repair << endl;
}

void RepairPipe(Pipe& new_pipe)
{
	if (new_pipe.pipe_name == "None")
	{
		cout << "No pipes";
	}
	else
	{
		new_pipe.pipe_repair != new_pipe.pipe_repair;
		cout << "You have changed repair status";
		PrintAddpipe(new_pipe);
	}
}

Station Addstation()
{
	Station new_station;
	cout << "Add a new CS:" << endl;
	cout << "Enter the name: ";
	cin.ignore();
	getline(cin, new_station.station_name);
	cout << "Number of workshops: ";
	check_int(new_station.station_workshop);
	cout << "Number of work workshops: ";
	check_int(new_station.station_work_workshop);
	while (new_station.station_work_workshop > new_station.station_workshop)
	{
		cout << "work workshops can't be greater than all workshops!\n";
		cout << "Number of work workshops: ";
		check_int(new_station.station_work_workshop);
	}
	cout << "Enter the station efficiency index (from 0 to 1): ";
	check2_double(new_station.station_efficiency);
	return new_station;
}

void PrintAddstation(Station new_station)
{
	cout << endl << "Info about your CS:" << endl;
	if (new_station.station_name == "None")
	{
		cout << "No stations\n";
	}
	else
	{
		cout << "Name: " << new_station.station_name << "\tWorkshops: " << new_station.station_workshop
			<< "\tActive workshops: " << new_station.station_work_workshop << "\tEfficiency: "
			<< new_station.station_efficiency << endl;
	}
}

void EditStation(Station& new_station)
{
	if (new_station.station_name == "None")
	{
		cout << "No stations\n";
	}
	else
	{
		cout << "Enter the number of active workshops: ";
		check_int(new_station.station_work_workshop);
		while (new_station.station_work_workshop > new_station.station_workshop)
		{
			cout << "work workshops can't be greater than all workshops!\n";
			cout << "Number of work workshops: ";
			check_int(new_station.station_work_workshop);
		}
	}
	PrintAddstation(new_station);
}

void FileRecord(Pipe pipe_data, Station station_data)
{
	ofstream fout("file");
	if (pipe_data.pipe_name == "None")
	{
		cout << "Nothing to record about pipe\n";
	}
	else
	{
		cout << "Info about the pipe in file.txt\n";
		if (fout)
		{
			fout << "Info about your pipe:\n";
			fout << pipe_data.pipe_name << endl;
			fout << pipe_data.pipe_length << endl;
			fout << pipe_data.pipe_diametr << endl;
			fout << pipe_data.pipe_repair << endl;
		}
	}
	if (station_data.station_name == "None")
	{
		cout << "Nothing to record about station\n";
	}
	else
	{
		cout << "Info about the station in file.txt\n";
		if (fout)
		{
			fout << "Info about your station:\n";
			fout << station_data.station_name << endl;
			fout << station_data.station_workshop << endl;
			fout << station_data.station_work_workshop << endl;
			fout << station_data.station_efficiency << endl;
		}
	}
	fout.close();
}

void FileOutput(Pipe& pipe_data, Station& station_data)
{
	ifstream fin("file");
	if (fin)
	{
		string zero_mean;
		int pipe_flag = 0;
		int station_flag = 0;
		while (getline(fin, zero_mean))
		{
			if (zero_mean == "Info about your pipe: ")
			{
				cout << "\nThe pipe data is get from the file!" << endl;
				cout << "\nInfo about your pipe: " << endl;
				getline(fin, pipe_data.pipe_name);
				cout << "Name of the pipe: " << pipe_data.pipe_name << endl;
				fin >> pipe_data.pipe_length;
				cout << "Length of the pipe: " << pipe_data.pipe_length << endl;
				fin >> pipe_data.pipe_diametr;
				cout << "Diameter of the pipe: " << pipe_data.pipe_diametr << endl;
				fin >> pipe_data.pipe_repair;
				cout << "Repair status of the pipe: " << pipe_data.pipe_repair << endl;
				pipe_flag += 1;
			}
			if (zero_mean == "Info about your station: ")
			{
				cout << "\nThe station sata is get from the file!" << endl;
				cout << "\nInfo about your station: " << endl;
				getline(fin, station_data.station_name);
				cout << "Name of the station: " << station_data.station_name << endl;
				fin >> station_data.station_workshop;
				cout << "Number of workshops: " << station_data.station_workshop
					<< endl;
				fin >> station_data.station_work_workshop;
				cout << "Numbers of work workshops: " << station_data.station_work_workshop << endl;
				fin >> station_data.station_efficiency;
				cout << "Station efficiency index: " << station_data.station_efficiency << endl;
				station_flag += 1;
			}
		}
		if (pipe_flag == 0)
		{
			cout << "\nNo info about pipe from file" << endl;
		}
		if (station_flag == 0)
		{
			cout << "\nNo info about station from file" << endl;
		}
		fin.close();
	}
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
		check_number_command(num);
		switch (num)
		{
		case 1:
		{
			pipe0 = Addpipe();
			PrintAddpipe(pipe0);
			break;
		}
		case 2:
		{
			station0 = Addstation();
			PrintAddstation(station0);
			break;
		}
		case 3:
		{
			PrintAddpipe(pipe0);
			PrintAddstation(station0);
			break;
		}
		case 4:
		{
			RepairPipe(pipe0);
			break;
		}
		case 5:
		{
			EditStation(station0);
			break;
		}
		case 6:
		{
			FileRecord(pipe0, station0);
			break;
		}
		case 7:
		{
			FileOutput(pipe0, station0);
			break;
		}
		case 0:
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "There is no such command, please, try again" << endl;
		}
		}
	}
	return 0;
}
//пссп
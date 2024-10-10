#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pipe
{
	string pipe_name = "None";
	double pipe_length = 0.0;
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

void check_int(int& int_data)//!
{
	cin >> int_data;
	while (cin.fail() || cin.peek() != '\n' || int_data <= 0)
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "\nEnter integrate data > 0!!\n";
		cin >> int_data;
	}
}

bool check_bool(bool& bool_data)
{
	cin >> bool_data;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nEnter 0 or 1\n";
		cin >> bool_data;
	}
	return bool_data;
}

int check_number_command(int& int_data)
{
	cin >> int_data;
	while (cin.fail() || cin.peek() != '\n' || int_data < 0 || int_data > 7)
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Enter number 0 to 7\n";
		cin >> int_data;
	}
	return int_data;
}

void check_double(double& efficiency_data)//!!
{
	cin >> efficiency_data;
	while (cin.fail() || cin.peek() != '\n' || (efficiency_data < 0.0) || (efficiency_data > 1.0))
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter an efficiency data from 0.0 to 1.0\n";
		cin >> efficiency_data;
	}
}

void check_double_lenght(double& length_data)//!!
{
	cin >> length_data;
	while (cin.fail() || cin.peek() != '\n' || (length_data <= 0.0))
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter a number > 0.0\n";
		cin >> length_data;
	}
}

Pipe Addpipe()
{
	Pipe new_pipe;
	cout << "Add a new pipe:" << endl;
	cout << "Enter the name: ";
	cin.ignore();
	getline(cin, new_pipe.pipe_name);
	cout << "Enter the length of pipe (m): ";
	check_double_lenght(new_pipe.pipe_length);
	cout << "Enter the diametr of pipe (mm): ";
	check_int(new_pipe.pipe_diametr);
	cout << "Enter the repair status (0 or 1): ";
	check_bool(new_pipe.pipe_repair);
	return new_pipe;
}

void OutputAddpipe(const Pipe& new_pipe)
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
		new_pipe.pipe_repair = !new_pipe.pipe_repair;
		cout << "You have changed repair status";
		OutputAddpipe(new_pipe);
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
	check_double(new_station.station_efficiency);
	return new_station;
}

void OutputAddstation(const Station& new_station)//??
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
	OutputAddstation(new_station);
}

void save_pipe(ofstream& fout, const Pipe& pipe_data) {
	if (pipe_data.pipe_name == "None")
	{
		cout << "Nothing to record about pipe\n";
	}
	else
	{
		cout << "Info about the pipe in file.txt\n";
		if (fout)//!!!!!!!!!!!!!!
		{
			fout << "Info about your pipe: \n";
			fout << pipe_data.pipe_name << endl;
			fout << pipe_data.pipe_length << endl;
			fout << pipe_data.pipe_diametr << endl;
			fout << pipe_data.pipe_repair << endl;
		}
	}
}

void save_station(ofstream& fout, const Station& station_data) {
	if (station_data.station_name == "None")
	{
		cout << "Nothing to record about station\n";
	}
	else
	{
		cout << "Info about the station in file.txt\n";
		if (fout)
		{
			fout << "Info about your station: \n";
			fout << station_data.station_name << endl;
			fout << station_data.station_workshop << endl;
			fout << station_data.station_work_workshop << endl;
			fout << station_data.station_efficiency << endl;
		}
	}
}

void FileRecord(const Pipe& pipe_data, const Station& station_data)
{
	ofstream fout("file");
	save_pipe(fout, pipe_data);
	save_station(fout, station_data);
	fout.close();
}

void FileOutputPipe(ifstream& fin, Pipe& pipe_data)
{
	getline(fin, pipe_data.pipe_name);
	fin >> pipe_data.pipe_length;
	fin >> pipe_data.pipe_diametr;
	fin >> pipe_data.pipe_repair;
}


void FileOutputStation(ifstream& fin, Station& station_data)
{
	getline(fin, station_data.station_name);
	fin >> station_data.station_workshop;
	fin >> station_data.station_work_workshop;
	fin >> station_data.station_efficiency;
}


void FileOutput(Pipe& pipe_data, Station& station_data)
{
	pipe_data = {};
	station_data = {};
	ifstream fin("file");
	string line;
	int flag = 0;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (line == "Info about your pipe: ")
			{
				FileOutputPipe(fin, pipe_data);
				cout << "\nThe pipe data is get from the file" << endl;
				flag = 1;
			}
			else if (line == "Info about your station: ")
			{
				FileOutputStation(fin, station_data);
				cout << "\nThe station data is get from the file" << endl;
				flag = 1;
			}
		if (flag == 0) cout << "\nNo info about station from file" << endl;
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
		cout << endl << "Enter the command: ";
		check_number_command(num);
		switch (num)
		{
		case 1:
		{
			pipe0 = Addpipe();
			OutputAddpipe(pipe0);
			break;
		}
		case 2:
		{
			station0 = Addstation();
			OutputAddstation(station0);
			break;
		}
		case 3:
		{
			OutputAddpipe(pipe0);
			OutputAddstation(station0);
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
		}
	}
	return 0;
}
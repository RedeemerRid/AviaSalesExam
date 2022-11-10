#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

template <class T>
void getValue(string prompt, T& value)
{
	cout << prompt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... try again" << endl;
		cout << prompt;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);
}
template <>
inline void getValue<string>(string prompt, string& value)
{
	cout << prompt;
	getline(cin, value);
}
template <>
inline void getValue<char>(string prompt, char& value)
{
	cout << prompt;
	cin.getline(&value, 30);
}


struct flight {
	string numFlight;
	string pointSrc;
	string pointDst;
	string dateFlight;
	string timeUp;
	string timeDown;
	string typeAirplane;
	double costTicket;
	int countSeats;
};
class Flight {
	
	map<string, flight> allFlight;

public:
	Flight() {}
	~Flight() {
		OutToFile();
	}

	void inputSystem() {
		cout << "Welcome my dear operator, choose yourself from the list : " << endl;
	}

	void addFlight() {
		auto it = allFlight.begin();
		flight f;
		bool flag = false;
		do {
			flag = false;
			getValue("enter number of Flight : ", f.numFlight);
			if (allFlight.count(f.numFlight)) {
				flag = true;
			}
		} while (flag);
		getValue("enter Point of Source : ", f.pointSrc);
		getValue("enter Point of Distination : ", f.pointDst);
		getValue("enter Date of Flightn : ", f.dateFlight);
		getValue("enter Time of Up : ", f.timeUp);
		getValue("enter Time of Down : ", f.timeDown);
		getValue("enter Type of Airplane : ", f.typeAirplane);
		getValue("enter Cost of Ticket : ", f.costTicket);
		getValue("enter Count of Seats : ", f.countSeats);
		
		allFlight[f.numFlight] = f;
	}

	void print() {
		for (auto it = allFlight.begin(); it != allFlight.end(); ++it) {
			cout << it->first << "\t" << (it->second).numFlight << endl << "\t" << (it->second).pointSrc
				<< endl << "\t" << (it->second).pointDst << endl << "\t" << (it->second).timeUp
				<< endl << "\t" << (it->second).timeDown << endl << "\t" << (it->second).typeAirplane
				<< endl << "\t" << (it->second).costTicket << endl << "\t" << (it->second).countSeats << endl;
		}
	}

	void OutToFile() {
		ofstream ft("2.txt");

		for (auto it = allFlight.begin(); it != allFlight.end(); ++it) {
			ft << it->first << endl;
			ft << (it->second).numFlight << endl;
			ft << (it->second).pointSrc << endl;
			ft << (it->second).pointDst << endl;
			ft << (it->second).timeUp << endl;
			ft << (it->second).timeDown << endl;
			ft << (it->second).typeAirplane << endl;
			ft << (it->second).costTicket << endl;
			ft << (it->second).countSeats << endl;
		}
		ft.close();
	}

	void InToFlight() {
		flight* f;
		ifstream ft("1.txt");
		
		
		while (!ft.eof()) {
			f = new flight;
			flight* ff;
			string x;
			ft >> x;
			ft >> f->numFlight;
			ft >> f->pointSrc;
			ft >> f->pointDst;
			ft >> f->dateFlight;
			ft >> f->timeUp;
			ft >> f->timeDown;
			ft >> f->typeAirplane;
			ft >> f->costTicket;
			ft >> f->countSeats;
			ff = f;
			allFlight[ff->numFlight] = *ff;
		}
		ft.close();
	}

};

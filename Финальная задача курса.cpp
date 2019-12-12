#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

class Date {
public:
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void CheingDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int day;
	int month;
	int year;
};

Date ParseDate(const string& s) {
	stringstream stream(s);
	int year = -1488;
	int	month = -1488;
	int	day = -1488;
	char def1, def2;
	stream >> year >> def1 >> month >> def2 >> day;
	if (def1 != '-' || def2 != '-' || !stream.eof() || year == -1488 || month == -1488 || day == -1488) {
		string err = "Wrong date format: " + s;
		throw runtime_error(err);
	}
	if (month > 12 || month < 1) {
		string err = "Month value is invalid: " + to_string(month);
		throw runtime_error(err);
	}
	if (day > 31 || day < 1) {
		string err = "Day value is invalid: " + to_string(day);
		throw runtime_error(err);
	}
	Date date(day, month, year);
	return date;
}

bool operator<(const Date& lhs, const Date& rhs) {
	int slhs = lhs.GetYear() * 10000 + lhs.GetMonth() * 100 + lhs.GetDay();
	int srhs = rhs.GetYear() * 10000 + rhs.GetMonth() * 100 + rhs.GetDay();
	if (slhs < srhs) {
		return true;
	}
	return false;
}

void PrintDate(const Date& d) {
	cout << setfill('0');
	cout << setw(4) << d.GetYear() << '-'
		<< setw(2) << d.GetMonth() << '-'
		<< setw(2) << d.GetDay() << " ";
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		that_base[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (that_base[date].count(event) > 0) {
			that_base.at(date).erase(event);
			return true;
		}
		return false;
	}

	int  DeleteDate(const Date& date) {
		int n = that_base[date].size();
		that_base[date].clear();
		return n;
	}

	void Find(const Date& date) const {
		if (that_base.count(date) != 0) {
			for (auto const& ev : that_base.at(date)) {
				cout << ev << endl;
			}
		}
	}

	void Print() const {
		for (auto const& evs : that_base) {
			if (evs.second.size() > 0) {
				for (auto const& ev : that_base.at(evs.first)) {
					PrintDate(evs.first);
					cout << ev << endl;
				}
			}
		}
	}

private:
	map<Date, set<string>> that_base;
};

int main() {
	Database db;

	string command;

	while (getline(cin, command)) {
		stringstream stream(command);
		string keyword;
		stream >> keyword;
		try {
			if (keyword == "Add") {
				string datein;
				string new_event;
				stream >> datein >> new_event;
				Date oh_my = ParseDate(datein);
				db.AddEvent(oh_my, new_event);
			}
			else if (keyword == "Del") {
				string datein;
				string devent = "";
				stream >> datein >> devent;
				Date deldate = ParseDate(datein);
				if (devent.empty()) {
					cout << "Deleted " << db.DeleteDate(deldate) << " events" << endl;
				}
				else {
					if (db.DeleteEvent(deldate, devent)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
			}
			else if (keyword == "Find") {
				string datein;
				stream >> datein;
				Date fdate = ParseDate(datein);
				db.Find(fdate);
			}
			else if (keyword == "Print") {
				db.Print();
			}
			else if (!keyword.empty()) {
				cout << "Unknown command: " << keyword << endl;
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		command.clear();
	}

	return 0;
}
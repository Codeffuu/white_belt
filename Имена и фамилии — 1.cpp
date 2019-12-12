#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
	string name;  

	for (const auto& item : names) {
		if (item.first <= year) {
			name = item.second;
		}
		else {
			break;
		}
	}

	return name;
}

string FindOtherNamesByYear(const map<int, string>& names, int year) {
	vector<string> name;
	string old_names = "(;

	for (const auto& item : names) {
		if (item.first <= year) {
			name.push_back(item);
		}
		else {
			break;
		}
	}
	name.erase[0];
	if (name.size() != 0) {
		for (const auto& s : name) {
			old_names += s + ", ";
		}
		old_names -= ", ";
		old_names += ")";
	}
	return old_names;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";
		}
		else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) {
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		const vector<string> first_name_old = FindOtherNamesByYear(first_names, year);
		const vector<string> last_name_old = FindOtherNamesByYear(last_names, year);
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			return last_name + last_name_old + " with unknown first name";
		}
		else if (last_name.empty()) {
			return first_name + first_name_old + " with unknown last name";
		}
		else {
			return first_name + first_name_old + last_name + last_name_old;
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
};

int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	return 0;
}
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
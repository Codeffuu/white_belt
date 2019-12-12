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

	for (const auto& item : names) {
		if (item.first <= year && name.empty()) {
			name.insert(name.begin(), item.second);
		}
		else if (item.first <= year && item.second != name[0]){
			name.insert(name.begin(), item.second);
		}
		else {
			break;
		}
	}
	string old_names = name.back();

	if (name.size() > 1) {
		old_names += " (";
		for (int i = 1; i < name.size(); ++i) {
			if (name.size() == (i + 1)) {
				old_names += name[i];
			}
			else{
				old_names += name[i] + ", ";
			}
		}
		old_names += ")";
	}
	else if (name.size() == 0) {
		old_names.erase();
	}
	return old_names;
}

class Person {
public:
	Person(const string& born_first_name, const string& born_last_name, const int born_year) {
		first_names[born_year] = born_first_name;
		last_names[born_year] = born_last_name;
		start = born_year;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year>=start){
			first_names[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= start) {
			last_names[year] = last_name;
		}
	}
	string GetFullName(int year) {
		if (year >= start) {
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
		else
			return "No person";
	}
	string GetFullNameWithHistory(int year) {
		if (year >= start) {
			const string first_name_old = FindOtherNamesByYear(first_names, year);
			const string last_name_old = FindOtherNamesByYear(last_names, year);
			if (first_name_old.empty() && last_name_old.empty()) {
				return "Incognito";
			}
			else if (first_name_old.empty()) {
				return last_name_old + " with unknown first name";
			}
			else if (last_name_old.empty()) {
				return first_name_old + " with unknown last name";
			}
			else {
				return first_name_old + " " + last_name_old;
			}
		}
		else
			return "No person";
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
	int start;
};
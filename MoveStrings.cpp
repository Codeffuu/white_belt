#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& s, vector<string>& d) {
	for (auto progon : s) {
		d.push_back(progon);
	}
	s.clear();
}
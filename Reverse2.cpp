#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> a;
	for (auto c : v) {
		a.insert(a.begin(), c);
	}
	return a;
}
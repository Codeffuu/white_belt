#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse(vector<int>& v) {
	vector<int> a;
		for (auto c : v) {
			a.insert(a.begin(), c);
		}
		v = a;
}
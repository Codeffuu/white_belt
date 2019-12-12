#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k; 
		a.push_back(k);
	}
	sort(begin(a), end(a),[] (const int& x, const int& y) {
		return (abs(x) < abs(y));
	});
	for (const auto& item : a) {
		cout << item << " ";
	}
	return 0;
}


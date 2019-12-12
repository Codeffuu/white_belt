#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	int q;
	map<vector<string>, int> buses;
	vector<string> route;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		for (int ii = 0; ii < n; ++ii) {
			string stops_name;
			cin >> stops_name;
			route.push_back(stops_name);
		}
		if (buses.count(route) == 0) {
			int that_bus = buses.size() + 1;
			buses[route] = that_bus;
			cout << "New bus " << that_bus << endl;
			route.clear();
		}
		else if (buses.count(route) == 1) {
			cout << "Already exists for " << buses[route] << endl;
			route.clear();
		}
	}
	return 0;
}
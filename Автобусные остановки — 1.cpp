#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	int q;
	map<vector<string>, int> buses;
	cin >> q;
	for (int i = 0; i < q; ++ii) {
		cin >> n;
		int that_bus = 1;
		for (int ii = 0; ii < n; ++ii) {
			string stops_name;
			vector<string> route;
			cin >> stops_name;
			route.push_back(stops_name);
		}
		if (buses.count(route) == 0) {
			buses[route] = that_bus;
			cout << "New bus " << that_bus;
			++that_bus;
		}
		else if (buses[route].size == 1) {
			cout << "Already exists for " << that_bus;
		}
	}
	return 0;
}
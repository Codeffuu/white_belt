#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;

int main() {

	int Q;
	map<set<string>, int> buses;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		set<string> route;
		int count_stops;
		cin >> count_stops;
		for (int ii = 0; ii < count_stops; ++ii) {
			string stops_name;
			cin >> stops_name;
			route.insert(stops_name);
		}
		if (buses.count(route) == 0) {
			int that_bus = buses.size() + 1;
			buses[route] = that_bus;
			cout << "New bus " << that_bus << endl;
		}
		else if (buses.count(route) == 1) {
			cout << "Already exists for " << buses[route] << endl;
		}
	}
	return 0;
}


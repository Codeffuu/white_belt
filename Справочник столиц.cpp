#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string keyword;
		map<string, vector<string>> buses;
		cin >> keyword;
		if (keyword == "NEW_BUS") {
			string bus, stop_name;
			int stop_count;
			cin >> bus >> stop_count;
			buses.first = bus;
			for (int ii = 0; ii < stop_count; ++ii) {
				cin >> stop_name;
				this_bus.push_back(stop_name);
			}
			buses.second = this.bus;
		}
	}

}

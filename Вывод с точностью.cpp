#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	int n, m;
	if (input) {
		input >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < m; ++ii) {
				int s;
				getline(input, s, ',');
				cout << setw(10) << s;
			}
		}
	}
	return 0;
}
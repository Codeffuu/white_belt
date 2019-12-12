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
				if (ii == m - 1) {
					int s;
					input >> s;
					cout << setw(10) << s;
				}
				else {
					int s;
					input >> s;
					input.ignore(1);
					cout << setw(10) << s << " ";
				}
				
			}
			cout << endl;
		}
	}
	return 0;
}
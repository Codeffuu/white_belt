#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	double line;
	ofstream output("output.txt");
	if (input) {
		cout << fixed << setprecision(3);
		while (getline(input, line)) {
			output << line << endl;
		}
	}
	return 0;
}
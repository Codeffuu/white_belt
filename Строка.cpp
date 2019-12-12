#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& ins) {
		new_string = ins;
	}
	void Reverse() {
		reverse(begin(new_string), end(new_string));
	}
	string ToString() const {
		return new_string;
	}
private:
	string new_string;
};

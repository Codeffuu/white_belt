#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		we_have_strings.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(we_have_strings), end(we_have_strings));
		return we_have_strings;
	}
private:
	vector<string> we_have_strings;
};

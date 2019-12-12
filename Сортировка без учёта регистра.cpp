#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int n;
	vector<string> all_strings;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		all_strings.push_back(s);
	}
	sort(begin(all_strings), end(all_strings), [](string x, string y) {
		vector<char> x_v2, y_v2;
		for (auto fst_st : x) {
			char v2 = tolower(fst_st);
			x_v2.push_back(v2);
		}
		for (auto scnd_st : y) {
			char v2 = tolower(scnd_st);
			y_v2.push_back(v2);
		}
		return x_v2 < y_v2;
	});
	for (const auto& g : all_strings) {
		cout << g << " ";
	}
	return 0;
}


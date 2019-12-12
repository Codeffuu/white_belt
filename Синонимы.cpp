#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;

int main() {

	int Q;
	map<string, set<string>> synonym_dictionary;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string keyword;
		cin >> keyword;
		if (keyword == "ADD") {
			string word_1, word_2;
			cin >> word_1 >> word_2;
			synonym_dictionary[word_1].insert(word_2);
			synonym_dictionary[word_2].insert(word_1);
		}
		else if (keyword == "COUNT") {
			string word;
			cin >> word;
			cout << synonym_dictionary[word].size() << endl;
		}
		else if (keyword == "CHECK") {
			string word_1, word_2;
			cin >> word_1 >> word_2;
			if (synonym_dictionary[word_1].count(word_2) > 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}


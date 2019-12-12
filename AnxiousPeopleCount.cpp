#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string function_word;
	int quantity_operations, argument;
	int anxious_people_count = 0;

	cin >> quantity_operations;

	vector<int> queue;

	for (int i = 0; i < quantity_operations; ++i) {
		cin >> function_word;
		if (function_word == "WORRY_COUNT") {
			for (auto anxious_people : queue) {
				if (anxious_people == 1) {
					++anxious_people_count;
				}
			}
			cout << anxious_people_count << endl;
			anxious_people_count = 0;
		}
		else if (function_word == "WORRY") {
			cin >> argument;
			queue[argument] = 1;
		}
		else if (function_word == "QUIET") {
			cin >> argument;
			queue[argument] = 0;
		}
		else if (function_word == "COME") {
			cin >> argument;
			int new_size = queue.size() + argument;
			queue.resize(new_size);
		}
	}
	return 0;
}
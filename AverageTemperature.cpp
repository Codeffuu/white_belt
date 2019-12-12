#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string function_word;
	int quantity_operations, argument;

	cin >> quantity_operations;

	vector<int> queue;

	for (int i = 0; i < quantity_operations; ++i) {
		cin >> function_word;
		if (function_word == WORRY_COUNT) {
			cout << anxious_people;
		}
		else if (function_word == WORRY) {
			cin >> argument;
			queue[argument] = true;
		}
		else if (function_word == QUIET) {
			cin >> argument;
			queue[argument] = false;
		}
		else if (function_word == COME) {
			cin >> argument;
			queue.reserve(queue.size + argument);
		}
	}
}
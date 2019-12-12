#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string keyword, deal;
	vector<vector<string>> that_month(31);
	int day, q;
	int month_nomber = 1;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> keyword;
		if (keyword == "ADD") {
			cin >> day >> deal;
			that_month[day - 1].push_back(deal);
		}
		if (keyword == "NEXT") {
			vector<string> lost_days;
			if (month_nomber == 1) {
				for (int g = 28; g <= 30; ++g) {
					that_month[27].insert(end(that_month[27]), begin(that_month[g]), end(that_month[g]));
				}
				that_month.resize(28);
			}
			else if ((month_nomber % 2 == 0 && month_nomber < 8) || (month_nomber % 2 == 1 && month_nomber > 8) || month_nomber == 12) {
				that_month.resize(31);
			}
			else if ((month_nomber % 2 == 1 && month_nomber < 7) || (month_nomber % 2 == 0 && month_nomber > 7)) {
				that_month[29].insert(end(that_month[29]), begin(that_month[30]), end(that_month[30]));
				that_month.resize(30);
			}
			++month_nomber;
			if (month_nomber > 12) {
				month_nomber = month_nomber - 12;
			}
		}
		if (keyword == "DUMP") {
			cin >> day;
			cout << that_month[day - 1].size() << " ";
			for (auto outro : that_month[day - 1]) {
				cout << outro << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
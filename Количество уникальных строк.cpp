#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;

set<string> BuildMapValuesSet(map<int, string>& s){
	set<string> back;
	for (const auto& x : s) {
		back.insert(x.second);
	}
	return back;
}

	
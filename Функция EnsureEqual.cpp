#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>


using namespace std;

void EnsureEqual(const string& s, const string& t) {
	if (s != t) {
		throw runtime_error(s + " != " + t);
	}
}
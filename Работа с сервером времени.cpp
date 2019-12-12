#include <iostream>
#include <exception>
#include <string>
using namespace std;

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		}
		catch (system_error& s_e) {
		}
		return LastFetchedTime;
	}

private:
	string LastFetchedTime = "00:00:00";
};
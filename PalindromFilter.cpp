#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> answer;
	vector<char> s, z, k;


	for (auto word : words) {
		for (auto c : word) {
			s.push_back(c);
			z.insert(z.begin(), c);
		}
		if (s == z) {
			if (word.size() >= minLength) {
				answer.push_back(word);
			}
		}
		s = k;
		z = k;
	}
	return answer;
}
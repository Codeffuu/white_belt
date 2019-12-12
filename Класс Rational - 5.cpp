#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		chisl = 0;
		znam = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			chisl = 0;
			znam = 1;
		}
		else {
			if (denominator < 0) {
				numerator = -numerator;
				denominator = -denominator;
			}
			int obch = Obch(abs(numerator), abs(denominator));
			chisl = numerator / obch;
			znam = denominator / obch;
		}
	}

	int Numerator() const {
		return chisl;
	}

	int Denominator() const {
		return znam;
	}

	int chisl;
	int znam;

private:

	int Obch(int a, int b) const {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int new_znam = lhs.znam * rhs.znam;
	int new_chisl = lhs.chisl * rhs.znam + rhs.chisl * lhs.znam;
	return Rational(new_chisl, new_znam);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int new_znam = lhs.znam * rhs.znam;
	int new_chisl = lhs.chisl * rhs.znam - rhs.chisl * lhs.znam;
	return Rational(new_chisl, new_znam);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	if (lhs.chisl == rhs.chisl && lhs.znam == rhs.znam) {
		return true;
	}
	return false;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.chisl * rhs.chisl, lhs.znam * rhs.znam);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.chisl * rhs.znam, rhs.chisl * lhs.znam);
}

istream& operator>>(istream& stream, Rational& rational) {
	if (stream.tellg() == -1) {
		return stream;
	}
	int o, t;
	stream >> o;
	stream.ignore(1);
	stream >> t;
	rational = Rational real(o, t);
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.chisl << '/' << rational.znam;
	return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}

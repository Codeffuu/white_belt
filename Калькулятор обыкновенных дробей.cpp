#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

class Rational {
public:
	Rational() {
		chisl = 0;
		znam = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
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
	if (rhs.chisl == 0) {
		throw domain_error("Division by zero");
	}
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
	Rational real(o, t);
	rational.chisl = real.chisl;
	rational.znam = real.znam;
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
	int n1, n2, d1, d2;
	char operation, check1, check2;
	try {
		cin >> n1 >> check1 >> d1 >> operation >> n2 >> check2 >> d2;
		if (check1 == '/' && check2 == '/') {
			Rational r1(n1, d1);
			Rational r2(n2, d2);
			Rational r;
			if (operation == '+')
				r = r1 + r2;
			else if (operation == '-') {
				r = r1 - r2;
			}
			else if (operation == '*') {
				r = r1 * r2;
			}
			else if (operation == '/') {
				r = r1 / r2;
			}
			cout << r.chisl << '/' << r.znam << endl;
		}
		else {
			cout << "Invalid argument";
		}
	}
	catch (domain_error& do_er) {
		cout << do_er.what();
	}
	catch (invalid_argument& inv_arg) {
		cout << inv_arg.what();
	}
	return 0;
}
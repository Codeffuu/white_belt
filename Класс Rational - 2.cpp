#include <iostream>
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
			if (denominator < 0 && numerator < 0 || numerator > 0 && denominator < 0) {
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
	else {
		return false;
	}
}

	int main() {
		{
			Rational r1(4, 6);
			Rational r2(2, 3);
			bool equal = r1 == r2;
			if (!equal) {
				cout << "4/6 != 2/3" << endl;
				return 1;
			}
		}

		{
			Rational a(2, 3);
			Rational b(4, 3);
			Rational c = a + b;
			bool equal = c == Rational(2, 1);
			if (!equal) {
				cout << "2/3 + 4/3 != 2" << endl;
				return 2;
			}
		}

		{
			Rational a(5, 7);
			Rational b(2, 9);
			Rational c = a - b;
			bool equal = c == Rational(31, 63);
			if (!equal) {
				cout << "5/7 - 2/9 != 31/63" << endl;
				return 3;
			}
		}

		cout << "OK" << endl;
		return 0;
	}

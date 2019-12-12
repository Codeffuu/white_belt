#include <iostream>
#include <sstream>

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
	Rational real(o, t);
	rational.chisl = real.chisl;
	rational.znam = real.znam;
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.chisl << '/' << rational.znam;
	return stream;
}

int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}

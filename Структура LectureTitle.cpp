#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Specialization
{
	string specin;
	explicit Specialization(string specfrom) {
		specin = specfrom;
	}
};

struct Course
{
	string courin;
	explicit Course(string courfrom) {
		courin = courfrom;
	}
};

struct Week
{
	string wein;
	explicit Week(string wefrom) {
		wein = wefrom;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_spec, Course new_cour, Week new_we) {
		specialization = new_spec.specin;
		course = new_cour.courin;
		week = new_we.wein;
	}
};

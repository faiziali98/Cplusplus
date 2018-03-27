#include<iostream>
using namespace std;

class Date {

	public:
		int month;
		int day;
		int year;
		Date();
		Date(int m, int d, int y);
		Date& operator +(const Date &myDate1);
		Date& operator -(const Date &myDate1);
		bool operator ==(const Date &myDate1);
		bool operator <(const Date &myDate1);
		friend ostream& operator <<(ostream &outs, const Date &myDate);
};


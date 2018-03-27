#include "Date.h"

Date::Date(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}

Date::Date() {
	month = 0;
	day = 0;
	year = 0;
}

Date& Date::operator +(const Date &myDate1) {
	Date newDate;
	newDate.day = myDate1.day + day;
	for(;;){
        if (newDate.day > 30) {
            newDate.day = newDate.day - 30;
            newDate.month = newDate.month + 1;
        }
        else
            break;
        }
	newDate.year = myDate1.year + year;
	newDate.month = myDate1.month + month;
	for(;;){
        if (newDate.month> 12) {
            newDate.month = newDate.month - 12;
            newDate.year = newDate.year + 1;
        }
        else
            break;
        }

	return newDate;
}

Date& Date::operator -(const Date &myDate1) {
	Date newDate;

	newDate.day = myDate1.day - day;
	if (newDate.day < 1) {
		newDate.day = 30 - newDate.day;
		newDate.month = newDate.month  - 1;
	}
	newDate.year = myDate1.year - year;
	newDate.month = myDate1.month - month;
	if (newDate.month < 1) {
		newDate.month = 12 - newDate.month;
		newDate.year = newDate.year - 1;
	}
    if (newDate.year<0)
        std::cout<<"Invalid date calculated during subtraction"<<std::endl;
	return newDate;
}

bool Date::operator ==(const Date &myDate1) {
	if (myDate1.day == day && myDate1.month == month && myDate1.year == year) {
		return true;
	} else {
		return false;
	}
}

bool Date:: operator <(const Date &myDate1) {
	if (myDate1.year < year) {
		return true;
	} else if (myDate1.year == year) {
		if (myDate1.month < month) {
			return true;
		} else if (myDate1.month == month) {
			if (myDate1.day < day) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

ostream& operator <<(ostream &outs, const Date &myDate) {
	cout << myDate.day<< "/" << myDate.month << "/" << myDate.year << endl;
	return cout;
}


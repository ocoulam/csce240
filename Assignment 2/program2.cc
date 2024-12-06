// Copyright 2024 Owen Coulam

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"program2functions.h"

int DateDifference(int month1, int day1,
    int year1, int month2, int day2, int year2) {
    // Let "true" be forward from date1,
    // and "false" be backwards from date1
    // where "date(n)" is the combination of month(n)/day(n)/year(n)

    // Assumes date1 is "before" date2 initally
    bool direction = true;

    if ( year1 > year2 ) {
        direction = false;
    } else if ( (year1 == year2) && (month1 > month2) ) {
        direction = false;
    } else if ( (year1 == year2) && (month1 == month2) && (day1 > day2) ) {
        direction = false;
    }

    int days = 0;

    // Based on boolean value of direction,
    // only one while loop will be used

    // Moves forward in time until date2 is reached
    while ( direction && (month1 != month2
        || year1 != year2 || day1 != day2) ) {
        NextDate(month1, day1, year1);
        days++;
    }

    // Moves backward in time until date2 is reached
    while ( !direction && (month1 != month2
        || year1 != year2 || day1 != day2) ) {
        PreviousDate(month1, day1, year1);
        days--;
    }

    return days;
}

int main() {
    // Declares variables and takes input
    int month1, day1, year1, month2, day2, year2;
    char slash;
    bool correctDates = true;

    cin >> month1 >> slash >> day1 >> slash
        >> year1 >> month2 >> slash >> day2
        >> slash >> year2;

    if ( !ValidDate(month1, day1, year1) ) {
        cout << month1 << "/" << day1 << "/"
            << year1 << " is not a valid date" << endl;
        correctDates = false;
    }
    if ( !ValidDate(month2, day2, year2) ) {
        cout << month2 << "/" << day2 << "/"
            << year2 << " is not a valid date" << endl;
        correctDates = false;
    }
    // Exits program if either dates are invalid
    if ( !correctDates ) {
        return 0;
    }
    int DayDiff = DateDifference(month1, day1, year1, month2, day2, year2);
    if ( DayDiff >= 0 ) {
        cout << month1 << slash << day1 << slash << year1 << " is "
            << DayDiff << " days before " << month2
            << slash << day2 << slash << year2 << endl;
        return 0;
    } else {
        DayDiff = -DayDiff;
        cout << month1 << slash << day1 << slash << year1 << " is "
            << DayDiff << " days after " << month2
            << slash << day2 << slash << year2 << endl;
        return 0;
    }
}

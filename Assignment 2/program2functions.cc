// Copyright 2024 Owen Coulam

#include"program2functions.h"

bool LeapYear(int year) {
    if ( year % 400 == 0 ) {
        return true;
    } else if ( year % 100 == 0 ) {
        return false;
    } else if ( year % 4 == 0 ) {
        return true;
    } else {
        return false;
    }
}

int LastDayOfMonth(int month) {
    if ( month < 1 || month > 12 || month == 2 ) {
        return 0;
    } else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        return 30;
    } else {
        return 31;
    }
}

int LastDayOfMonth(int month, int year) {
    if ( month == 2  && year > 0 ) {
        if ( LeapYear(year) ) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 0;
    }
}

bool ValidDate(int month, int day, int year) {
    // Accounts for the two declarations of "LastDayOfMonth"
    int LastDay;
    if ( month == 2 ) {
        LastDay = LastDayOfMonth(2, year);
    } else {
        LastDay = LastDayOfMonth(month);
    }

    if ( LastDay == 0 || day > LastDay || day < 1 || year < 1 ) {
        return false;
    }
    return true;
}

void NextDate(int& month, int& day, int& year) {
    int LastDay;
    if ( month == 2 ) {
        LastDay = LastDayOfMonth(2, year);
    } else {
        LastDay = LastDayOfMonth(month);
    }

    if ( !ValidDate(month, day, year) ) {
        return;
    } else if ( month == 12 && day == 31 ) {
        month = 1;
        day = 1;
        year++;
    } else if ( day == LastDay ) {
        day = 1;
        month++;
    } else {
        day++;
    }
}

void PreviousDate(int& month, int& day, int& year) {
    int LastDay;
    if ( month == 3 ) {
        LastDay = LastDayOfMonth(2, year);
    } else {
        LastDay = LastDayOfMonth(month - 1);
    }

    if ( !ValidDate(month, day, year) ) {
        return;
    } else if ( month == 1 && day == 1 ) {
        month = 12;
        day = 31;
        year--;
    } else if ( day == 1 ) {
        day = LastDay;
        month--;
    } else {
        day--;
    }
}

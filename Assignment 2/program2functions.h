// Copyright 2024 Owen Coulam

#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

// Determines if the given year is a leap year
bool LeapYear(int year);

// Finds the last day of the month for any month but Febuary
int LastDayOfMonth(int month);

// Finds the last day of the month for Febuary (dependent on the year)
int LastDayOfMonth(int month, int year);

// Returns if month/day/year is a valid date
bool ValidDate(int month, int day, int year);

// Modifies inputs to date after month/day/year
void NextDate(int& month, int& day, int& year);

// Modifies inputs to date before month/day/year
void PreviousDate(int& month, int& day, int& year);

#endif

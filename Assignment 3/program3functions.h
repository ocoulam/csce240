// Copyright 2024 Owen Coulam
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_

// Returns number of elements greater than the mean of the array
int CountAboveAv(const double nums[][10], int rows);

// Sorts a double subscripted array by a column by moving the rows
void SortByCol(double nums[][10], int rows, int targetCol, bool ascending);

// Sorts a double subscripted array by a row by moving the columns
void SortByRow(double nums[][10], int rows, int targetRow, bool ascending);

// Sorts array and returns median in a target column
double MedianInCol(double nums[][10], int rows, int targetCol);

// Sorts array, returns number of modes (at most 2), and updates
// mode value array to contain those modes
int ModeInCol(double nums[][10], int rows, int targetCol, double ans[]);

#endif

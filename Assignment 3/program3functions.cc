// Copyright 2024 Owen Coulam
#include"program3functions.h"

int CountAboveAv(const double nums[][10], int rows) {
    double av = 0.0;
    int count = 0;
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < 10; ++j ) {
            av += nums[i][j];
        }
    }
    av /= 10 * rows;
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < 10; ++j ) {
            if ( nums[i][j] > av ) {
                count++;
            }
        }
    }

    return count;
}

void SwapRows(double nums[][10], int rows, int firstRow, int secondRow) {
    double temp;
    for ( int i = 0; i < 10; ++i ) {
        temp = nums[firstRow][i];
        nums[firstRow][i] = nums[secondRow][i];
        nums[secondRow][i] = temp;
    }
}

void SortByCol(double nums[][10], int rows, int targetCol, bool ascending) {
    for ( int k = rows - 1; k > 0; --k ) {
        for ( int i = 0; i < k; ++i ) {
            if ( ascending && nums[i][targetCol] > nums[i+1][targetCol] ) {
                SwapRows(nums, rows, i, i+1);
            }
            if ( !ascending && nums[i][targetCol] < nums[i+1][targetCol] ) {
                SwapRows(nums, rows, i, i+1);
            }
        }
    }
}

void SwapColumns(double nums[][10], int rows, int firstCol, int secondCol) {
    double temp;
    for ( int i = 0; i < rows; ++i ) {
        temp = nums[i][firstCol];
        nums[i][firstCol] = nums[i][secondCol];
        nums[i][secondCol] = temp;
    }
}

void SortByRow(double nums[][10], int rows, int targetRow, bool ascending) {
    for ( int k = 9; k > 0; --k ) {
        for ( int i = 0; i < k; ++i ) {
            if ( ascending && nums[targetRow][i] > nums[targetRow][i+1] ) {
                SwapColumns(nums, rows, i, i+1);
            }
            if ( !ascending && nums[targetRow][i] < nums[targetRow][i+1] ) {
                SwapColumns(nums, rows, i, i+1);
            }
        }
    }
}

double MedianInCol(double nums[][10], int rows, int targetCol) {
    SortByCol(nums, rows, targetCol, true);
    if ( rows % 2 == 0 ) {
        return (nums[rows / 2][targetCol] +
            nums[(rows / 2) - 1][targetCol]) / 2;
    } else {
        return nums[(rows - 1) / 2][targetCol];
    }
}

int ModeInCol(double nums[][10], int rows, int targetCol, double ans[]) {
    SortByCol(nums, rows, targetCol, true);
    int greatestFreq = 2;  // Must be at least 2 to override ans array
    double blank = ans[0];
    int freq = 1;
    double currNum = blank;

    for ( int i = 1; i < rows; ++i ) {
        if ( nums[i][targetCol] != nums[i-1][targetCol] ) {
            if ( freq == greatestFreq ) {
                if ( ans[0] == blank ) {
                    ans[0] = currNum;
                } else if ( ans[1] == blank ) {
                    ans[1] = currNum;
                } else {
                    ans[0] = ans[1] = blank;
                    return 0;
                }
            } else if ( freq > greatestFreq ) {
                ans[0] = currNum;
                ans[1] = blank;
                greatestFreq = freq;
            }

            freq = 1;
            currNum = nums[i][targetCol];
        }

        if ( nums[i][targetCol] == nums[i-1][targetCol] ) {
            freq++;
            currNum = nums[i][targetCol];
        }
    }

    if ( freq == greatestFreq ) {
        if ( ans[0] == blank ) {
            ans[0] = currNum;
            return 1;
        } else if ( ans[1] == blank ) {
            ans[1] = currNum;
            return 2;
        } else {
            ans[0] = ans[1] = blank;
            return 0;
        }
    } else if ( freq > greatestFreq ) {
        ans[0] = currNum;
        ans[1] = blank;
    }

    if ( ans[0] == blank ) {
        return 0;
    } else if ( ans[1] == blank ) {
        return 1;
    }
    return 2;
}

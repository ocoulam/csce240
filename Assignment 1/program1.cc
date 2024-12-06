// Copyright 2024 Owen Coulam
// CSCE 240 Homework 1

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// Determines if num is prime
bool isPrime(int num) {
    if ( num < 1 ) {
        return false;
    }
    for ( int i = 2; i < num; ++i ) {
        if ( num % i == 0 ) {
            return false;
        }
    }
    return true;
}

// Finds num1 ^ num2
int pow(int num1, int num2) {
    int sum = num1;
    for ( int i = 1; i < num2; ++i ) {
        sum *= num1;
    }
    return sum;
}

// Outputs correct factorization if user is incorrect
void generateFactors(int num) {
    cout << "Incorrect. " << num << " = ";
    int absNum = num;
    if ( num > 0 ) {
        cout << "1 * ";
    } else {
        cout << "-1 * ";
        absNum = -num;
    }

    int temp = absNum;
    for ( int i = 2; i < absNum; ++i ) {
        if ( isPrime(i) && (absNum % i == 0) ) {
            int exp = 0;
            while ( temp % i == 0 ) {
                temp /= i;
                exp++;
            }
            if ( temp == 1 ) {
                cout << i << "^" << exp << endl;
            } else {
                cout << i << "^" << exp << " * ";
            }
        }
    }
}

int main() {
    // Declares vars
    int target, num1, num2, total = 1;
    char op1, op2;
    bool syntaxPass = true;

    // First set of inputs
    cin >> target >> op1 >> num1 >> op2;
    if ( op1 != '=' || (num1 != 1 && num1 != -1) ) {
        cout << "Invalid input format." << endl;
        return 0;
    }
    total *= num1;

    // Remaining set of inputs (all factors)
    while (true) {
        cin >> num1 >> op1 >> num2 >> op2;
        if ( !isPrime(num1) || op1 != '^' || (op2 != '*' && op2 != '?') ) {
            cout << "Invalid input format." << endl;
            return 0;
        }
        total *= pow(num1, num2);
        if ( op1 == '?' || op2 == '?' ) {
            break;
        }
    }

    // Ouputs result to user
    if ( !syntaxPass ) {
        cout << "Invalid input format." << endl;
    } else if ( target != total ) {
        generateFactors(target);
    } else {
        cout << "Correct!" << endl;
    }

    return 0;
}

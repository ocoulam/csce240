// Copyright 2024 Owen Coulam
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"truefalsequestion.h"

namespace csce240_program5 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool a) : Question(q) {
    answer_ = a;
}

// Add a Print function that takes a bool parameter: void Print(bool) const;
// This function should create 1 or 2 lines of output to the standard output
// device, using cout.

// The first line of output should be "Question: " followed by the value of
// the question data member (from base class Question).
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by "true" or "false" depending on the
// value of the private data member.

void TrueFalseQuestion::Print(bool p) const {
    cout << "Question: " << GetQuestion() << endl;
    if (p) {
        if ( answer_ ) {
            cout << "Correct Answer: " << "true" << endl;
        } else {
            cout << "Correct Answer: " << "false" << endl;
        }
    }
}

}  // namespace csce240_program5

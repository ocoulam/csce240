// Copyright 2024 Owen Coulam
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"shortanswerquestion.h"

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) : Question(q) {
    answer_ = a;
}

// Add a Print function that takes a bool parameter: void Print(bool) const;
// This fuction should create 1 or 2 lines of output to the standard output
// device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member (inherited from the Question class).
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by the value of the correct answer
// private data member.

void ShortAnswerQuestion::Print(bool p) const {
    cout << "Question: " << GetQuestion() << endl;
    if (p) {
        cout << "Correct Answer: " << answer_ << endl;
    }
}

}  // namespace csce240_program5

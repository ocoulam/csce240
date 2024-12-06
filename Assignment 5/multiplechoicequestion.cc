// Copyright 2024 Owen Coulam
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"multiplechoicequestion.h"

namespace csce240_program5 {

// If all but the last two arguments are provided, make all of the answer
// choices the empty string "", and all of the correct/incorrect values true.
// If all but the last argument is provided, default all correct/incorrect
// values to true.

MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int c,
                                        string * o, bool * r) : Question(q) {
    choices_ = new string[c];
    is_correct_ = new bool[c];
    num_choices_ = c;
    if ( q != "?" && c != 0 && o == nullptr && r == nullptr ) {
        for ( int i = 0; i < c; i++ ) {
            choices_[i] = "";
            is_correct_[i] = true;
        }
    } else if ( q != "?" && c != 0 && o != nullptr && r == nullptr ) {
        for ( int i = 0; i < c; i++ ) {
            choices_[i] = o[i];
            is_correct_[i] = true;
        }
    } else {
        for ( int i = 0; i < c; i++ ) {
            choices_[i] = o[i];
            is_correct_[i] = r[i];
        }
    }
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& m)
                                                : Question(m.GetQuestion()) {
    num_choices_ = m.num_choices_;
    choices_ = new string[num_choices_];
    is_correct_ = new bool[num_choices_];
    for ( int i = 0; i < num_choices_; i++ ) {
        choices_[i] = m.choices_[i];
        is_correct_[i] = m.is_correct_[i];
    }
}

MultipleChoiceQuestion::~MultipleChoiceQuestion() {
    if ( choices_ != nullptr ) {
        delete [] choices_;
    }
    if ( is_correct_ != nullptr ) {
        delete [] is_correct_;
    }
}

MultipleChoiceQuestion& MultipleChoiceQuestion::operator =
                                    (const MultipleChoiceQuestion& m) {
    SetQuestion(m.GetQuestion());
    num_choices_ = m.num_choices_;
    if ( choices_ != nullptr ) {
        delete [] choices_;
    }
    if ( is_correct_ != nullptr ) {
        delete [] is_correct_;
    }
    choices_ = new string[num_choices_];
    is_correct_ = new bool[num_choices_];
    for ( int i = 0; i < num_choices_; i++ ) {
        choices_[i] = m.choices_[i];
        is_correct_[i] = m.is_correct_[i];
    }
    return *this;
}

// Add a SetAnswerChoices function that sets the number of choices, the values
// of the answer choices, and the answer correct/incorrect values. This function
// will dynamically allocate and deallocate memory for the data members, as
// necessary. The prototype is provided below

void MultipleChoiceQuestion::SetAnswerChoices(int c, string * o, bool * r) {
    delete [] choices_;
    delete [] is_correct_;
    choices_ = new string[c];
    is_correct_ = new bool[c];
    num_choices_ = c;
    for ( int i = 0; i < num_choices_; i++ ) {
        choices_[i] = o[i];
        is_correct_[i] = r[i];
    }
}

// Add a Print function that takes a bool parameter: void Print(bool) const;
// This fuction should send output to the standard output device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member.
// The next line of output should be "Answer Choices:"
// The following lines should print each answer a separate line.
// If the Print function's argument is true, each answer choice should be
// followed by " - correct" or " - incorrect"

void MultipleChoiceQuestion::Print(bool p) const {
    cout << "Question: " << GetQuestion() << endl;
    cout << "Answer Choices:" << endl;
    if ( !p ) {
        for ( int i = 0; i < num_choices_; i++ ) {
            cout << choices_[i] << endl;
        }
    } else {
        for ( int i = 0; i < num_choices_; i++ ) {
            cout << choices_[i] << " - " <<
                (is_correct_[i] ? "correct" : "incorrect") << endl;
        }
    }
}

}  // namespace csce240_program5

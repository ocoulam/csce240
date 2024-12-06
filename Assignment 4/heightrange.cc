// Copyright 2024 Owen Coulam

#include"heightrange.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

HeightRange::HeightRange() {
    short_ = Height(0, "feet");
    tall_ = Height(0, "feet");
}

HeightRange::HeightRange(const Height& h1, const Height& h2) {
    Height temp1 = h1;
    Height temp2 = h2;

    temp1.ConvertUnits("meters");
    temp2.ConvertUnits("meters");

    if ( temp1.GetValue() > temp2.GetValue() ) {
        short_ = h2;
        tall_ = h1;
    } else {
        short_ = h1;
        tall_ = h2;
    }
}

void HeightRange::SetShortest(const Height& s) {
    Height temp1 = s;
    Height temp2 = tall_;

    temp1.ConvertUnits("meters");
    temp2.ConvertUnits("meters");

    if ( temp1.GetValue() <= temp2.GetValue() ) {
        short_ = s;
    }
}

void HeightRange::SetTallest(const Height& t) {
    Height temp1 = t;
    Height temp2 = short_;

    temp1.ConvertUnits("meters");
    temp2.ConvertUnits("meters");

    if ( temp1.GetValue() >= temp2.GetValue() ) {
        tall_ = t;
    }
}

bool HeightRange::InRange(const Height& test, bool end_points) {
    Height temp1 = short_;
    Height temp2 = tall_;
    Height temp3 = test;

    temp1.ConvertUnits("meters");
    temp2.ConvertUnits("meters");
    temp3.ConvertUnits("meters");

    if ( end_points == true ) {
        if ( temp1.GetValue() <= temp3.GetValue()
            && temp2.GetValue() >= temp3.GetValue() ) {
            return true;
        } else {
            return false;
        }
    } else {
        if ( temp1.GetValue() < temp3.GetValue()
            && temp2.GetValue() > temp3.GetValue() ) {
            return true;
        } else {
            return false;
        }
    }
}

Height HeightRange::Width() {
    Height temp1 = short_;
    Height temp2 = tall_;

    temp1.ConvertUnits(temp2.GetUnits());
    return Height(temp2.GetValue() - temp1.GetValue(), temp2.GetUnits());
}

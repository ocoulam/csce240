// Copyright 2024 Owen Coulam

#include"height.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

Height::Height(double value, string units) {
    if ( value > 0 ) {
        value_ = value;
    } else {
        value_ = 0;
    }

    if ( units != "feet" && units != "inches" &&
        units != "centimeters" && units != "meters" ) {
            units_ = "feet";
    } else {
        units_ = units;
    }
}

// Same as Java this.value
bool Height::SetValue(double value) {
    if ( value < 0 ) {
        return false;
    }
    value_ = value;
    return true;
}

bool Height::SetUnits(string units) {
    if ( units != "feet" && units != "inches" &&
        units != "centimeters" && units != "meters" ) {
            return false;
    }
    units_ = units;
    return true;
}

void Height::ConvertUnits(string new_units) {
    if ( new_units == units_ || (new_units != "feet" &&
        new_units != "inches" && new_units != "centimeters" &&
        new_units != "meters") ) {
            return;
    } else if ( units_ == "feet" && new_units == "inches" ) {
        value_ *= 12;
    } else if ( units_ == "feet" && new_units == "centimeters" ) {
        value_ *= 30.48;
    } else if ( units_ == "feet" && new_units == "meters" ) {
        value_ *= 0.3048;
    } else if ( units_ == "inches" && new_units == "feet" ) {
        value_ /= 12;
    } else if ( units_ == "inches" && new_units == "centimeters" ) {
        value_ *= 2.54;
    } else if ( units_ == "inches" && new_units == "meters" ) {
        value_ /= 39.37;
    } else if ( units_ == "centimeters" && new_units == "feet" ) {
        value_ /= 30.48;
    } else if ( units_ == "centimeters" && new_units == "inches" ) {
        value_ /= 2.54;
    } else if ( units_ == "centimeters" && new_units == "meters" ) {
        value_ /= 100;
    } else if ( units_ == "meters" && new_units == "centimeters" ) {
        value_ *= 100;
    } else if ( units_ == "meters" && new_units == "feet" ) {
        value_ *= 3.2808;
    } else {
        value_ *= 39.3701;
    }
    units_ = new_units;
}

ostream& operator << (ostream& whereto, const Height& t) {
  whereto << t.value_ << " " << t.units_;
  return whereto;
}

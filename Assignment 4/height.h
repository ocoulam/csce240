// Copyright 2024 Owen Coulam

#ifndef HEIGHT_H_
#define HEIGHT_H_

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::ostream;

// Class for a height with value and a corresponding unit
class Height {
 public:
  explicit Height(double value = 0, string units = "feet");
  bool SetValue(double value);
  bool SetUnits(string unit);
  double GetValue() const { return value_; }
  string GetUnits() const { return units_; }
  void ConvertUnits(string unit);
  friend ostream& operator << (ostream&, const Height&);
 private:
  double value_;
  string units_;
};

#endif

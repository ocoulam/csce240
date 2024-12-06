// Copyright 2024 Owen Coulam

#ifndef HEIGHTRANGE_H_
#define HEIGHTRANGE_H_

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::ostream;
#include"height.h"

// Class with two heights, tallest and shortest (yields a range)
class HeightRange {
 public:
  HeightRange();
  HeightRange(const Height& h1, const Height& h2);
  Height GetShortest() const { return short_; }
  Height GetTallest() const { return tall_; }
  void SetShortest(const Height& s);
  void SetTallest(const Height& t);
  bool InRange(const Height& test, bool end_points = true);
  Height Width();
 private:
  Height short_;
  Height tall_;
};

#endif

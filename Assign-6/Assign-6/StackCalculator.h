#ifndef CS197C_STACKCALC
#define CS197C_STACKCALC

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class StackCalculator {
    stack<double> calcStack;
 public:
    StackCalculator();
    ~StackCalculator();
};

#endif

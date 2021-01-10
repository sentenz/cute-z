#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using namespace std;

namespace Sentenz
{

    double calculator(string operations);
    vector<string> rpn(string infix);
    bool parse(const string &symbol);
    int priority(const string &c);
    bool isOperator(const string &c);

} /// SENTENZ

#include "Calculator.cpp"

#endif /// CALCULATOR_H

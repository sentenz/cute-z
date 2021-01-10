#include "Calculator.h"

#include <iostream>
#include <math.h>
#include <cctype>
#include <regex>
#include <stack>
#include <exception>
#include <stdexcept>

#include <QString>

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                             RPN Calcolator                              //
/////////////////////////////////////////////////////////////////////////////

    double calculator(string operations)
    {
        try
        {
            vector<string> prefix = rpn(operations);

            stack<double> stack;

            for (auto &it : prefix)
            {
                string s = it;

                if (isOperator(s))
                {
                    double op1, op2;
                    if (!stack.empty())
                    {
                        op2 = stack.top();
                        stack.pop();
                    }
                    else
                    {
                        return numeric_limits<double>::quiet_NaN();
                    }

                    if (!stack.empty())
                    {
                        op1 = stack.top();
                        stack.pop();
                    }
                    else
                    {
                        return numeric_limits<double>::quiet_NaN();
                    }

                    switch(s[0])
                    {
                        case '+': stack.push(op1 + op2);
                            break;
                        case '-': stack.push(op1 - op2);
                            break;
                        case '*': stack.push(op1 * op2);
                            break;
                        case '/': stack.push(op1 / op2);
                            break;
                        case '^': stack.push(pow(op1, op2));
                            break;
                    }
                }
                else
                {
                    /// Couse some reasens atof / stod returning integers
                    //stack.push(atof(s.c_str()));
                    //stack.push(std::stod(s));
                    stack.push(QString::fromStdString(s).toDouble());
                }
            }

            if (!stack.empty())
            {
                return stack.top();
            }
        }
        catch (exception& e)
        {
            cerr << "calculator exception caught: " << e.what() << endl;
            return numeric_limits<double>::infinity();
        }
        catch (...)
        {
            cerr << "calculator warning: issua occurred" << endl;
            return numeric_limits<double>::infinity();
        }

        return 0.0;
    }

    vector<string> rpn(string infix)
    {
        string num_pattern("\\d*\\.?(\\d*\\.?\\d*)?"); //[0-9]?+\\.[0-9]?*
        string op_pattern("[\\^+*/-]");
        regex re(num_pattern + "|" + op_pattern);
        sregex_iterator it(infix.begin(), infix.end(), re);
        sregex_iterator it_end;

        vector<string> outputList;
        stack<string> s;

        for (;it != it_end; ++it)
        {
            if (parse(it->str()))
            {
                outputList.push_back(it->str());
            }

            if (it->str() == "(")
            {
                s.push(it->str());
            }

            if (it->str() == ")")
            {
                while (!s.empty() && s.top() != "(")
                {
                    outputList.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }

            if (isOperator(it->str()))
            {
                while (!s.empty() && priority(s.top()) >= priority(it->str()))
                {
                    outputList.push_back(s.top());
                    s.pop();
                }
                s.push(it->str());
            }
        }

        //pop any remaining operators from the stack and insert to outputlist
        while (!s.empty())
        {
            outputList.push_back(s.top());
            s.pop();
        }

        return outputList;
    }

    bool parse(const string &symbol)
    {
        bool isNumber = false;

        for (unsigned int i = 0; i < symbol.size(); ++i)
        {
            if (!isdigit(symbol[i]))
            {
                isNumber = false;
            }
            else
            {
                isNumber = true;
            }
        }

        return isNumber;
    }

    int priority(const string &c)
    {
        if (c == "^")
        {
            return 3;
        }
        else if (c == "*" || c == "/")
        {
            return 2;
        }
        else if (c== "+" || c == "-")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isOperator(const string &c)
    {
        return ((c == "+") || (c == "-") || (c == "*") || (c == "/") || (c == "^"));
        //return (!c.find_first_not_of("+*/-^") != c.npos);
    }

} /// SENTENZ

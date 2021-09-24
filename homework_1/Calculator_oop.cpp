#include "Calculator_oop.h"

void Calculator::go()
{
    checkExpression();
    Parse();
    
    double result = 0.0;
    switch (expr.Operator)
    {
    case '+':
        result = expr.lsh + expr.rsh;
        break;
    case '-':
        result = expr.lsh - expr.rsh;
        break;
    case '*':
        result = expr.lsh * expr.rsh;
        break;
    case '/':
        result = (double)expr.lsh / expr.rsh;
        break;
    }

    cout << result <<endl;
}

void Calculator::checkExpression()
{
    unsigned operatorCounter = 0;
    for (unsigned i = 0; i < rawExpression.size(); ++i)
    {
        if (rawExpression[i] < '0' || rawExpression[i] > '9')
        {
            switch (rawExpression[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
                if (i != 0)
                    operatorCounter++;
                break;
            default:
                throw invalid_argument("invalid expression");

            }
        }
    }

    if (operatorCounter != 1)
        throw invalid_argument("invalid expression");
}

void Calculator::Parse()
{
    string::iterator iterOperator;
    for (auto it = rawExpression.begin() + 1; it != rawExpression.end(); ++it)
    {
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            iterOperator = it;
            break;
        }
    }

    expr.lsh = stoi(string(rawExpression.begin(), iterOperator));
    expr.rsh = stoi(string(iterOperator + 1, rawExpression.end()));
    expr.Operator = *iterOperator;
}

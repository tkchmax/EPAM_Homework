#include "Calculator_proc.h"

Expression Parse(string s)
{
    Expression expr;

    string::iterator iterOperator;
    for (auto it = s.begin() + 1; it != s.end(); ++it)
    {
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            iterOperator = it;
            break;
        }
    }

    expr.lsh = stoi(string(s.begin(), iterOperator));
    expr.rsh = stoi(string(iterOperator+1, s.end()));
    expr.Operator = *iterOperator;

    return expr;
}

bool isLegalExpression(string s)
{
    unsigned operatorCounter = 0;
    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            switch (s[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
                if(i != 0)
                    operatorCounter++;
                break;
            default:
                return false;

            }
        }
    }

    if (operatorCounter != 1)
        return false;
    return true;
}

void calc()
{
    do
    {
        cout << ">> ";
        string input;
        getline(cin, input);
        if(input == "q")
            return;
        if (isLegalExpression(input))
        {
            Expression expr = Parse(input);
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

            cout << result << endl;
        }
        else
        {
            cout << "invalid input\n";
        }
    } while (true);
    

}
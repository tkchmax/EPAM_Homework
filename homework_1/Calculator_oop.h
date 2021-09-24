
#ifndef CALCULATOR_OOP_H
#define CALCULATOR_OOP_H

#include <iostream>
#include <string>
using namespace std;

struct Expression
{
	Expression() : lsh(0), rsh(0), Operator('0') {}
	int lsh, rsh;
	char Operator;
};

class Calculator
{
public:
	Calculator() : rawExpression("0") {}

	Calculator(string rawExpr) : rawExpression(rawExpr) {}

	void go();
private:
	string rawExpression;
	Expression expr;

	void checkExpression();
	void Parse();
};

#endif


#ifndef CALCULATOR_PROC_H
#define CALCULATOR_PROC_H

#include <iostream>
#include <string>
using namespace std;

struct Expression
{
	Expression() : lsh(0), rsh(0), Operator('0') {}
	int lsh, rsh;
	char Operator;
};

Expression Parse(string s);
bool isLegalExpression(string s);
void calc();

#endif
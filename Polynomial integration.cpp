// Polynomial integration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Equation
{
private:
	int terms;
	std::vector<float> termz;
	float start;
	float fin;
public:
	void getterms();
	void inputequation();
	bool checkequation();
	void setlimits();
	void output();
	Equation()
	{
		terms = 0;
	};
};


void Equation::getterms()
{
	cout << "What is the largest exponent in your polynomial? \n";
	int exponent;
	cin >> exponent;
	terms = (exponent + 1);
	termz.resize(exponent + 1);
}

void Equation::inputequation()
{
	int b = 1;
	for (float coef : termz)
	{
		cout << "input the number " << b << " term \n";
		cin >> termz[b - 1];
		b++;
	}
};

bool Equation::checkequation()
{
	int e = 0;
	bool eq;
	string response;
	cout << "is this your equation? \n";
	for (float coef : termz)
	{
		cout << coef << "x^" << e << " + ";
		e++;
	}
	cout << "\n";
	cin.ignore(32767, '\n');
	getline(cin, response);
	if (!response.compare("yes")||!response.compare("Yes"))
	{
		return(1);
	}
	else
	{
		return(0);
	}

};

void Equation::setlimits()
{
	cout << "What do you want to integrate from? \n";
	cout << "insert the starting point: \n";
	cin >> start;
	cout << "insert the ending point: \n";
	cin >> fin;
}

void Equation::output()
{
	if (start < fin)
	{
		float sum = 0;
		float exponent;
		exponent = termz.size();
		exponent--;
		float control;
		int power;
		for (float a = start; a < fin; a = (a + .00001))
		{
			control = exponent;
			float equation;
			equation = 0;
			for (float coef : termz)
			{
				power = (exponent - control);
				equation = (coef*(pow(a, power)) + equation);
				control--;
			}
			sum = ((equation)*.00001 + sum);
		}
		cout << "The integral of the polynomial is " << sum << "\n";
	}
	else if (start > fin)
	{
		float sum = 0;
		float exponent;
		exponent = termz.size();
		exponent--;
		float control;
		int power;
		for (float a = start; a > fin; a = (a - .00001))
		{
			control = exponent;
			float equation;
			equation = 0;
			for (float coef : termz)
			{
				power = (exponent - control);
				equation = (coef*(pow(a, power)) + equation);
				control--;
			}
			sum = ((equation)*(-.00001) + sum);
		}
		cout << "The integral of the polynomial is " << sum << "\n";
	}
	else
	{
		cout << "The integral of the polynomial is zero. \n";
	}
}
int main()
{
	AGAIN:
	Equation polynomial;
	polynomial.getterms();
	polynomial.inputequation();
	if (!polynomial.checkequation()) {goto AGAIN;}
	polynomial.setlimits();
	polynomial.output();
    return 0;
}


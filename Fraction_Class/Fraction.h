#pragma once
// Fraction_Class
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
//////////////////ОБЪЯВЛЕНИЕ КЛАССА - CLASS DECLORATION/////////

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//					CONSTRUCTORS:
	Fraction();
	Fraction(double decimal);
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//				OPERATORS:
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//				TYPE-CAST OPERATORS:
	explicit operator int()const;
	explicit operator double()const;

	//				METHODS:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	std::ostream& print(std::ostream& os)const;
};
//////////////////////////////////////////////////////////////////////////
//////////////////КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLORATION END/////////
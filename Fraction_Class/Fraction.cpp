#include"Fraction.h"
//////////////////////////////////////////////////////////////////////////
//////////////////ОПРЕДЕЛЕНИЕ КЛАССА - CLASS DEFINITION//////////////////
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//					CONSTRUCTORS:
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal) : integer(decimal), denominator(1e+9), numerator(decimal* denominator)
{
	decimal -= integer;			//убираем целую часть из десятичной дроби
	reduce();
	cout << "DConstructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer) :integer(integer), numerator(0), denominator(1)
{
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) : integer(0), numerator(numerator)
{
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator) : integer(integer), numerator(numerator)
{
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//				OPERATORS:
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

//				TYPE-CAST OPERATORS:
Fraction::operator int()const
{
	return Fraction(*this).to_proper().integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//				METHODS:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{

	int more, less, rest = 0;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;	//GCD - Greates Common Divisor (Наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
std::ostream& Fraction::print(std::ostream& os)const
{
	if (integer)os << integer;
	if (numerator)
	{
		if (integer)os << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	else if (integer == 0)os << 0;
	//os << endl;
	return os;
}
//////////////////////////////////////////////////////////////////////////
//////////////////КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFINITION END/////////
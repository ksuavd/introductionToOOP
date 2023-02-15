// Fraction_Class
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//					CONSTRUCTORS:
	Fraction():integer(0), numerator(0), denominator(1)
	{
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(double decimal):integer(decimal), denominator(1e+9), numerator(decimal* denominator)
	{
		decimal -= integer;			//убираем целую часть из десятичной дроби
		reduce();
		cout << "DConstructor:\t\t" << this << endl;
	}
	explicit Fraction(int integer):Fraction(integer, 0, 1)
	{
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator):integer(0), numerator(numerator)
	{
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator):integer(integer), numerator(numerator)
	{
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other):integer(other.integer), numerator(other.numerator), denominator(other.denominator)
	{
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				OPERATORS:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				TYPE-CAST OPERATORS:
	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//				METHODS:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
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
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	std::ostream& print(std::ostream& os)const
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
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{

	return left * right.inverted();
}

//////////////////////////////////////////////////////////////////
//////					Comparison operators				//////
//////////////////////////////////////////////////////////////////

bool operator==(Fraction left, Fraction right)
{
	
	return
		left.to_proper().get_integer() == right.to_proper().get_integer() &&
		left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right); 
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	
	return !(left < right);	
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

/////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int number[3] = {};

	const int SIZE = 32;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";

	
	is.getline(buffer, SIZE);

	int n = 0;	

	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);	
	

	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:obj(number[0], number[1], number[2]);
	}

	return is;
}

/////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

//#define HOME_WORK_1
//#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
	cout << (Fraction(1, 3) <= Fraction(5, 10)) << endl;
	//cout << (3 == 3) << endl;  
#endif // COMPARISON_OPERATORS

#ifdef TYPE_CONVERSIONS_BASICS
			//	(type)value;	//C-like notation (C-подобная форма записи)
//	type(value);	//Functional notation (Функциональная форма записи)

//cout << 7. / 2 << endl;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less with no data loss
	int d = 4.5;	//Conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS

	/*
	-------------------------------------
	1. Преобразование других типов в наш;
		Single-argument constructor;
		Assignment operator;
	2. Преобразование и нашего типа в другие типы;
	-------------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;	//Conversion from other to class preformed by Single-argument constructor
	A.print();

	Fraction B;
	B = Fraction(8);			//Conversion from other to class preformed by Assignment operator
	B.print();

	//	explicit - явный  
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
			/*
-------------------------------------
Type-cast operators
operator type()const
{
	conversion algorithm;
	return ...;
}
-------------------------------------
*/

	Fraction A(11, 4);
	A.print();
	int a = (int)A;
	cout << a << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK_1
	Fraction B(2, 3, 4);
	double b = (double)B;
	cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction B = 2.75;
	//B.print(cout) << endl;;
	cout << B << endl;
#endif // HOME_WORK_2

	Fraction A;
	//cout << "Введите простую дробь: "; cin >> A;
	/*
		5;
		1/2;
		2(3/4);
		2 3/4;
	*/
//cout << A << endl;
	Fraction B;
	B = Fraction(8,3,5);		
	cout << B  << endl;
	Fraction C = Fraction(8);
	cout << C << endl;


}

// Fraction_Class

#include <iostream>
using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator- (Fraction left, Fraction right);
bool operator == (Fraction left, Fraction right);  
bool operator > (Fraction left, Fraction right);
bool operator < (Fraction left, Fraction right);
/*
    bool operator >= (Fraction left, Fraction right);
    bool operator <= (Fraction left, Fraction right);
    bool operator != (Fraction left, Fraction right);
    */

class Fraction
{
    int integer;//целая часть
    int numerator;//числитель
    int denominator;//знаменатель
   
  
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
    //Constructors
    Fraction(int integer, int numerator, int denominator)
    {
        this->integer= integer;
        this->numerator= numerator;
        this->set_denominator(denominator);
        cout << "Constructor:\t\t" << this << endl;
    }
    Fraction()
    {
       this->integer = 0;
       this->numerator = 0;
       this->denominator = 1;
       cout << "DefConstructor:\t\t" << this << endl;
    }
    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "1ArgConstructor:\t" << this << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        this->set_denominator(denominator);
        cout << "Constructor:\t\t" << this << endl;
    }
    Fraction(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator=other.denominator;
        cout << "CopyConstructor:\t" << this << endl;
    }
    //Destructor
    ~Fraction()
    {
        cout << "Destructor:\t\t" << this << endl;
    }
    //Operators


   

    //Metods

    Fraction& to_proper()//целую часть интегрирует в числитель
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


    Fraction& to_improper() // выделяет целую часть из числителя
    {
        numerator += integer * denominator;
        integer = 0;
        return *this;
    }
    void print()const
    {
        if (integer)cout << integer;
        if (numerator)
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        else if (integer == 0)cout << 0;
        cout << endl;
    }
   
};

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    /*
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result;
    */

    //Явно вызываем конструктор и создаем временный безымянный объект
    //который сразу же возвращается на место вызова:
    return Fraction
    {
       left.get_numerator() * right.get_numerator(),
       left.get_denominator() * right.get_denominator()
    }.to_proper();
    
}
Fraction operator/(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction
    {
       left.get_numerator() * right.get_denominator(),
       right.get_numerator() * left.get_denominator()
    }.to_proper();

 //   return left * right.inverted();  //также запись что сверху только короче

}

Fraction operator+ (Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction
    {
       left.get_numerator() * right.get_denominator()+ right.get_numerator()* left.get_denominator(),
       left.get_denominator() * right.get_denominator()
    }.to_proper();
}

Fraction operator- (Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction
    {
       left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
       left.get_denominator() * right.get_denominator()
    }.to_proper();
}
bool operator == (Fraction left, Fraction right)
{

    left.to_improper();
    right.to_improper();
    if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())  return true;
    else return false;
    return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
    return  left.to_improper().get_numerator() * right.get_denominator() == right.to_improper().get_numerator() * left.get_denominator();
}
bool operator > (Fraction left, Fraction right)
{
return  left.to_improper().get_numerator()* right.get_denominator()> right.to_improper().get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
    return  left.to_improper().get_numerator() * right.get_denominator() < right.to_improper().get_numerator() * left.get_denominator();
}



//#define CONSTRUCTORS_CHECK

int main()
{
#ifdef CONSTRUCTORS_CHECK
    setlocale(LC_ALL, "");
    Fraction A;
    A.print();

    Fraction B=5;
    B.print();

    Fraction C(2,3);
    C.print();

    Fraction D(2, 3,4);
    D.print();

    Fraction E=D;
    E.print();
#endif
    double a = 2;
    double b = 3;
    double c = a * b;


    Fraction A(2, 3, 4);
    A.print();

    Fraction B(3,4,5);
    B.print();

    Fraction C = A * B;
    C.print();

    Fraction D = A / B;
    D.print();

    /*A *= B;
    A.print();*/
    (B + A).print();
    (B - A).print();
    cout << (B==A) << endl;
    cout << (A > B) << endl;
    cout << (A < B) << endl;
}

// Fraction_Class

#include <iostream>
#include <string.h>

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
    Fraction(double decimal)
    {
        decimal += 1e-9;
        this->integer = decimal; //сохраняем целую часть
        decimal -= integer; //убираем целую часть из десятичной дроби
      this->denominator = 1e+9;
        this->numerator = decimal * denominator;
        reduce();
    }


    //Destructor
    ~Fraction()
    {
        cout << "Destructor:\t\t" << this << endl;
    }
    //Operators

    //Fraction& operator=()(int integer, int numerator, int denominator)
    //{

    //}

    Fraction& operator=(const Fraction& other)//перегрузка оператора присваивания
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyAssigment:\t\t" << this << endl;
        return *this;
    }
    Fraction& operator*=(const Fraction& other)
    {
        return *this = *this * other;
    }

    //Type-cast operators
    explicit   operator int()const
    {
        return Fraction(*this).to_proper().integer;
    }

    explicit   operator double()const
    {
        return  ((double)numerator/ (double)denominator)+ (double)integer;
    }
  
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
    void print()const //void &print(std::ostream& os)const //для вызова cout из перегруженного оператора
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
        //return os; //для вызова cout из перегруженного оператора
    }

    Fraction& reduce()
    {
        int more, less, rest = 0;//большее , меньшее , остаток
        if (numerator > denominator)more = numerator, less = denominator;//выясняем кто больше
        else less = numerator, more = denominator;
        do
        {
            rest = more % less; //в остаток записываем рез. от деления большего на меньшее 
            more = less;
            less = rest;
        } while (rest);
        int GCD = more;//GCD-Grates Common Divisor (наибольший общий делитель)
        numerator /= GCD;
        denominator /= GCD;
        return *this;
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
    }.to_proper().reduce();
    
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
bool operator>=(const Fraction& left, const Fraction& right)
{
    //return left > right || left == right; //больше или равно - это НЕ меньше
    return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
  //  return left < right || left == right;
    return !(left > right);
}
ostream& operator<< (ostream& os, const Fraction& obj)
{
    if (obj.get_integer())os << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())os << "(";
        os << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())os << ")";
    }
    else os << 0; 
    return os;
    //return obj.print(os); // тоже самое написание перергрузки оператора только короче! 
}
istream& operator>> (istream& is, Fraction& obj)
{
  /* int integer;
    int numerator;
    int denominator;
    is >> integer >> numerator >> denominator;
    obj.set_integer(integer);
    obj.set_numerator(numerator);
    obj.set_denominator(denominator);*/ 
    int number[3] = {}; //массив для чисел в дроби

    const int SIZE = 32; // строка
    char buffer[SIZE] = {};
    char delimitres [] = "/ ()";

    //is>> buffer;
    is.getline(buffer, SIZE);
    int n = 0;// счетчик чисел в введной строке
    for (char* pch = strtok(buffer, delimitres); pch; pch = strtok(NULL, delimitres))
        number[n++] = atoi(pch);// функция atoi (...) ASCII-string to integer преобразование 
    switch (n)
    {
        case 1:obj.set_integer(number[0]); break;
        case 2:
            obj.set_numerator(number[0]); 
            obj.set_denominator(number[1]);
            break;
        case 3:((number[0]), (number[1]), (number[2])); break;
    }
    return is;
}


//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATORS
//#define OPERATORS2
#define HOMR_WORK_1
int main()
{
    setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
   
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
#ifdef COMPARISON_OPERATORS
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

    A *= B;
    A.print();
    (B + A).print();
    (B - A).print();
    cout << (B==A) << endl;
    cout << (A > B) << endl;
    cout << (A < B) << endl;
    A = A * B;

    cout << (Fraction(1, 3) <= Fraction(5,11)) << endl;
#endif  
#ifdef OPERATORS2
    Fraction A  (5,6,7); 
    A.print();
    cout << A << endl;

    /*Fraction B; 
    cout << "Введите дробь: "; cin >> B; cout << B << endl;*/
#endif
    //explicit -явный 
    /*
    1.   Перобразование других типов в наш;
       Single-argument constructor;
       Assignment operator;
    
    2. Перобразование и нашего типа в другие типы;

    */

    /**   Fraction A(2,3,4);
    cout << A << endl;
    int a = (int)A;
    cout << a << endl;

    //Home Work

    Fraction B(2, 3, 4);
    double b = (double)B;
    cout << b << endl;
    
   Fraction C = 2.76;
    cout << C << endl;
    */
    
    Fraction D;
    cout << "Введите дробь: "; cin >> D; cout << D << endl; 
    

}

// Fraction.cpp 
#include <iostream>
using namespace std;
class Fraction
{
    int integer;//целая часть
    int numerator;//числитель
    int denomerator;//знаменатель
public:
    int get_integer()const
    {
        return integer;
    }
    int get_numerator()const
    {
        return numerator;
    }
    int get_denomerator()const
    {
        return denomerator;
    }
    void set_integer (int integer)
    {
        this->integer= integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denomerator(int denomerator)
    {
        if (denomerator == 0)denomerator = 1;
        this->denomerator = denomerator;   
    }
        //Constructors
    Fraction(int integer = 0, int numerator = 0, int denomerator = 1)
    {
        this->set_integer(integer);
        this->set_numerator (numerator);
        this->set_denomerator(denomerator);
    }
        //Destructor
    ~Fraction()
    {

    }
        //Operators


        //Metods
   
    void to_proper()//целую часть интегрирует в числитель
    {
        integer += numerator / denomerator;
        numerator %= denomerator;
    }

   void to_improper() // выделяет целую часть из числителя
    {
        numerator += integer * denomerator;
        integer = 0;
    }
   void print()const
   {
       if (integer)cout << integer;
       if (numerator)
       {
           if (integer)cout << "(" << numerator << "/" << denomerator << ")" << endl;
       }
       else if (integer == 0)cout << 0 << endl;
       cout << endl;
   }

};
/*Fraction operator+(const Fraction& left, const Fraction& right)
{
    Fraction res;

       
        
}*/

//#define OUTPUT_ON_DISPLAY
//#define PROPER_IMPROPER



int main()
{
    setlocale(LC_ALL, "");
#ifdef OUTPUT_ON_DISPLAY
    cout << "Hello Fraction!\n";

    Fraction A(5);
    A.print();

    Fraction B(1, 2);
    B.print();

    Fraction C(2, 3, 4);
    C.print();
#endif //OUTPUT_ON_DISPLAY

#ifdef PROPER_IMPROPER

    Fraction A(1,2,5);
    A.print();
    A.to_improper();
    A.print();


#endif//PROPER_IMPROPER
}
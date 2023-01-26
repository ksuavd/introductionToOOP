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
};

int main()
{
    setlocale(LC_ALL, "");
    cout << "Hello Fraction!\n";


}

// String.cpp 
#include <iostream>
#include <cstring>
using namespace std;
class String;

class String
{
    int size;// размер строки
    char* str;//адрес строки в динамической памяти

public:
    int get_size()const
    {
        return size;
    }
    const char* get_str()const
    {
        return str;
    }

//Constructors
explicit String(int size = 80) //конст-р с параметром по умолчанию
{
    this->size = size;
    this->str = new char[size] {};//выделение памяти для строки
    cout << "DefConstructor:\t" << this << endl;
}
String(const char* str)
{
    int size = strlen(str);
    this->str = new char[size + 1];// выделение памяти + 1 на терминрующ. 0
    for (size_t i = 0; i < size; i++)// перебираем циклом каждый элемент полученного массива и каждый символ скопировать в указатель
    {
        this->str[i] = str[i];
    }
    this->str[size] = '\0';// обозначаем конец строки, в последний элемент присваиваем терм. 0
}


//Destructor
~String()
{
    delete this->str;
    cout << "Destructor:\t" << this << endl;
}
//Operators
//String operator+(const String& other)
//{
//   
//    return newStr;
//}
//Metods
void print()const
{
    cout << "Size:\t" << size << endl;
    cout << "Str:\t" << str << endl;
}

};

std::ostream& operator<<(std::ostream& os, const String& obj)//перегрузка cout
{
    return    os << "Str:\t" << obj.get_str();
}

int main()
{
 //   setlocale(LC_ALL, "");
    String str1 = "Hello";
    cout << str1 << endl;

    String str2 = "World";
    cout << str2 << endl;

/*
   String str3 = str1 + str2;
   cout << str3 << endl;
   */
}


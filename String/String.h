//String.h
#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
////////////ОБЪЯВЛЕНИЕ КЛАССА -CLASS DECLARATION//////////////////////////////////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
class String
{
    int size;// размер строки в байтах
    char* str;//адрес строки в динамической памяти

public:
    int get_size()const;
    const char* get_str()const;
    char* get_str();

    //Constructors
    explicit String(int size = 80);
    String(const char* str);
    String(const String& other);
    String(String&& other)noexcept;

    //Destructor
    ~String();

    //OPERATORS
    String& operator=(const String& other);
    String& operator=(String&& other)noexcept;
    String& operator+=(const String& other);

    const char& operator[](int i)const;
    char& operator[](int i);

    //METODS
    void print()const;

};

///////////////////////////////////////////////////////////////////////////////////////
////////////КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА -CLASS DECLARATION END/////////////////////////////

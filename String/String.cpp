// String.cpp 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
////////////ОБЪЯВЛЕНИЕ КЛАССА -CLASS DECLARATION//////////////////////////////////////
class String;
String operator+(const String& left, const String& right);
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



//////////////////////////////////////////////////////////////////////////////////////
////////////ОПРЕДЕЛЕНИЕ КЛАССА -CLASS DEFENISION//////////////////////////////////////
int String::get_size()const
{
    return size;
}
const char* String::get_str()const
{
    return str;
}
char* String::get_str()
{
    return str;
}

//Constructors
 String::String(int size) :size(size), str(new char[size] {}) //конст-р с параметром по умолчанию
{
    cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
    for (int i = 0; i < size; i++)  this->str[i] = str[i];
    cout << "1ArgConstructor:" << this << endl;
}
String::String(const String& other):String(other.str)
{
    //Deep copy - побитовое копирование
    for (int i = 0; i < size; i++) this->str[i] = other.str[i];
    cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str)
{
    //Shallow copy - поверхностное копирование
    other.size = 0;
    other.str = nullptr;		//nullptr - это указатель на ноль.
    cout << "MoveConstructor:" << this << endl;
}

//Destructor
String::~String()
{
    delete this->str;
    cout << "Destructor:\t" << this << endl;
}
//Operators
String& String::operator=(const String& other)
{
    //			l-value = r-value;
    if (this == &other)return *this;
    delete[] this->str;
    this->size = other.size;
    this->str = new char[size] {};
    for (int i = 0; i < size; i++)
        this->str[i] = other.str[i];
    cout << "CopyAssignment:\t" << this << endl;
    return *this;
}

String& String::operator=(String&& other)noexcept
{
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "MoveAssignment:\t" << this << endl;
    return *this;
}
String& String::operator+=(const String& other)
{
    return *this = *this + other;
}
const char& String::operator[](int i)const
{
    return str[i];
}
char& String::operator[](int i)
{
    return str[i];
}

//Metods
void String::print()const
{
    cout << "Size:\t" << size << endl;
    cout << "Str:\t" << str << endl;
}


String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)//перегрузка cout
{
    return os << "Str:\t" << obj.get_str();
}
///////////////////////////////////////////////////////////////////////////////////////
////////////КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFENISION END////////////////////////////

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS
int main()
{
  setlocale(LC_ALL, "");
#ifdef BASE_CHECK
    String str (5);
    str.print();

   String str1 = "Hello"; // "Hello" - это строковая константа
   str1 = str1;
   cout << str1 << endl;

   String str2 = "World";
   cout << str2 << endl;


//   cout << "\n-------------------------------------------------------\n";
  // str1 += str2;
  // cout << str1 << endl;
  // cout << "\n-------------------------------------------------------\n";


   String str3;
   str3=str1+str2; // Move constructor
   cout << str3 << endl;

   String str4 = str3;//Copy constructor
   str4.print();
    //str1=str3;
   // cout << str1 << endl;
#endif // BASE_CHECK
#ifdef CALLING_CONSTRUCTORS
    String str1;	             //Default constructor
	str1.print();

	String str2 = "Hello";	 //Single argument constructor
	str2.print();
	String str3 = str2;	     //Copy constructor

	str3.print();
	String str4();           //здесь не вызывается никакой конструктор! Потому что здесь не создается объект
                             // Здесь объявляется функция str4(), которая не принимает никаких параметров, 
                             // и возвращает значение типа String.
    //  str4.print();           //str4-это НЕ объект, это функция, а для функции нельзя вызвать метод!
    //Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так: 
    String str5{};           //явный вызов конструктора по умолчанию
    str5.print();
    String str6{22};         
    str6.print();
    String str7{ "World" };
    str7.print();
    String str8{ str7 };      // Copy constructor
    str8.print();
#endif //CALLING_CONSTRUCTORS

}


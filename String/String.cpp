// String.cpp 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class String;
String operator+(const String& left, const String& right);
class String
{
    int size;// размер строки в байтах
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
    char* get_str()
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
    this->size = strlen(str) + 1;//вычисляем размер строки 
    this->str = new char[size] {};// выделение памяти + 1 на терминрующ. 0
    for (int i = 0; i < size; i++)// перебираем циклом каждый элемент полученного массива и каждый символ скопировать в указатель
    {
        this->str[i] = str[i];
    }
    cout << "1ArgConstructor:\t" << this << endl;
    //this->str[size] = '\0';// обозначаем конец строки, в последний элемент присваиваем терм. 0
}

String (const String& other) //Shallow copy -поверхностное копирование
{
    //Deep copy - побитовое копирование
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
}
String(String&& other)noexcept
{
    //Shallow copy - поверхностное копирование
    this->size = other.size;
    this->str = other.str;		//Shallow copy
    other.size = 0;
    other.str = nullptr;		//nullptr - это указатель на ноль.
    cout << "MoveConstructor:" << this << endl;
}

//Destructor
~String()
{
    delete this->str;
    cout << "Destructor:\t" << this << endl;
}
//Operators
String& operator=(const String& other) // оператор присваивания
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

String& operator=(String&& other)
{
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "MoveAssignment:\t" << this << endl;
    return *this;
}
String& operator+=(const String& other)
{
    return *this = *this + other;
}
const char& operator[](int i)const
{
    return str[i];
}
char& operator[](int i)
{
    return str[i];
}

//Metods
void print()const
{
    cout << "Size:\t" << size << endl;
    cout << "Str:\t" << str << endl;
}

};

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


//#define BASE_CHECK

int main()
{
  setlocale(LC_ALL, "");
#ifdef BASE_CHECK
    //String str1 (5);
    //str1.print();

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
   
    //str1=str3;
   // cout << str1 << endl;
#endif // BASE_CHECK
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


}


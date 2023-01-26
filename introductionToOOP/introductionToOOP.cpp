// introductionToOOP.cpp 
#include <iostream>
using namespace std;
#define delimiter "\n----------------------------------------\n"

class Point //Создавая структуру или класс, мы создаем новый тип данных.
{
private:
    double x;
    double y;
    
public: 
    double get_x() const//возвращаем значение переменной х
    {
        return x;
    }
    void set_x(double valeX)//устанавливаем значение x
    {
      this->x = valeX;
    }
    double get_y() const//возвращаем значение переменной y
    {
        return y;
    }
    void set_y(double valeY)//устанавливаем значение y
    {
        this->y= valeY;//напрямую обращаемся к полям объекта
    }
 /*   void Print()
    {
        cout << "X = " << x << "\t Y = " << y << endl;
    }*/
            //Constructors;
   /*  {   Point()
      
        x = y = 0;
        cout << "DefConstructors:\t" << this << endl;
    }*/
   /*Point(double x)
    {
        this->x = x;
        this->y = 0;
        cout << "1ArgConstructors:\t" << this << endl;
    }*/
    /*   Point(double x, double y)
    {
        this->x = x;
        this->y = y;
        cout << "Constructors:\t" << this << endl;
    }*/
   Point(double x=0, double y=0)
    {
        this->x = x;
        this->y = y;

    cout << "Constructor:\t" << this << endl;
  }
   Point(const Point& other)
   {
       this->x = other.x;
       this->y = other.y;
       cout << "CopyConstructors:" << this << endl;
   }

   ~Point()
    {
        cout << "Destructor:\t" << this << endl;
    }
         //Operators
   
   Point& operator=(const Point& other)
   {
       this->x = other.x;
       this->y = other.y;
       cout << "CopyAssignment: " << this << endl;
       return *this;
   }
   Point& operator++()
   {
       x++;
       y++;
       return *this;
   }
   Point operator++(int)
   {
       Point old = *this;
       x++;
       y++;
       return old;
   }
             //Metods:
   void Print() const
   {
       cout << "X = " << x << "\t Y = " << y << endl;
   }
    double distance (const Point& dot) const
    {
        double distance_X = this->x - dot.x;
        double distance_Y= this->y - dot.y;
        double distance = sqrt(distance_X * distance_X + distance_Y * distance_Y);
        return distance;
    }
};
   Point operator+(const Point& left, const Point& right)
    {
        Point res;
        res.set_x(left.get_x() + right.get_x());
        res.set_y(left.get_y() + right.get_y());
        return res;
    }
   std::ostream& operator<<(std::ostream & os, const Point& obj)
   {
   return    os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
   }

   istream& operator >> (istream& is, Point& obj)
   {
       double x, y;
       is >> x >> y;
       return is;
   }
 


    //Comparison operator
 bool operator ==(const Point& left, const Point& right)
    {
      //  if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
          //  return true;
        //else
       //     return false;
     return(left.get_x() == right.get_x() && left.get_y() == right.get_y());
    }
  
  /*bool operator !=(const Point& left, const Point& right)
  {

return (!left==right);
    }*/

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

double distance(const Point& A, Point& B);


int main()
{
    setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
    A.x = 2;
    A.y = 3;
    cout << A.x << "\t" << A.y << endl;
    Point* pA = &A;
    cout << pA->x << "\t" << pA->y << endl; */
#endif // STRUCT_POINT
#ifdef DISTANCE_CHECK
        Point A;//Объявление переменной А типа Point или же объявление объекта А структуры Point или же создание экземпляра А структуры Point
    A.set_x(2);
    A.set_y(3);
    //  cout << A.get_x() << "\t" << A.get_y() << endl; - для вызова без функции Print, а через cout 
    A.Print();
    cout << delimiter << endl;
    Point B;
    B.set_x(7);
    B.set_y(8);
    B.Print();
    cout << delimiter << endl;
    cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
    cout << delimiter << endl;
    cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
    cout << delimiter << endl;
#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK
    Point A;
    //  cout << A.get_x() << "\t" << A.get_y() << endl;
    A.Print();

    Point B(2, 3);
    B.Print();

    Point C = 4;// конструктор с 1 параметром
    C.Print();

    Point D = C;//конструктор копирования
    D.Print();
#endif //CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK_1
    //CopyAssignment
    Point A(2, 3);
    A.Print();
    Point B = A;//Конструктор копирования - CopyConstructor
    B.Print();
    Point C;
    C = B;//Оператор присваивания - CopyAssignment
    C.Print();
#endif
#ifdef ASSIGNMENT_CHECK_2
    int a, b, c;
    a = b = c = 0;

    Point A, B, C;
    cout << delimiter << endl;
    A = B = C = Point(2, 3);
    //Point (2,3) - явный вызов конструктора, и этот конструктор создает временный безымяный объект
    //Временные безымянные объекты существуют в переделах одного выражения.
    cout << delimiter << endl;
#endif
    int a = 2;
    int b = 3;
    int c = a + b;

    Point A(2, 3);
    Point B(4, 5);
    /* Point C = A + B + A + B;
     cout << delimiter << endl;
     C.Print();

     ++C;*/
     // cout << delimiter << endl;
    //  C.Print();
   // cout << (A != B) << endl;
  //  Point A(2, 3);
    //A.Print();
    // A.set_x(12);
    // A.set_y(13);
  
    // A.Print();
    
    cout << "Введите координаты точки: "; cin >> A;
    cout << A << endl;
}

double distance(const Point& A, Point& B)
{
    double Xdot = A.get_x() - B.get_x();
    double Ydot = A.get_y() - B.get_y();
    double distance = sqrt(Xdot * Xdot + Ydot * Ydot);
    return distance;
}
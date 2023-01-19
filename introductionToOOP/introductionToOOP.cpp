// introductionToOOP.cpp 
#include <iostream>
using namespace std;

class Point //Создавая структуру или класс, мы создаем новый тип данных.
{
private:
    double x;
    double y;
    
public: 
    double GetX() const//возвращаем значение переменной х
    {
        return x;
    }
    void SetX(double valeX)//устанавливаем значение x
    {
      this->x = valeX;
    }
    double GetY() const//возвращаем значение переменной y
    {
        return y;
    }
    void SetY(double valeY)//устанавливаем значение y
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
    cout << "Constructors:\t" << this << endl;
  }
        
   ~Point()
    {
        cout << "Constructors:\t" << this << endl;
    }
    //Metods:
    double distance (Point dot) const
    {
        double distance_X = this->x - dot.x;
        double distance_Y= this->y - dot.y;
        double distance = sqrt(distance_X * distance_X + distance_Y * distance_Y);
        return distance;
    }
    void Print() const
    {
        cout << "X = " << x << "\t Y = " << y << endl;
    }

}; 

//#define STRUCT_POINT
//#define DISTANCE_CHECK
double distance(Point A, Point B);


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
    A.SetX(2);
    A.SetY(3);
  //  cout << A.GetX() << "\t" << A.GetY() << endl; - для вызова без функции Print, а через cout 
    A.Print();

    Point B; 
    B.SetX(7);
    B.SetY(8);
    B.Print();

    cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
    cout << "Расстояние между точками А и В: " <<distance(A, B) << endl;
#endif // DISTANCE_CHECK
    Point A;
  //  cout << A.GetX() << "\t" << A.GetY() << endl;
    A.Print();

    Point B(2, 3);
        B.Print();

        Point C = 4;// конструктор с 1 параметром
        C.Print();
}

double distance(Point A, Point B)
{
    double Xdot = A.GetX() - B.GetX();
    double Ydot = A.GetY() - B.GetY();
    double distance = sqrt(Xdot * Xdot + Ydot * Ydot);
    return distance;
}
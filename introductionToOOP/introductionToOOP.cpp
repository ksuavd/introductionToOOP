// introductionToOOP.cpp 
#include <iostream>
using namespace std;

class Point //Создавая структуру или класс, мы создаем новый тип данных.
{
private:
    double x;
    double y;
    
public: 
    int GetX()//возвращаем значение переменной х
    {
        return x;
    }
    void SetX(int valeX)//устанавливаем значение x
    {
        x = valeX;
    }
    int GetY()//возвращаем значение переменной y
    {
        return y;
    }
    void SetY(int valeY)//устанавливаем значение y
    {
        y = valeY;
    }
    void Print()
    {
        cout << "X = " << x << "\t Y = " << y << endl;
    }


}; 



int main()
{
    setlocale(LC_ALL, "");
    Point A;//Объявление переменно А типа Point или же объявление объекта А структуры Point или же создание экземпляра А структуры Point
    /*  A.x = 2;
    A.y = 3;
    cout << A.x << "\t" << A.y << endl;
    Point* pA = &A;
    cout << pA->x << "\t" << pA->y << endl;*/
    A.SetX(2);
    A.SetY(3);
    A.Print();
    

 
}


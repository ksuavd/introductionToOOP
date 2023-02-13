// Matrix.cpp 
#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
    int rows, cols;
    double** mat;

public:

    int get_rows()const
    {
        return rows;
    }
    int get_cols()const
    {
        return cols;
    }

    //Constructors
    Matrix(int rows = 0, int cols = 0)
    {
        this->rows = rows;
        this->cols = cols;
        this->mat = new double* [rows] {};
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new double[cols] {};
        }
        cout << "Constructor:\t" << endl;
    }



    //Destructor



    //Operators
  


    //Metods
    void print()const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void rand(int number = 100)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                this->mat[i][j] = rand() % number;
            }
        }
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    Matrix A(3, 4);
    A.rand();
    A.print();
}


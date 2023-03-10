#include <iostream>
using namespace std;


typedef struct Matrix3x3 
{
    int matrix[3][3];

    void setMatrix(int mat[3][3]) 
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                matrix[i][j] = mat[i][j];
            }
        }
    }

    void printMatrix() 
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << matrix[i][j]<<" ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int at(int x, int y)
    {
        return matrix[x][y];
    }

    int Det()
    {
        int result;

        int x = 1, y = 1, z = 1;
        int num;

        for (int i = 0; i < 3; i++)
        {
            num = i;

            x *= at(i, num);
            num++;

            if(num >= 3)
            {
                num = num - 3;
            }

            y *= at(i, num);
            num ++;

            if(num >= 3)
            {
                num = num - 3;
            }

            z *= at(i, num);
        }
        
        result = x + y + z;
        x = 1, y = 1, z = 1;

        for (int i = 0; i < 3; i++)
        {
            num = i + i;

            if(num >= 3)
            {
                num = num - 3;
            }

            x *= at(i, num);
            num++;

            if(num >= 3)
            {
                num = num - 3;
            }

            y *= at(i, num);
            num ++;

            if(num >= 3)
            {
                num = num - 3;
            }

            z *= at(i, num);
        }

        result = result - (x + y + z);

        return result;
    }

    int Trace()
    {
        int trace = 0;
        
        for (int i = 0; i < 3; i++)
        {
            trace += at(i, i);
        }
        
        return trace;
    }

} Mat;

Mat add(Mat a, Mat b)
{
    Mat result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.matrix[i][j] = a.at(i, j) + b.at(i, j);
        }
    }

    return result;
}

Mat multi(Mat a, Mat b)
{
    Mat result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result.matrix[i][j] += a.at(i, k) * b.at(k, j);
            }
        }
    }

    return result;
}

int main() 
{
    int matrix1[3][3] = { {1,2,3}
                         ,{4,5,6}
                         ,{7,8,9} };
    int matrix2[3][3] = { {1,0,0},
                          {4,5,6},
                          {7,8,9} };
    Mat a;
    a.setMatrix(matrix1);
    a.printMatrix();
    Mat b;
    b.setMatrix(matrix2);
    b.printMatrix();

    cout << "행렬의 덧셈 : " << endl;
    add(a, b).printMatrix();

    cout << "행렬의 곱셈 : " << endl;
    multi(a, b).printMatrix();

    cout << "행렬 a의 판별식 : ";
    cout << a.Det() << endl;
    cout << "행렬 b의 판별식 : ";
    cout << b.Det() << endl;

    cout << endl;

    cout << "행렬 a의 trace : ";
    cout << a.Trace() << endl;
    cout << "행렬 b의 trace : ";
    cout << b.Trace() << endl;
    
    cout << endl;

    cout << "(AB).Trace() : ";
    cout << multi(a, b).Trace() << endl;
    cout << "(AB).Det() : ";
    cout << multi(a, b).Det() << endl;

    return 0;
}
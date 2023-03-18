//2 contributors
//Touched by user2 (230317)


#include <iostream>
using namespace std;

//2차원 배열을 이용한 3x3 행렬
typedef struct Matrix3x3 
{
    int matrix[3][3];

//행렬 값 받아와서 저장하는 함수
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

//행렬을 출력하는 함수
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

//행렬의 특정 요소에 접근할 수 있는 함수
    int at(int x, int y)
    {
        return matrix[x][y];
    }

//행렬의 판별식을 구하는 함수
    int Det()
    {
        int result = 0;

        int x[3];
        for (int i = 0; i < 3; i++)
	    {
		    x[i] = 1;
	    }
        int num;

        for (int i = 0; i < 3; i++)
        {
            num = i;

            for (int j = 0; j < 3; j++)
            {
                x[j] *= at(i, num);
                num++;

                if(num >= 3)
                {
                    num = num - 3;
                }
            }
        }
        
        for (int i = 0; i < 3; i++)
        {
            result = result + x[i];
            x[i] = 1;
        }

        for (int i = 0; i < 3; i++)
        {
            num = i + i;

            for (int j = 0; j < 3; j++)
            {
                if(num >= 3)
                {
                    num = num - 3;
                }

                x[j] *= at(i, num);
                num++;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            result = result - x[i];
        }
        
        return result;
    }

//행렬의 Trace를 리턴하는 함수
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

//행렬의 덧셈
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

//행렬의 곱셈
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

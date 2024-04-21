#include <iostream>

class Matrix{
public:
Matrix(const int& n,const int& m)  : row(n),column(m)
{
    matrix = new int*[row];
    for(int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }
}

Matrix(const Matrix& obj){
    this->row = obj.row;
     this->column = obj.column;

     this->matrix = new int*[obj.row];
     for (int i = 0; i < obj.row; ++i)
     {
        matrix[i] = new int[obj.column];
     }
     

     for (int i = 0; i < obj.row; ++i)
     {
        for (int j = 0; j < obj.column; ++j)
        {
            this->matrix[i][j] = obj.matrix[i][j];
        }
     }

}

Matrix& operator =(const Matrix& obj){
    if (this == &obj)
    {
        return *this;
    }
    

     for(int i = 0;i < row; ++i){
	     delete [] matrix[i];
     }
     delete [] matrix;

     this->row = obj.row;
     this->column = obj.column;

     this->matrix = new int*[obj.row];
     for (int i = 0; i < obj.row; ++i)
     {
        matrix[i] = new int[obj.column];
     }
     

     for (int i = 0; i < obj.row; ++i)
     {
        for (int j = 0; j < obj.column; ++j)
        {
            this->matrix[i][j] = obj.matrix[i][j];
        }
        
     }
   
    return *this;
}

Matrix operator +(const Matrix& obj){
    if (row == obj.row && column == obj.column)
    {
        Matrix temp(row,column);
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
            }
            
        }

        return temp;
    }else{
        std::cout<<"The matrices dimensions are not the same:"<<std::endl;
    }
    
}

Matrix operator -(const Matrix& obj){
    if (row == obj.row && column == obj.column)
    {
        Matrix temp(row,column);
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                temp.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
            }
            
        }

        return temp;
    }else{
        std::cout<<"The matrices dimensions are not the same:"<<std::endl;
    }
    
}

~Matrix(){
    for(int i = 0; i < row; ++i)
    {
        delete [] matrix[i];
        matrix[i] = nullptr;
    }

    delete [] matrix;
    matrix = nullptr;
}

public:
void matrixInit(){
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    
}

void printMatrix(){
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

private:
int row = 0;
int column = 0;
int** matrix = nullptr;

};

int main(int argc,char* argv[]){
    Matrix m1(2,3);
    m1.matrixInit();
    m1.printMatrix();

    std::cout<<std::endl;

    Matrix m2(m1);
    m2.printMatrix();

    std::cout<<std::endl;

    Matrix m3 = m1 - m2;;
    m3.printMatrix(); 

    return 0;
}

#include <iostream>
#include<matrix.h>
using namespace std;


Matrix::Matrix(int row ,int col , double element )
{
    this->row = row;
    this->col = col;
    this->n = col * row;
    this->mat = new double [n];
    for(int i=0; i < n; i++){
        this->mat[i] = element;
    }
}

Matrix::printf(){
    int count = 0;
    for(int i = 0; i < n; i++){
        count++;
        cout<<mat[i]<<" ";
        if(count == col){
            count = 0;
            cout<<endl;
        }
    }
}

Matrix::printf(int i, int j){
    cout<<mat[i*col+j]<<endl;
}

Matrix::Matrix(int row, int col, double mtx[])
{
 this->row = row;    this->col = col;
 this->n   = row * col; this->mat = new double[n];
 for(int i=0; i<n; i++)
  this->mat[i] = mtx[i];
}

Matrix::mix(int i, int j,int element){
    this->mat[i*col+j] = element;
}

 double Matrix::get(int i, int j){
    return this->mat[i*col+j];
}
bool Matrix::CheckIndex(int index_tobechecked,int indexnum)
 {     //在矩阵中前indexnum项中找是否有值等于index_tobechecked，
       //如果有，返回true，如果没有，返回false
         int i;
     for (i=0;i<indexnum;i++)
     {
         if(index_tobechecked==this->mat[i])
             break;
     }
     if(i<indexnum) return true;
     else return false;
 }
int Matrix::get_row(){
      return this->row;
  }
int Matrix::get_col(){
      return this->col;
  }
int Matrix::get_n(){
      return this->n;
  }

Matrix::Matrix(int row, double element){
    this->row = row;
    this->col = row;
    this->n = row*col;
    this->mat = new double [n];
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            if(i==j){
                this->mat[i*col+j] = element;
            }
            else {
                this->mat[i*col+j] = 0.0;
            }
        }
    }
}

Matrix Matrix::MatrixDeleteRows(int deletenum){
    int row = this->get_row()-deletenum;
    int col = this->col;

    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,this->get(i+deletenum,j));
        }
    }
    return newmat;
}

Matrix Matrix::MatrixDeleteRows(int order, int deletenum){
    int row = this->get_row()-deletenum;
    int col = this->get_col();
    Matrix newmat(row,col,0.0);
    for(int i=0; i < order; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,this->get(i,j));
        }
    }
    for(int i=order; i < row; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,this->get(i+deletenum,j));
        }
    }
    return newmat;
}

Matrix Matrix::MatrixDeleteColumns(int deletenum){
    int row = this->get_row();
    int col = this->get_col()-deletenum;
    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,this->get(i,j+deletenum));
        }
    }
    return newmat;
}
Matrix Matrix::MatrixDeleteColumns(int order, int deletenum){
    int row = this->get_row();
    int col = this->get_col()-deletenum;
    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < order; j++){
            newmat.mix(i,j,this->get(i,j));
        }
    }
    for(int i=0; i < row; i++){
        for(int j=order; j < col; j++){
            newmat.mix(i,j,this->get(i,j+deletenum));
        }
    }
    return newmat;
}

Matrix Matrix::SumMatrix( Matrix &obj1,  Matrix &obj2){
    int row = obj2.get_row();
    int col = obj2.get_col();
    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,obj1.get(i,j)+obj2.get(i,j));
        }
    }
    return newmat;
}

Matrix::Matrix( Matrix &obj1,  Matrix &obj2, char a){
    this->row = obj1.get_row();
    this->col = obj2.get_col();
    this->n = col*row;
    this->mat = new double [n];
    int m;
    switch (a)
    {
        case '+':
              {
                for(int i=0; i < row; i++){
                    for(int j=0; j < col; j++){
                        this->mat[i*col+j] = obj1.get(i,j)+obj2.get(i,j);
                    }
                }
                break;
               }
        case '*':
        {
            for(int i=0; i < n; i++){
                this->mat[i] = 0.0;
            }
            for(int i=0; i < row; i++){
                for(int j=0; j < col; j++){
                    for(int k=0; k < obj1.get_col(); k++){
                        this->mat[i*col+j] += obj1.get(i,k)*obj2.get(k,j);
                    }
                }
            }
            break;
        }
    case '-':{

          for(int i=0; i < row; i++){
              for(int j=0; j < col; j++){
                  this->mat[i*col+j] = -(obj1.get(i,j)+obj2.get(i,j));
              }
          }
          break;

        }
    }
}

Matrix Matrix::op_mat(){
    int row = this->get_row();
    int col = this->get_col();
    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
           newmat.mix(i,j,this->get(i,j));
        }
    }
    return newmat;
}

Matrix Matrix::get_mat(int row_s, int row_b, int col_s, int col_b){
    int row = row_b-row_s+1;
    int col = col_b-col_s+1;
    Matrix newmat(row,col,0.0);
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            newmat.mix(i,j,this->get(i+row_s-1,j+col_s-1));
        }
    }
    return newmat;
}

Matrix Matrix::mix_mat(int row_s, int row_b, int col_s, int col_b, double element[]){
    int q=0;
    for(int i=row_s; i < row_b; i++){
        for(int j=col_s; j < col_b; j++){
            this->mix(i,j,element[q]);
            q++;
        }
    }
}

Matrix Matrix::trv( Matrix &A){
    Matrix At(A.get_col(),A.get_row(),0.0);
    for(int i=0; i < A.get_col(); i++){
        for(int j=0; j < A.get_row(); j++){
            At.mix(i,j,A.get(j,i));
        }
    }
    return At;
}
//M*N =E;
Matrix Matrix::inv(Matrix A){ //A是n阶矩阵
    Matrix A_1(A.get_col(),A.get_row(),0.0);
    for(int i=0; i < A.get_col(); i++){
        for(int j=0; j < A.get_row(); j++){
            if(i==j){

            }
        }
    }
}

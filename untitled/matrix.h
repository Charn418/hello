#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
    int col;//列
    int row;//行
    double element; //元素
    int n;  //  元素个数
    double *mat; //矩阵
public:
    //定义一个矩阵元素全是elemen的row*col的矩阵
    Matrix(int row = 1,int col = 1, double element = 0.0);
    Matrix(int row, int col, double mtx[]);
    Matrix(int row,double element);
    printf(); //打印一个矩阵全部元素
    printf(int i, int j); //打印一个矩阵的第i行第j列的元素
    mix(int i, int j,int element); //修改第i行第j列的元素为elemen
    double get(int i, int j); //得到第i行第j列的元素
    //检查矩阵前indexnum项是否有元素index_tobechecked
    bool CheckIndex(int index_tobechecked,int indexnum);
    //删除矩阵前deletenum行
    Matrix MatrixDeleteRows(int deletenum);
    //删除矩阵从第order行开始后deletenum行
    Matrix MatrixDeleteRows(int order,int deletenum);
    //删除矩阵前deletenum列
    Matrix MatrixDeleteColumns(int deletenum);
    //删除矩阵从第order列开始后deletenum列
    Matrix MatrixDeleteColumns(int order, int deletenum);
    //两个矩阵求和
    Matrix SumMatrix( Matrix &obj1, Matrix &obj2);
    //两个矩阵求和或者积
    Matrix(Matrix &obj1, Matrix &obj2,char a);
    //求一个矩阵的*-1
    Matrix op_mat();
    //求一个矩阵里的小矩阵
    Matrix get_mat(int row_s,int row_b,int col_s,int col_b);
    //修改一个矩阵里的小矩阵
     Matrix mix_mat(int row_s,int row_b,int col_s,int col_b,double element[]);
     // 矩阵的转置
     Matrix trv( Matrix &A);
     //逆矩阵
     Matrix inv(Matrix A);
    int get_row();
    int get_col();
    int get_n();
};

#endif // MATRIX_H

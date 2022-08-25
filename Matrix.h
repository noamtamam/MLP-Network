// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
	int rows, cols;
} matrix_dims;

class Matrix{
private:
    float* _data;
    int _rows;
    int _cols;
    int _size;

    int i_j(int const i, const int j) const
    {
        return (i*_cols) +j;
    }
public:
    // constructor
    Matrix(int row, int cols);
    // default constructor
    Matrix();
    // copy constructor
    Matrix(const Matrix& other);
    //destructor
    ~Matrix();

    int get_rows()const;
    int get_cols()const;
    Matrix& transpose();
    Matrix& vectorize();
    void plain_print()const;
    Matrix dot(Matrix m);
    float norm()const;
    // operators:
    Matrix operator+(const Matrix& m) const;
    Matrix& operator= (const Matrix& m);
    Matrix operator*(const Matrix& m) const;
    Matrix operator*(float c) const;
    friend Matrix operator*(float c, const Matrix& m);
    Matrix& operator+=(const Matrix& m);
    float& operator()(int i, int j);
    float operator()(int i, int j) const;
    float& operator[](int idx);
    float operator[](int idx)const;
    friend std::ostream& operator <<(std::ostream& os, const Matrix& m);
    friend std::istream& operator >>(std::istream& is, Matrix& m);


};

#endif //MATRIX_H
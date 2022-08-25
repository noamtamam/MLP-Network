#include <algorithm>
#include "Matrix.h"
#include <iostream>
#include <math.h>
#define THRESHOLD 0.1

Matrix::Matrix()
{
    _data = new float [1];
    _data[0] = 0;
    _rows = 1;
    _cols = 1;
    _size = 1;
}
Matrix::Matrix(int rows, int cols)
{
  if(rows <= 0 || cols <= 0 )
  {
    throw std::length_error("legnth error in constructor!");
  }
    _size = rows *cols;
    _data = new float [_size];
    _rows = rows;
    _cols = cols;
    for(int i =0; i<_size; i++)
    {
      _data[i] = 0;
    }
}
/**
 * gets an matrix and copy the value of it to the matrix
 * @param other
 */
Matrix::Matrix(const Matrix& other)
{
    _rows = other._rows;
    _cols = other._cols;
    _size = _rows * _cols;
//    delete[] _data;
    _data = new float [_size];
    std::copy(other._data, other._data + other._size, _data);
}

Matrix::~Matrix()
{
    delete[] _data;
}

int Matrix::get_rows()const
{
    return _rows;
}
 int Matrix::get_cols() const
 {
     return _cols;
 }
/**
 * switch the data from rows to cols
 * @return
 */
Matrix& Matrix::transpose()
{
    float* temp = new float [_size];
    for(int i = 0; i <_rows; i++)
    {
        for(int j=0; j<_cols; j++)
        {
        temp[j*_rows +i] = _data[i*_cols +j];
        }
    }
    std::copy(temp, temp + _size, _data);
    int old_row = _rows;
    _rows = _cols;
    _cols = old_row;
    delete[](temp);
  return *this;
}
/**
 * switch all data for rols to cols to one col
 * @return
 */
Matrix& Matrix::vectorize()
{
    _rows = _size;
    _cols = 1;
    return *this;
}
void Matrix::plain_print()const
{
    for( int i =0; i<_rows; i++)
    {
        for(int j=0; j<_cols; j++)
        {
            std::cout <<_data[i_j(i, j)]<<" ";
        }
        std::cout <<std::endl;
    }
  std::cout <<std::endl;
}
/**
 * multiply the matrix with another matrix by each cordinate
 * @param m
 * @return a new matrix
 */
Matrix Matrix::dot(Matrix m)
{
    if(_rows != m._rows || _cols != m._cols)
    {
        throw std::length_error("length error dot!");
    }
    Matrix new_mat(m._rows, m._cols);
    for(int i =0; i<m._size; i++)
    {
        new_mat._data[i] = _data[i]*m._data[i];
    }
    return new_mat;
}

float Matrix::norm()const
{
    float sum =0;
    for(int i =0; i<_size; i++)
    {
        sum += pow(_data[i], 2);
    }
    return sqrt(sum);
}

Matrix Matrix::operator+(const Matrix& m) const
{
    if(_rows != m._rows || _cols != m._cols)
    {
        throw std::length_error("length error! +");
    }
    Matrix new_mat = Matrix(_rows, _cols);
    for(int i =0; i<_size; i++)
    {
        new_mat._data[i] = _data[i] + m._data[i];
    }
    return new_mat;
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if(this == &m)
    {
        return *this;
    }
    _size = m._size;
    _rows = m._rows;
    _cols = m._cols;
    delete[] _data;
    _data = new float [_size];
    std::copy(m._data, m._data+_size, _data);
    return *this;
}
/**
 * multiply a matrix and returns the result, by linear algebra multiply
 * @param m
 * @return matric result
 */
Matrix Matrix::operator*(const Matrix &m) const
{
    if(_cols != m._rows)
    {
        throw std::length_error("length error * operator!");
    }
    Matrix new_mat = Matrix(_rows, m._cols);
    for(int i=0; i<_rows; i++)
    {
        for(int j =0; j <m._cols; j++)
        {
            float sum = 0.0;
            for(int k=0; k<m._rows; k++)
            {
                sum+= _data[i_j(i,k)] * m._data[k*m._cols + j];
            }
            new_mat._data[i*m._cols +j] = sum;
        }
    }
    return new_mat;
}

Matrix Matrix::operator*( float c) const
{
    Matrix new_mat = Matrix(_rows, _cols);
    for(int i =0; i<_size; i++)
    {
        new_mat._data[i] = _data[i]*c;
    }
    return new_mat;
}

Matrix operator*(float c, const Matrix& m)
{
    Matrix new_mat = Matrix(m._rows, m._cols);
    for(int i =0; i<m._size; i++)
    {
        new_mat._data[i] = c*m._data[i];
    }
    return new_mat;
}
Matrix& Matrix::operator+=(const Matrix& m)
{
    if(_rows != m._rows || _cols != m._cols)
    {
        throw std::length_error("length error +=!");
    }
    for(int i =0; i<_size; i++)
    {
        _data[i] += m._data[i];
    }
    return *this;
}
/**
 * get the value in row i and col j
 * @param i
 * @param j
 * @return float value reference
 */
float& Matrix::operator()(int i, int j)
{
  if(i < 0 || j <0)
  {
    throw std::out_of_range("out of range! ()");
  }
    int id = i_j(i, j);
    if(id >= _size)
    {
        throw std::out_of_range("out of range! ()");
    }
    return _data[id];
}
/**
 * get the value in row i and col j
 * @param i
 * @param j
 * @return float value
 */
float Matrix::operator()(int i, int j) const
{
  int id = i_j(i, j);
  if(id >= _size)
  {
    throw std::out_of_range("out of range! ()");
  }
  return _data[id];
}
/**
 * get the value in place idx
 * @param idx
 * @return float reference
 */
float& Matrix::operator[](int idx)
{
  if(idx <0)
  {
    throw std::out_of_range("out of range! []");
  }
    if(idx >= _size)
    {
        throw std::out_of_range("out of range! [] here");
    }

    return _data[idx];
}
/**
 * get the value in place idx
 * @param idx
 * @return float
 */
float Matrix::operator[](int idx) const
{
  if(idx <0)
  {
    throw std::out_of_range("out of range! []");
  }
  if(idx >= _size)
  {
    throw std::out_of_range("out of range! [] ");
  }

  return _data[idx];
}
/**
 * print matrix function
 */
std::ostream& operator << (std::ostream& os, const Matrix& m)
{
    for(int i = 0; i<m._rows; i++)
    {
        for(int j=0; j<m._cols; j++)
        {
            if (m._data[i*m._rows+j] > THRESHOLD)
            {
                os << "**";
            }
            else
            {
                os << "  ";
            }
        }
        os << std::endl;
    }
    return os;
}
std::istream& operator >>(std::istream& is, Matrix& m)
{
    is.seekg(0,std::ios_base::end);
    long int binary_size = (long int) m._size*sizeof(float);
    if(is.tellg()!= binary_size)
    {
        throw std::runtime_error("run time error");
    }
    is.seekg(0,std::ios_base::beg);
    if(!is.read((char*)m._data, binary_size))
    {
        throw std::runtime_error("run time error");
    }
    return is;



}
#include "Activation.h"
#include "Matrix.h"
#include <math.h>

/**
 * gets a matrix and switch with zero all negative values
 * @param m
 * @return
 */
    Matrix activation::relu(Matrix& m)
    {
        int size = m.get_cols()*m.get_rows();
        Matrix new_mat(m.get_rows(), m.get_cols());
        for(int i=0; i<size; i++)
        {
            if(m[i]<0)
            {
                new_mat[i] =0;
            }
            else
            {
                new_mat[i] = m[i];
            }
        }
      return new_mat;
    }
    /**
     * operate softmax function
     * @param m
     * @return
     */
    Matrix activation::softmax(Matrix& m)
    {
        Matrix new_mat(m.get_rows(), m.get_cols());
        float sum = 0.0;
        int rows = m.get_rows();
        int cols = m.get_cols();
        int size = cols * rows;
        for(int i=0; i<size; i++)
        {
          float value = m[i];
          sum+= std::exp(value);
          new_mat[i] = std::exp(value);
        }
        sum = 1 /sum;
        new_mat = sum * new_mat;
        return new_mat;
    }




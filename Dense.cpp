#include "Dense.h"

act_fun Dense::get_activation() const
{
    return _act_func;
}

Matrix Dense::get_bias() const
{
    return _b;
}

Matrix Dense::get_weights() const
{
    return _w;
}
/**
 * operate the activation function on a given matrix
 * @param m
 * @return
 */
Matrix Dense::operator()(const Matrix& m)const
{
    Matrix new_mat(m.get_rows(),m.get_cols());
    new_mat = (_w*m);
    new_mat+= _b;
    new_mat = _act_func(new_mat);
    return new_mat;

}
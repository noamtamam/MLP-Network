#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"
class Dense{
private:
    Matrix _w;
    Matrix _b;
    act_fun _act_func;
public:
    Dense(Matrix w, Matrix b, act_fun f)
    {
        _w = w;
        _b = b;
        _act_func = f;
    }
    Matrix get_weights()const;
    Matrix get_bias()const;
    act_fun get_activation()const;
    Matrix operator()(const Matrix&)const;

};


#endif //DENSE_H

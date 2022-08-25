#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H
typedef Matrix (*act_fun) (Matrix&);
namespace activation
{
    Matrix relu(Matrix& m);
    Matrix softmax(Matrix& m);
}
#endif //ACTIVATION_H
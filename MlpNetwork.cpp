#include "MlpNetwork.h"
#define M_SIZE 10
MlpNetwork::MlpNetwork(Matrix *w, Matrix *b)
: _d1 (Dense(w[0], b[0],&(activation::relu))),
_d2 (Dense(w[1], b[1],&(activation::relu))),
_d3 (Dense(w[2], b[2],&(activation::relu))),
_d4 (Dense(w[3], b[3],&(activation::softmax))){}

digit MlpNetwork::get_max (Matrix &m) const
{
  unsigned int idx =0;
  float max =0;
  for(unsigned int i=0; i<M_SIZE;i++)
  {
    if (m[i]>max)
    {
      max = m[i];
      idx = i;
    }
  }
  digit d{idx, m[idx]};
  return d;
}
/**
 * operate all function in dense on the input matrix
 * @param input
 * @return
 */
digit MlpNetwork::operator()(const Matrix & input) const
{
  Matrix r1 = _d1(input);
  Matrix r2 = _d2(r1);
  Matrix r3 = _d3(r2);
  Matrix r4 = _d4(r3);
  digit d = get_max (r4);
  return d;



}

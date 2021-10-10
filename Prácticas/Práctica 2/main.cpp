#include <iostream>

#include "rational_matrix_t.hpp"

using namespace std;

int main(void)
{
  rational_matrix_t A(3, 2);

  A(1, 1) = rational_t(8, 5);
  A(1, 2) = rational_t(4, 2);
  A(2, 1) = rational_t(1, 2);
  A(2, 2) = rational_t(6, 3);
  A(3, 1) = rational_t(4, 3);
  A(3, 2) = rational_t(3, 2);

  cout << A << endl;

  rational_matrix_t B(2, 4);

  B(1, 1) = rational_t(8, 3);
  B(1, 2) = rational_t(5, 2);
  B(1, 3) = rational_t(1, 3);
  B(1, 4) = rational_t(7, 3);
  B(2, 1) = rational_t(4, 2);
  B(2, 2) = rational_t(5, 2);
  B(2, 3) = rational_t(4, 3);
  B(2, 4) = rational_t(3, 2);

  cout << "*" << endl
       << endl;
  cout << B << endl;

  rational_matrix_t C;

  //  C.multiply(A,B);

  C = A * B;

  cout << "=" << endl
       << endl;
  cout << C << endl;

  cout << "modificacion: " << endl;

  rational_matrix_t E(2, 3);
  E(1, 1) = rational_t(8, 3);
  E(1, 2) = rational_t(1, 1);
  E(1, 3) = rational_t(0, 1);
  E(2, 1) = rational_t(1, 1);
  E(2, 2) = rational_t(4, 1);
  E(2, 3) = rational_t(1, 1);

  E.suma_fil();

  return 0;
}

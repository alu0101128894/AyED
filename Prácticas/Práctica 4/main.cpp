#include <cstdio>
#include <iostream>

#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "sparse_matrix_t.hpp"

#define MAX_DIM 5

using namespace std;

int main(void)
{
	matrix_t<rational_t> A(MAX_DIM, MAX_DIM);

	for (int i = 1; i <= MAX_DIM; i++)
		A(i, i) = rational_t(1, i + 1);

	A(1, 2) = rational_t(5);
	A(3, 4) = rational_t(3, 2);
	A(4, 1) = rational_t(7, 2);

	A.write(cout);
	cout << endl;

	{
		sparse_matrix_t SA(A, 1E-2, COL_CONF);
		SA.write(cout);
		cout << endl;
	}

	{
		sparse_matrix_t SA(A, 1E-2, ROW_CONF);
		SA.write(cout);
		cout << endl;
	}

	matrix_t<rational_t> C(MAX_DIM, MAX_DIM);
	//sparse_matrix_t SA(A, 1E-2, ROW_CONF);
	sparse_matrix_t SA(A, 1E-2, COL_CONF);
	SA.multiply(A, C);
	C.write(cout);
	cout << endl;

	SA.nulos(C);

	return 0;
}

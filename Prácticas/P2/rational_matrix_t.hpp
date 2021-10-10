#pragma once

#include "matrix_t.hpp"
#include "rational_t.hpp"

typedef matrix_t<rational_t> rational_matrix_t;

ostream &operator<<(ostream &os, const rational_matrix_t &M)
{
	M.write(os);
	return os;
}

rational_matrix_t operator*(const rational_matrix_t &A, const rational_matrix_t &B)
{
	rational_matrix_t C;
	C.multiply(A, B);
	return C;
}

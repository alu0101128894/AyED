#include <cstdio>
#include <iostream>

using namespace std;

#include "bitset.hpp"
using namespace AED;

int main(void)
{
	cout << sizeof(block_t) << endl;
	
	bitset_t A;

  A.insert(1);
	A.insert(5);
	A.insert(9);
	A.insert(25);

	cout << "A.first_item: " << A.first_item() << endl;
	cout << "A.last_item: " << A.last_item()<< endl;

	cout << "A: ";
	A.write(cout);
	cout << endl;

	bitset_t B;

	B.insert(A);
	B.insert(31);
	B.insert(21);
	B.remove(9);

  cout << "B: ";
	B.write(cout);
	cout << endl;
	cout << "B.first_item: " << B.first_item() << endl;
	cout << "B.last_item: " << B.last_item()<< endl;

	bitset_t C;
	
	B.set_intersec(A,C);

  cout << "C: ";
	C.write(cout);
	cout << endl;
	

}

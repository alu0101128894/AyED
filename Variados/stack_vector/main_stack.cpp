#include <cstdio>
#include "stack_v_t.hpp"
#include "stack_l_t.hpp"


int main(void)
{
	
	AED::stack_v_t<char> pila_vector;

	for(int i = 0; i < 10; i++){

		pila_vector.push('a' + i);

		pila_vector.write(cout);
		cout << endl;
	}

	cout << endl;

	while(!pila_vector.empty()){
		
		pila_vector.pop();

		pila_vector.write(cout);
		cout << endl;
	}


	AED::stack_l_t<char> pila_lista;

	for(int i = 0; i < 10; i++){

		pila_lista.push('a' + i);

		pila_lista.write(cout);
		cout << endl;
	}

	cout << endl;

	while(!pila_lista.empty()){
		
		pila_lista.pop();

		pila_lista.write(cout);
		cout << endl;
	}
}

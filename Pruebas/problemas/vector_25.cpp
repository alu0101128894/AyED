#include <iostream>
#include <cstdio>

using namespace std;

class vector_t{
	private:
		int* v_;
		int sz_;
	public:
		vector_t(int sz):
			v_(NULL);
			sz_(sz);
			{ v_=new int [sz];
			}
		~vector_t (void)
			{	delete [] v_;
		}

		int get_sz(void) const
		{ return sz_;
		}
		int at(int pos) const
			{	return v_[pos];
		}
		int& at(int pos) //devuelve una referencia a la posicion del vector.devuelve el acceso a un aposicion determinada, podemos modificar el valor, es como un set
		{ return v_[pos];
		}
		void write(ostream& os) const//ostream es un tipo de dato que se refieren a mandar algo a la salida (cout es un caso particular de ostream, cerr tambien, salida estandar de error)
		{for (int i=0;i<sz;i++)
			{os<<v_[i]<<" ";
			}
			os<<endl;
		}
};

int main(void){
	vector_t a(5);
	vector_t b(10);
	for(int i=0;i<a.get_sz();i++) a.at(i)=i;
	for(int i=0;i<b.get_sz();i++) b.at(i)=10+i;
	const vector_t& c=a;
	c.write(cout);
	b.at(3)=18;
}

//con el nuevo vector que le pasamos los indices:
//
//atributos:
// int i_;
// int d_;
//
//
// public:
// vector_t(int i, int d);
// 	v_(NULL);
// 	i_(i);d_(d);
// 	{v_=new int[get_sz];
//      }
// int get_sz(void) const
// {return d_-i_+1;
// }
//
// int at(int pos) const
// { return v_[pos-i_]
// }
//
// int& at(int pos)
// {return v_[pos-i_];
// }
//
// es otro caso de abstraccion, el usuario cree que trabaja entre -3 y 3 pero en realidad es 0 y 6.

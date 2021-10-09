#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class complex_t { //el _t para saber que es un tipo de dato
	private: 
		double re_;  // si acaba en _ es un atributo de la clase
		double im_;

	public:
		//el constructor:cada vez que se declara el objeto en el main ej complex_t b(1,2) o complex_t a; el constructor le da valores iniciales al registro de la clase( parte real e imaginaria)
		complex_t(void):
		       re_(0),
	       	       im_(0){}	       //constructor por defecto que no se le pasan parametros. si no le pasamos parametros, por defecto los parametros tendran valor 0, si lo queremos de otra forma, ponemos dos puntos y los atributos con los valores que queremos.

		//ahora un constructor que le pase dos parametros
		complex_t(double re, double im):
			re_(re),
			im_(im){}
		//destructor: se ejecuta cunado deja de existir el objeto, solo hay 1, por ejemplo para eliminar memoria dinamica
		~complex_t(void){}

		double get_re(void) const {return re_;}
		double get_im(void) const {return im_;}
		//el conts es para no modificar el contenido
		void set_re(double re) {re_=re;}
		void set_im(double im) {im_=im;}

		double get_mod(void) const{return sqrt(re_*re_+im_*im_);}
		double get_phase(void) const {return atan2(im_/re_);}
		void suma(const complex_t& a, const complex_t& b){
				re_=a.re_+b.re_;
				im_=a.im_+b.im_;
		}//si estamos dentro de un metodo de la clase no hace falta usar los get y set
};

 }

}

int main (void){
	complex_t a;
	complex_t b(1,2);
	complex_c;

	a.set_re(4);
	a.set_im(6);
	c.suma(a,b);

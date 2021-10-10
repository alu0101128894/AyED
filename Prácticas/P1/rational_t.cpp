#include "rational_t.hpp"
#include "cmath"
//implementacion de los metodos:
rational_t::rational_t(const int n, const int d) //constructor, crea el numero racional con n en el numerador y d en el denominador, ademas comprueba que el numerador sea distinto de 0.
{
  num_ = n, den_ = d;
}

double rational_t::value() const //devuelve un double que es la division del numerador con el denominador
{
  return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const //devuelve el racional
{
  return rational_t((-1) * get_num(), get_den());
}

rational_t rational_t::reciprocal() const //metodo que devuelve el inverso del racional, el denomiador como numerador y viceversa
{
  return rational_t(get_den(), get_num());
}

///////////////////////////////FASE II////////////////////////////

bool rational_t::equal(const rational_t &r, const double precision) const //resta el valor del invocante con el que le pasamos y compara el valor absoluto que sea menor o igual que la tolerancia que asignamos previamente.
{
  if (fabs(value() - r.value()) <= precision)
    return true;
  else
    return false;
}

bool rational_t::greater(const rational_t &r, const double precision) const //igual que equal pero que el invocante sea mayor que el racinal que le pasamos como argumento
{
  if (fabs(value() - r.value()) > precision)
    return true;
  else
    return false;
}

bool rational_t::less(const rational_t &r, const double precision) const //el contrario que greater
{
  if (fabs(value() - r.value()) < ((-1) * precision))
    return true; // if (fabs(r.value()-value())>precision) return true;
  else
    return false;
}

////////////////////////////////FASE IV ///////////////////////////

rational_t rational_t::add(const rational_t &r) //suma como se explica en https://es.wikipedia.org/wiki/N%C3%BAmero_racional
{
  int new_num = (num_ * r.den_) + (den_ * r.num_);
  int new_den = den_ * r.den_;
  return rational_t(new_num, new_den);
}

rational_t rational_t::substract(const rational_t &r) //la resta es la inversa de la suma, por lo que multiplicamos por -1 y llamamos al metodo suma
{
  return rational_t(add(r.opposite()));
}

rational_t rational_t::multiply(const rational_t r) // simple multiplicacion de racionales (https://es.wikipedia.org/wiki/N%C3%BAmero_racional)
{
  int new_num = num_ * r.num_;
  int new_den = den_ * r.den_;
  return rational_t(new_num, new_den);
}

rational_t rational_t::divide(const rational_t &r) //viceversa que multiplicacion
{
  int new_num = num_ * r.den_;
  int new_den = den_ * r.num_;
  return rational_t(new_num, new_den);
}

void rational_t::write(ostream &os) const //imprime por pantalla, es un metodo de la libreria <iostream>, obtiene los atributos con el metodo get, lo imprime por pantalla y ademas tambien imprime el resultado del metodo value()
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream &is) //lee por teclado, primero el numerador y lo guarda en num_ y lo mismos para el denominador y comprueba que no sea 0.
{
  cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}
bool rational_t::check_rational()
{
  if (den_ == 0 && num_ != 0)
    return true;
  return false;
}

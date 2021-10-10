
#include <iostream>
#include <cmath>
#include "rational_t.hpp"

using namespace std;

///////////// FASE III: función de búsqueda
bool search(const rational_t *v, const int n, const rational_t &x)
{
  //tengo que comparar el vector dinamico de racionales con el racional que le pasamos usando la funcion equal, no hace falta llamar al metodo value porque el ecual ya lo invoca
  int i = 0;
  while ((i < n))
  { //
    if (v[i].equal(x))
      return true;
    i++;
  }
  return false;
}

int main()
{
  rational_t a(7, 4), b(1, 3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  cout << "Opuesto de a: ";
  a.opposite().write();
  cout << "Recíproco de b: ";
  b.reciprocal().write();

  // FASE III: ejemplo
  int n;
  cout << "Introduce n: ";
  cin >> n;
  rational_t *v = new rational_t[n];
  if (v != NULL)
  {
    for (int i = 0; i < n; i++)
    {
      v[i] = rational_t(1, pow(2, i));
      v[i].write();
    }

    rational_t x(1, pow(2, 3));
    bool b = search(v, n, x);
    cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;

    delete[] v;
  }
  else
  {
    cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
    return 1;
  }

  cout << "a";
  a.write();
  cout << "b";
  b.write();
  // FASE IV
  cout << "a + b: ";
  a.add(b).write();

  cout << "b - a: ";
  b.substract(a).write();

  cout << "testing /////////////////////" << endl;
  a.write();
  b.write();

  cout << "a * b: ";
  a.multiply(b).write();

  cout << "multiplier done ////////////////////////" << endl;

  a.write();
  b.write();

  cout << "a / b: ";
  a.divide(b).write();

  // MODIFICACION//

  cout << "modificacion" << endl;
  if (b.check_rational())
    cout << "infinito" << endl;
  return 0;
}

#pragma once //segun wikipedia sirve para que el codigo fuente que se invoque sea incluido una unica vez

#include <iostream>
#include <cassert>
#include <cmath>

#define EPSILON 1e-6

using namespace std;

//declaracion de los metodos, algunos implementados y otros no

class rational_t //definicion de la clase; tipo de dato (objeto) con nombre rational_t y dos atributos
{
  int num_, den_; //dos atributos de la clase

public:                                     //metodos de la clase
  rational_t(const int = 0, const int = 1); //constructor; inicializa con el numerador a valor 0 y denominador a valor 1 por defecto, si no le pasamos parametros coje estos.
  ~rational_t() {}                          //destructor de la clase

  int get_num() const //metodo para devolver el numerador
  {
    return num_;
  }

  int get_den() const //metodo para devolver el denominador
  {
    return den_;
  }

  void set_num(const int n) //metodo para asignar el valor al numerador, const porque no se modifica el parametro dentro de la funcion
  {
    num_ = n;
  }

  void set_den(const int d) //metodo para asignar el valor al denominador y además comprueba (assert) que no sea 0.
  {
    assert(d != 0), den_ = d;
  }

  double value(void) const;          //declaracion de un metodo 'value' que no le pasamos parametros y devuelve un tipo double
  rational_t opposite(void) const;   //declaracion de un metodo 'opposite' que no le pasamos parametro y no modifica el contenido(atributos) y devuelve un objeto
  rational_t reciprocal(void) const; //igual que el anterior

  // FASE II
  bool equal(const rational_t &r, const double precision = EPSILON) const;   //declaracion de un metodo 'equal' que compara dos objetos de la misma clase con un umbral de error y devuelve true si son iguales, false por el contrario
  bool greater(const rational_t &r, const double precision = EPSILON) const; //declaracion de un metodo 'greater' que devuelve true si el primero es mas grande que el segundo
  bool less(const rational_t &r, const double precision = EPSILON) const;    //declaracion de un metodo 'less' que funciona al contrario que greater

  // FASE IV
  rational_t add(const rational_t &);       //declaracion de un metodo 'add' que suma dos objetos de la misma clase
  rational_t substract(const rational_t &); //declaracion de un metodo 'substract' que resta dos objetos de la misma clase
  rational_t multiply(const rational_t);    //igual que 'add' pero multiplicando
  rational_t divide(const rational_t &);    //igual que 'add' pero dividiendo

  void write(ostream &os = cout) const; //metodo llamado 'write' que imprime el valor de los atributos del objeto
  void read(istream &is = cin);         //metodo llamado 'read' que escribe el valor por teclado en los atributos del objeto

  //MODIFICACION//

  bool check_rational(); //comprueba que no sea infinito
};

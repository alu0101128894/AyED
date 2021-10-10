#pragma once

#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "pair_t.hpp"
#include "rational_t.hpp"

enum
{
  COL_CONF,
  ROW_CONF
};

typedef pair_t<rational_t> p_rational_t;
typedef dll_node_t<p_rational_t> node_rational_t;
typedef dll_t<p_rational_t> list_rational_t;

class sparse_matrix_t
{
private:
  const int m_; //numero de filas originales
  const int n_; //numero de columnas originales
  vector_t<dll_t<pair_t<rational_t>>> v_;

  const int conf_;

public:
  sparse_matrix_t(const matrix_t<rational_t> &A, double eps, int conf) : m_(A.get_m()),
                                                                         n_(A.get_n()),
                                                                         v_(), //no se si es por filas o columnas, asi que lo pongo a 0
                                                                         conf_(conf)
  {
    if (conf_ == COL_CONF)
    {
      v_.resize(n_);
      //recorremos la columna j
      for (int j = 1; j <= n_; j++)
        for (int i = 1; i <= m_; i++)
          if (A(i, j).get_num() != 0)
            v_[j - 1].insert_tail(new dll_node_t<pair_t<rational_t>>(pair_t<rational_t>(i, A(i, j))));
    }
    else
    {
      v_.resize(m_);
      for (int i = 1; i <= m_; i++)
        for (int j = 1; j <= n_; j++)
          if (A(i, j).get_num() != 0)
            v_[i - 1].insert_tail(new dll_node_t<pair_t<rational_t>>(pair_t<rational_t>(j, A(i, j))));
    }
  }

  ~sparse_matrix_t(void) {}

  void write(ostream &os) const
  {
    for (int i = 0; i < v_.size(); i++)
    {
      v_[i].write(os);
      os << endl;
    }
    os << endl;
  }

  //para la multiplicacion tiene que estar en formato fila, es mas facil

  void multiply(const matrix_t<rational_t> &A, matrix_t<rational_t> &B)
  {
    if (n_ == A.get_m())
    {
      B.resize(m_, A.get_n());
      for (int i = 1; i <= v_.size(); i++)
      {
        for (int j = 1; j <= A.get_n(); j++)
        {
          node_rational_t *aux = v_[i - 1].get_tail();
          rational_t prod = 0;
          while (aux)
          {
            prod = prod + aux->get_data().get_val() * A(aux->get_data().get_inx(), j);
            aux = aux->get_next();
          }
          B(i, j) = prod;
        }
      }
    }
    else
    {
      cout << "Error en la multiplicacion" << endl;
    }
  }

  void nulos(const matrix_t<rational_t> &A)
  {
    int counter = 0;
    node_rational_t *aux = v_[0].get_head();
    while (aux)
    {
      counter++;
      aux = aux->get_next();
    }
    cout << "Elementos no nulos: " << counter << endl;
  }
};

ostream &operator<<(ostream &os, const pair_t<rational_t> &a)
{
  a.write(os);
  return os;
}

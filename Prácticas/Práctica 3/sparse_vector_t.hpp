#pragma once

#include <random>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "list_pair_t.hpp"
#include "vector_t.hpp"
#include <cmath>

#include <iostream>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

namespace AED
{

  class sparse_vector_t
  {
  private:
    list_pair_t v_;
    int sz_;

  public:
    sparse_vector_t(const vector_t<double> &v, double eps) : v_(),
                                                             sz_(v.size())
    {
      for (int i = v.size() - 1; i >= 0; i--)
      {
        if (is_not_zero(v[i], eps))
        {
          v_.insert_head(new node_pair_t(spair_t(i, v[i])));
        }
      }
    }

    ~sparse_vector_t(void) {}

    ostream &write(ostream &os) const
    {

      os << "[ " << setw(7) << sz_ << " ";
      v_.write(os);
      os << " ]";

      return os;
    }

    double sparse_grade(void) const
    {
      assert(v_.head() && sz_);
      const node_pair_t *aux;
      aux = v_.head();
      double sparce_sz = 0.0;
      while (aux)
      {
        aux = aux->get_next();
        sparce_sz++;
      }
      return sparce_sz / sz_;
    }

    void sparse_even(void) const
    {
      const node_pair_t *aux;
      aux = v_.head();
      int even = 0;
      while (aux)
      {
        if ((aux->get_data().get_inx() % 2) == 0)
        {
          even++;
          // aux=aux->get_next();
        } //else{
          // aux=aux->get_next();
          // }
        aux = aux->get_next();
      }

      cout << even << endl;
    }

    double scal_prod(const vector_t<double> &b) const
    {

      assert(!v_.empty());
      const node_pair_t *aux;
      double prod = 0;
      aux = v_.head();
      while (aux)
      {
        prod = prod + aux->get_data().get_val() * b[aux->get_data().get_inx()];
        aux = aux->get_next();
      }

      return prod;
    }

    double disorder_scal_prod(const sparse_vector_t &b) const
    {

      assert(!v_.empty() && !b.v_.empty());
      double dot = 0;
      const node_pair_t *aux;
      const node_pair_t *aux2;
      aux = v_.head();
      aux2 = b.v_.head();
      while (aux)
      {
        if (aux->get_data().get_inx() == aux2->get_data().get_inx())
        {
          dot = dot + aux->get_data().get_val() * aux2->get_data().get_val();
          aux = aux->get_next();
          aux2 = aux2->get_next();
        }
        else if (aux->get_data().get_inx() != aux2->get_data().get_inx())
        {
          aux2 = b.v_.head();
          while (aux2)
          {
            if (aux2->get_data().get_inx() == aux->get_data().get_inx())
            {
              dot = dot + aux->get_data().get_val() * aux2->get_data().get_val();
              aux = aux->get_next();
              break;
            }
            else
            {
              aux2 = aux2->get_next();
            }
          }
          aux = aux->get_next();
        }
      }

      return dot;
    }

    void sparse_order(void) const
    {

      node_pair_t *aux;
      aux = v_.head();
      int counter = 0;
      while (aux)
      {
        aux = aux->get_next();
        counter++;
      }

      int a[counter];
      aux = v_.head();

      while (aux)
      {
        a[aux->get_data().get_inx()] = aux->get_data().get_val();
        aux = aux->get_next();
      }

      //  sparse_vector_t b(a, 1E-3); // ¿?¿?
    }

    double scal_prod(const sparse_vector_t &b) const
    {

      assert(!v_.empty() && !b.v_.empty());
      const node_pair_t *aux;
      const node_pair_t *aux2;
      aux = v_.head();
      aux2 = b.v_.head();
      double dot = 0;

      while (aux && aux2)
      {
        if (aux->get_data().get_inx() == aux2->get_data().get_inx())
        {
          dot = dot + aux->get_data().get_val() * aux2->get_data().get_val();
          aux = aux->get_next();
          aux2 = aux2->get_next();
        }
        else if (aux->get_data().get_inx() > aux2->get_data().get_inx())
        {
          aux2 = aux2->get_next();
        }
        else if (aux->get_data().get_inx() < aux2->get_data().get_inx())
        {
          aux = aux->get_next();
        }
      }
      return dot;
    }

    void array_random(const vector_t<double> &b, double eps)
    {
      vector<int> a;
      srand(unsigned(time(0)));
      for (int i = 0; i <= b.size() - 1; i++)
        a.push_back(i);

      random_shuffle(a.begin(), a.end());

      for (int i = 0; i <= a.size() - 1; i++)
      {
        if (is_not_zero(b[a[i]], eps))
        {
          v_.insert_head(new node_pair_t(spair_t(a[i], b[a[i]])));
        }
      }
    }

  private:
    bool is_not_zero(double val, double eps) { return fabs(val) > eps; }
  };

}

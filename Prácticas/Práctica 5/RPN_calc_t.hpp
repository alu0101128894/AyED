#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

namespace AED
{

  template <class T>
  class RPN_calc_t
  {
  private:
    T stack_;

  public:
    RPN_calc_t() {}

    ~RPN_calc_t() {}

    const int compute(istream &is)
    {

      int operando;
      char operador;
      int counter = 0;

      while (!is.eof())
      {

        is >> ws;
        int c = is.peek();

        if (!cin.eof())
        {

          if (isdigit(c))
          {
            is >> operando;
            stack_.push(operando);
          }
          else
          {
            is >> operador;
            operate(operador);
            counter++;
          }
        }
      }

      const int result = stack_.top();
      stack_.pop();
      cout << counter << endl;
      return result;
    }

  private:
    void operate(char operador)
    {

      int op_r = stack_.top();
      stack_.pop();
      int op_l = stack_.top();
      stack_.pop();

      if (operador == 0x2B)
      {
        stack_.push(op_l + op_r);
      }

      if (operador == 0x2D)
      {
        stack_.push(op_l - op_r);
      }

      if (operador == 0x2A)
      {
        stack_.push(op_l * op_r);
      }

      if (operador == 0x2F)
      {

        assert(op_r != 0);
        stack_.push(op_l / op_r);
      }

      if (operador == '^')
      {
        stack_.push(pow(op_l, op_r));
      }

      if (operador == 'r')
      {
        int op = stack_.top();
        stack_.pop();
        stack_.push(sqrt(op));
      }

      if (operador == 'l')
      {
        int op = stack_.top();
        stack_.pop();
        stack_.push(log2(op));
      }

      if (operador == 'c')
      {
        int op = stack_.top();
        stack_.pop();
        stack_.push(pow(op, 2));
      }
    }
  };

}

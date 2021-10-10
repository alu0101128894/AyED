#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

template <class T>
class matrix_t
{
private:
    int m_;
    int n_;

    vector_t<T> v_;

public:
    matrix_t(void) : m_(0),
                     n_(0),
                     v_() {}

    matrix_t(int m, int n) : m_(m),
                             n_(n),
                             v_(m * n) {}

    ~matrix_t(void)
    {
    }

    void resize(int m, int n)
    {
        v_.resize(m * n);
        m_ = m;
        n_ = n;
    }

    T &at(int i, int j)
    {
        return v_.at(pos(i, j));
    }

    const T &at(int i, int j) const
    {
        return v_.at(pos(i, j));
    }

    T &operator()(int i, int j)
    {
        return at(i, j);
    }

    const T &operator()(int i, int j) const
    {
        return at(i, j);
    }

    int get_m(void) const
    {
        return m_;
    }

    int get_n(void) const
    {
        return n_;
    }

    void write(ostream &os) const
    {

        for (int i = 1; i <= m_; i++)
        {
            for (int j = 1; j <= n_; j++)
                os << at(i, j) << "  ";

            os << endl;
        }
    }

    void multiply(const matrix_t &A, const matrix_t &B)
    {
        assert(A.get_n() == B.get_m());

        resize(A.get_m(), B.get_n());

        for (int i = 1; i <= m_; i++)
            for (int j = 1; j <= n_; j++)
            {
                T aux;
                for (int k = 1; k <= A.get_n(); k++)
                    aux = aux + A.at(i, k) * B.at(k, j);

                at(i, j) = aux;
            }
    }

    void suma_fil(void)
    {
        T suma = 0;
        for (int i = 0; i <= n_; i++)
        {
            suma = suma + at(m_, i);
        }
        cout << suma << endl;
    }

private:
    int pos(int i, int j) const
    {
        return (i - 1) * n_ + j - 1;
    }
};

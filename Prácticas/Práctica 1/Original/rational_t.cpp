#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

double rational_t::value() const
{
  return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const
{
  return rational_t((-1) * get_num(), get_den());
}

rational_t rational_t::reciprocal() const
{
  return rational_t(get_den(), get_num());
}

// bool rational_t::equal(const rational_t& r, const double precision) const
// {
// }

// bool rational_t::greater(const rational_t& r, const double precision) const
// {
// }

// bool rational_t::less(const rational_t& r, const double precision) const
// {
// }

// rational_t rational_t::add(const rational_t& r)
// {
// }

// rational_t rational_t::substract(const rational_t& r)
// {
// }

// rational_t rational_t::multiply(const rational_t& r)
// {
// }

// rational_t rational_t::divide(const rational_t& r)
// {
// }

void rational_t::write(ostream &os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream &is)
{
  cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}

#pragma once

#include "pair_t.hpp"
#include "sll_node_t.hpp"
#include "sll_t.hpp"

namespace AED
{

	typedef pair_t<double> spair_t;
	typedef sll_node_t<spair_t> node_pair_t;
	typedef sll_t<spair_t> list_pair_t;

}

ostream &operator<<(ostream &os, const AED::spair_t &p)
{
	p.write(os);
	return os;
}

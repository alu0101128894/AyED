#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "vector_t.hpp"

#define MAX_STACK_SIZE 20

using namespace std;

namespace AED
{

	template <class T>
	class stack_v_t
	{
	private:
		vector_t<T> v_;
		int top_;

	public:
		stack_v_t(int max_sz = MAX_STACK_SIZE) : v_(max_sz),
												 top_(-1) {}

		~stack_v_t(void) {}

		bool empty(void)
		{
			return (top_ < 0);
		}

		T top(void)
		{

			assert(!empty());
			return v_.get_v(top_);
		}

		void pop(void)
		{

			assert(!empty());
			top_--;
		}

		void push(T dato)
		{

			assert(top_ < v_.get_sz() - 1);

			top_++;
			v_.get_set_v(top_) = dato;
		}

		ostream &write(ostream &os)
		{

			for (int i = top_; i >= 0; i--)
				cout << " │ " << setw(2) << v_.get_v(i) << "  │" << endl;
			cout << " └─────┘" << endl;
		}
	};

	template <class T>
	class TAD_stack_t
	{

	public:
		TAD_stack_t(void) {}
		virtual ~TAD_stack_t(void) {}

		virtual bool empty(void) = 0;
		virtual T top(void) = 0;
		virtual void pop(void) = 0;
		virtual void push(T dato) = 0;

		virtual ostream &write(ostream &os) = 0;
	};

}

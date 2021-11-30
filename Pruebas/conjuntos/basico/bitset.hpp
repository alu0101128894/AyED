#pragma once

#include <cstdio>
#include <cstring>

typedef long int block_t;

namespace AED {

 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }


/* itoa:  convert n to characters in s */
 void itoa(unsigned long n, char s[],int base)
 {
     long i;
     const int resto = __builtin_clzl(n);

     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % base + '0';   /* get next digit */
     } while ((n /= base) > 0);     /* delete it */

     int j = 0;
     for(; j < resto; j++)
	     s[i + j] = '0';

    s[i + j] ='\0';

     reverse(s);
 }


	class bitset_t {
	public:
		block_t block_;

	public:
		bitset_t(void):
		block_(0) {}

		~bitset_t(void){}

    // permite insertar un elemento entre 1 y 64
		void insert(int i){
			block_t aux = 0x1;
			block_ |= (aux << (i-1));  
		}


		void insert(const bitset_t& bs)
		{
			block_ |= bs.block_;
		}
		
		void remove(int i)
		{
			block_t aux = 0x1;
			aux <<= (i-1);
			block_ &= ~aux;
		}

		void remove(const bitset_t& bs)
		{
			block_ &= ~bs.block_;
		}
		
		bool contains(int i)
		{
			block_t aux = 0x1;
			aux <<= (i-1);
			return (block_ & aux) != 0;  
		}

		bool contains(const bitset_t& bs)
		{
			return (block_ & bs.block_) == bs.block_;
		}

		
		void clear(void) {block_ = 0;}
		
		void set_intersec(const bitset_t& bsj, bitset_t& result) const
		{
			result.block_ = block_ & bsj.block_;
		}

		void set_union(const bitset_t& bsj, bitset_t& result) const
		{
			result.block_ = block_ | bsj.block_;
		}
		
		void set_minus(const bitset_t& bsj, bitset_t& result) const
		{
			result.block_ = block_ & ~bsj.block_;
		}
		
		int cardinality(void) {return __builtin_popcount(block_);}
	
		int first_item(void){ return __builtin_ffsl(block_);}
		int last_item(void) { return 64 - __builtin_clzl(block_);}
		
		void write(std::ostream& os)
		{
			char aux[255];
			itoa(block_, aux, 2);
			os << aux;
		}	

	
	};
	 

}

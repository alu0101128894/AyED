#pragma once

	#include <cassert>
	#include <iostream>
	#include <cstring>	
	
	using namespace std;
	
    #define IT_PER_LINE 8	
	#define WIDE_OUTPUT 9


//#include <cstdint>


extern "C" void set_bit_64  (void*, int i);
extern "C" void reset_bit_64(void*, int i);
extern "C" int test_bit_64 (void*, int i);
extern "C" bool find_bit_64 (void*, int* pos);


#define BITSET_BLOCK_SIZE (8 * sizeof(T))
#define ONE_MASK 0x01



    template<class T, size_t N>
	class bitset2_t {
	public:
		T* block_;
        const int sz_;

	public:
		bitset2_t(void):
        block_(NULL),
        sz_((N / BITSET_BLOCK_SIZE) + 1)
        {
            block_ = new T[sz_];
        }

		bitset2_t(const bitset2_t& bs):
        block_(NULL),
        sz_(bs.sz_)
        {
            for(int i = 0; i < sz_; i++)
                block_[i] = bs.block_[i];
        }

		~bitset2_t(void){
            
            if (block_)
                delete [] block_;
        }


		void insert(const bitset2_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] |= bs.block_[i];
		}

		void remove(const bitset2_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] &= ~bs.block_[i];
		}

		bool contains(const bitset2_t& bs) const
		{	
			bool contains_set = true;

			int i = 0;

			while ((i < sz_) && (contains_set)){
				contains_set = contains_set && ((block_[i] & bs.block_[i]) == bs.block_[i]);
				i++;
			}

			return contains_set;		
		}

		void insert(int i);

		
		void remove(int i);

		
		bool contains(int i);
		
		void clear(void){
            
            for(int i = 0; i < sz_; i++)
                block_[i] = 0x0;            
            
        }
		
		void union_set(const bitset2_t&  B, bitset2_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] | B.block_[j];						
		}	

		void intersec_set(const bitset2_t&  B, bitset2_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] & B.block_[j];						
		}

		void diff_set(const bitset2_t&  B, bitset2_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] & ~B.block_[j];						
		}
		
        int cardinality(void)
        {
            int card = 0;
                
            for(int i = 0; i < sz_; i++)
                card += __builtin_popcount(block_[i]);
                
            return card;
        }
		
		
		bool operator==(bitset2_t& bs)
        {
            bool equal = true;
            
 			int i = 0;

			while ((i < sz_) && (equal)){
				equal = block_[i] == bs.block_[i];
				i++;
			}           
            
            return equal;
        }
        
        
		const bitset2_t& operator=(const bitset2_t& bs)
        {
            
            for(int i = 0; i < sz_; i++)
                block_[i] = bs.block_[i];  

            return *this;
        }
        
        
		ostream& write(ostream& os) const 
		{

			string s;
			to_string(s);
			os << s;

			return os;
		}        

    private:
        
        void to_string(string& s) const 
		 {
			for(int j = 0; j < sz_; j++){

				const int sz = min(N_BITS_WORD, N - j * N_BITS_WORD);

				T block = block_[j];		

				for(int i = 0; i < sz; i++)
				{
					const char c = '0' + (block & T(0x1));
					s.insert(s.begin(),c); 
					block >>= 1;
				}
			}
		 }

	};

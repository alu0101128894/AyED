#pragma once

#include <cstring>
#include <cassert>

using namespace std;

#define N_BITS_WORD (8 * sizeof(T))



template <class T, size_t N>
class bitset_t
{
	private:
		T* block_;
		int sz_;
	
	public:
		bitset_t(void):
			block_(NULL),
			sz_(N/N_BITS_WORD){

			if ((N % N_BITS_WORD) != 0)
				sz_ ++;
		
			block_ = new T[sz_];

			for(int i = 0; i < sz_; i++)
				block_[i] = 0;
		};

		bitset_t(const bitset_t& bs):
		block_(NULL),
		sz_(bs.sz_)
		{
			block_ = new T[bs.sz_];	

			for(int i = 0; i < sz_; i++)
				block_[i] = bs.block_[i];		
		}

		~bitset_t(void) {
			if (block_) delete [] block_;
		}

		void insert(int i){

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			block_[pos] |= (T(0x1) << offset);
		}

		void remove(int i){

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			block_[pos] &= ~(T(0x1) << offset);
		}

		bool contains(int i) const
		{

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			return (block_[pos] & (T(0x1) << offset)) != T(0x0);  
		}

		void insert(const bitset_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] |= bs.block_[i];
		}

		void remove(const bitset_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] &= ~bs.block_[i];
		}

		bool contains(const bitset_t& bs) const
		{	
			bool contains_set = true;

			int i = 0;

			while ((i < sz_) && (contains_set)){
				contains_set = contains_set && ((block_[i] & bs.block_[i]) == bs.block_[i]);
				i++;
			}

			return contains_set;		
		}

		int first_item(void) const
		{			
			int sm = -1;

			for(int i = 0; (i < sz_) && (sm == -1);i++)
			{
				if (block_[i] != 0)
					sm = first_item(block_[i]) + N_BITS_WORD * i;
			}

			return sm;
			
		}

		int last_item(void) const
		{		
			int bg = -1;

			for(int i = sz_ - 1; (i >= 0) && (bg == -1);i--)
			{
				if (block_[i] != 0)
					bg = last_item(block_[i]) + N_BITS_WORD * i;
			}

			return bg;
			
		}

		int cardinality(void) const
		{
			int card = 0;

			for(int i = 0; i < sz_; i++)
				card += cardinality(block_[i]);

			return card;
		}

		ostream& write(ostream& os) const 
		{

			string s;
			to_string(s);
			os << s;

			return os;
		}


		void union_set(const bitset_t&  B, bitset_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] | B.block_[j];						
		}	

		void intersec_set(const bitset_t&  B, bitset_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] & B.block_[j];						
		}

		void diff_set(const bitset_t&  B, bitset_t& C) const
		{
			for(int j = 0; j < sz_; j++)				
				C.block_[j] = block_[j] & ~B.block_[j];						
		}

	private:

		int first_item(T block) const
		{
			int pos = 1;

			while(((block & T(0x1)) == 0x0) && (pos <=  N_BITS_WORD)){
			
				block >>= 1;
				pos ++;
			}

			return pos;
		}

		int last_item(T block) const
		{
			int pos = 1;

			while(block != 0x1){
			
				block >>= 1;
				pos ++;
			}

			return pos;
		}

		int cardinality(T block) const
		{
			int card = 0;

			for(int i = 0; i < N_BITS_WORD;i++)
			{
				card += block & T(0x1);
				block >>= 1;
			}

			return card;
		}
	
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

ostream& operator<<(ostream& os, const bitset_t<long int, 80>& bs)
{
	bs.write(os);
	return os;
}

ostream& operator<<(ostream& os, const bitset_t<char, 80>& bs)
{
	bs.write(os);
	return os;
}

template <class T>
class letter_set_t
{
	private:
		bitset_t<T, 128> set_;

	public:
		letter_set_t(void): set_() {}

		~letter_set_t(void) {}

		void insert(char c){

			assert(((c >= 65) && (c <= 90))||((c >= 97) && (c <= 121)));

			set_.insert(c);
		}

		void remove(char c){

			assert(((c >= 65) && (c <= 90))||((c >= 97) && (c <= 121)));

			set_.remove(c);
		}

		bool contains(char c) const
		{
			assert(((c >= 65) && (c <= 90))||((c >= 97) && (c <= 121)));

			return set_.contains(c); 
		}

		void insert(const letter_set_t& bs)
		{
			set_.insert(bs.set_);
		}

		void remove(const letter_set_t& bs)
		{
			set_.remove(bs.set_);
		}

		bool contains(const letter_set_t& bs) const
		{	
			return set_.contains(bs.set_);		
		}

		char first_item(void) const
		{					
			return set_.first_item();
		}

		char last_item(void) const
		{		
			return set_.last_item();
		}

		int cardinality(void) const
		{
			return set_.cardinality();
		}

		ostream& write(ostream& os) const 
		{

			string s;
			to_string(s);
			os << s;

			return os;
		}


		void union_set(const letter_set_t&  B, letter_set_t& C) const
		{
			set_.union_set(B.set_, C.set_);					
		}	

		void intersec_set(const letter_set_t&  B, letter_set_t& C) const
		{
			set_.intersec_set(B.set_, C.set_);							
		}

		void diff_set(const letter_set_t&  B, letter_set_t& C) const
		{
			set_.diff_set(B.set_, C.set_);							
		}
	private:		
		void to_string(string& s) const 
		 {
			s += '{';

			for(int j = 1; j <= 128; j++)
				if (set_.contains(j)){
					s += char(j);
					s += ' ';		
				}

			s += '}';
		 }
	
};



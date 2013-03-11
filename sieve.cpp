#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)

#define MAX_NUM 1000001 
std::vector<int> primenos;

// array will be initialized to 0 being global


int primes[MAX_NUM];


void gen_sieve_primes(void)

{

	for (int p=2; p<MAX_NUM; p++) // for all elements in array

	{

		if(primes[p] == 0) // it is not multiple of any other prime

			primes[p] = 1; // mark it as prime


		// mark all multiples of prime selected above as non primes

		int c=2;

		int mul = p * c;

		for(; mul < MAX_NUM;)

		{

			primes[mul] = -1;

			c++;

			mul = p*c;

		}

	}

}

void save_primes()

{

	int c = 0;

	for(int i=0; i<MAX_NUM; i++)

	{

		if(primes[i] == 1)

		{
			primenos.push_back(i);
						


		}

	}

}

int main()

{

	gen_sieve_primes();//generates primes indices 0 or 1
	save_primes();//saves prime numbers in vector called primenos

	
	return 0;

}







#include <iostream>
using namespace std;
#include <math.h>

long long count( int S[], int m, int n )
{
    if (n == 0)
        return 1;
    
    if (n < 0)
        return 0;
 
    if (m <=0 && n >= 1)
        return 0;
 
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int main(){
	int* prime = new int [1000000] ();
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i < 1000000; i++){
		for (int j = i; j < floor(1000000/i); j++){
			prime[i*j] = 1;
		}
	}
	int summations;
	int temp = 11;
	int prime_number;
	while (summations < 5000){
		if (prime[temp] == 0){
			prime_number = temp;
			int pcount = 0;
			for (int i = 2; i < prime_number; i++){
				if (prime[i] == 0)
				pcount++;
			}
			int array[pcount] = {0};
			int idx = 0;
			for (int j = 2; j < prime_number; j++){
				if (prime[j] == 0){
					array[idx] = j;
					idx++;
					}
			}
		summations = count(array, pcount, prime_number);
		}
		temp++;
	}
	cout<<prime_number;
	return 0;
}

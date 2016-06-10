#include <iostream>
using namespace std;

int totient(int n, int prime[]){
	int idx = 0;
	double product = 1;
	while (n >= prime[idx]){
		if (n % prime[idx] == 0){
			product = product*(1.0 - 1/(prime[idx]*1.0));
		}
		idx++;
	}
	return n*product;
}

int main(){
	int* prime_array = new int [1000000] ();
	prime_array[0] = 1;
	prime_array[1] = 1;
	for (int i = 2; i < 5000000; i++)
		for (int j = 2*i; j < 1000000; j+=i)
			prime_array[j] = 1;
	int count = 0;
	for (int i = 0; i < 1000000; i++)
		if (prime_array[i] == 0)
			count++;
	int prime[count];
	int idx = 0;
	for (int i = 0; i < 1000000; i++)
		if (prime_array[i] == 0){
			prime[idx] = i;
			idx++;
		}
	double r = 1;
	idx = 0;
	long long num = 1;
	while ((r >= 4*1.0/10)){
		r = r*(prime[idx] - 1)/prime[idx];
		num = num*prime[idx];
		cout<<num<<"  "<<r<<"   "<<4*1.0/10<<endl;
		idx++;
	}
	cout<<num;
	return 0;
}

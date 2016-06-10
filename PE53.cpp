#include <iostream>
using namespace std;
#include <math.h>

unsigned long long numerator(unsigned long long n, unsigned long long r){
	if (r == n)
		return 1;
	return (r + 1)*numerator(n, r + 1);
}

unsigned long long factorial(unsigned long long number){
	if (number == 0)
		return 1;
	return (number)*factorial(number - 1);
}

unsigned long long comb(unsigned long long n, unsigned long long r){
	if (r < floor(n/2))
		r = n - r;
	return numerator(n,r)/(factorial(n - r));
}

int main(){
	unsigned long long n = 7;
	unsigned long long r = 2;
	unsigned long long combt;
	int count = 0;
	for (int i = 23; i <= 100; i ++){
		int r = 0;
		combt = 0;
		while (combt <= 1000000){
			r++;
			combt = comb(i, r);
			if (combt > 1000000)
				count = count + i - 2*r  + 1;
			//cout<<i<<"  "<<r<<"  "<<count<<endl;
		}
	}
	cout<<count;
	return 0;
}

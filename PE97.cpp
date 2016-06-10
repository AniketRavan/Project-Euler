#include <iostream>
using namespace std;

# define tenD 10000000000

int main(){
	long long product = 28433;
	int power = 7830457;
	int number = 2;
	for (int i = power; i > 0; i--){
		product = product*number;
		if (product > tenD)
			product = product % tenD;
	}
	cout<<(product + 1) % tenD;
	return 0;
}

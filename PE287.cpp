#include <iostream>
using namespace std;
#include <math.h>

bool is_prime(int number){
    if (number == 2)
        return true;
    for (int i = 2; i <= floor(sqrt(number)); i++){
        if (number % i == 0)
            return false;
    }
    return true;
}

bool verify(int number){
    int div;
    for (int i = 1; i <= floor(sqrt(number)); i++){
        if (number % i == 0){
            //cout<<number<<"  "<<i<<"  "<<number/i + i<<"  "<<is_prime(number/i + i)<<endl;
            if (!(is_prime(number/i + i))){
                return false;
            }
        }
    }
    return true;
}

int main() {
    unsigned long long sum = 0;
	for (int i = 1; i <= 100000000; i++){
		if (verify(i))
	        sum+=(i);
		if (i % 1000000 == 0)
			cout<<i<<endl;
		}
	cout<<sum;
	return 0;
}

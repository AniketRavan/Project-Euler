#include <iostream>
using namespace std;
#include <math.h>

bool is_prime(int number){
	if (number == 2)
		return true;
	for (int i = 3; i <= floor(sqrt(number)); i++)
		if (number % i == 0)
			return false;
	return true;
}

int main(){
	int flag = 1;
	int number = 33;
	while (flag == 1){
		number+=2; 
		while (is_prime(number))
			number+=2;
		flag = 0;
		for (int i = 1; i <= floor(sqrt(number/2)); i++){
			if (is_prime(number - 2*i*i)){
				flag = 1;
			}
		}
	}
	cout<<number;
	return 0;
}

#include <iostream>
using namespace std;

int count_prime_factors(int number){
	int divisor = 2;
	bool add = 1;
	int count = 0;
	while (number > 1){
		if (number % divisor == 0){
			if (add == 1)
				count++;
			number = number/divisor;
			add = 0;}
		else{
			divisor++;
			add = 1;
		}
	}
	return count;
}

int main(){
	int flag = 0;
	int numbers = 1;
	while (flag == 0){
		if (count_prime_factors(numbers) == 4)
			if (count_prime_factors(numbers + 1) == 4)
				if (count_prime_factors(numbers + 2) == 4)	
					if (count_prime_factors(numbers + 3) == 4)
						flag = 1;
	numbers++;
	//cout<<numbers<<endl;
	}
	cout<<numbers - 1<<endl;
	return 0;
}

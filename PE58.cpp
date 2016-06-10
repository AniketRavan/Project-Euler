#include <iostream>
using namespace std;
#include <math.h>

bool isprime(int number){
	if (number == 2)
		return true;
	for (int i = 2; i <= floor(sqrt(number)); i++){
		if (number % i == 0)
			return false;
	} 
	return true;
}

int main(){
	float percentage = 1;
	float count_diagonal = 1;
	float count_primes = 0;
	int current = 1;
	int increment = 2;
	int search_index = 0;
	while (percentage >= 0.1){
		for (int i = 0; i < 4; i++){
			current = current + increment;
			if (isprime(current)){
				count_primes = count_primes + 1;
				search_index = search_index + 1;
			}
		}
		increment = increment + 2;
		count_diagonal = count_diagonal + 4;
		percentage = count_primes/count_diagonal;
		//cout<<count_diagonal<<"  "<<count_primes<<"  "<<percentage<<endl;
			//cout<<percentage<<"  "<<increment - 2 + 1<<endl;
	}
	cout<<increment - 2 + 1;
	return 0;
}

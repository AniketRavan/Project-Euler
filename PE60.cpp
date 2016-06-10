#include <iostream>
using namespace std;
#include <math.h>

bool is_prime(long number){
	if (number == 2)
		return true;
	for (int i = 3; i <= floor(sqrt(number)); i++){
		if (number % i == 0)
			return false;
	}
	return true;
}

int number_of_digits(int number){
	int count = 0;
	while (number > 0){
		number = number/10;
		count++;
	}
	return count;
}

long power(long number, int exp){
	long num = number;
	for (int i = 0; i < exp; i++)
		num = num*10;
	return num;
}

int main(){
	int* prime = new int [1000000] ();
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i < 1000000; i++){
		for (int j = i; j <= floor(1000000/i); j++){
			prime[i*j] = 1;
		}
	}
	int count = 0;
	for (int i = 0; i < 1000000; i++){
		if (prime[i] == 0)
			count++;
	}
	
	int prime_numbers[count];
	int idx = 0;
	for (int i = 0; i < 1000000; i++)
		if (prime[i] == 0){
			prime_numbers[idx] = i;
			idx++;
		}
	int sum = 0;
	int numbers_found = 0;
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++){
			int n1 = prime_numbers[i];
			int n2 = prime_numbers[j];
			long temp = prime_numbers[i] + power(prime_numbers[j], number_of_digits(prime_numbers[i]));
			//cout<<is_prime(temp);
			if (is_prime(temp)){
				temp = prime_numbers[j] + power(prime_numbers[i], number_of_digits(prime_numbers[j]));
				if (is_prime(temp)){
					sum = sum + prime_numbers[i] + prime_numbers[j] + prime_numbers[j] + power(prime_numbers[i], number_of_digits(prime_numbers[j])) + prime_numbers[i] + power(prime_numbers[j], number_of_digits(prime_numbers[i]));
					numbers_found++;
				}
			}
			if (numbers_found == 5)
		}
	cout<<sum;
	return 0;
}

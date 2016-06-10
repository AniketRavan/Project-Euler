#include <iostream>
using namespace std;

int factorial(int number){
	if (number <= 0)
		return 1;
	return number*factorial(number - 1);
}

int digit_fact_sum(int number){
	int sum = 0;
	while (number > 0){
		sum = sum + factorial((number % 10));
		number = number/10;
	}
	return sum;
}

int main(){
	int* array = new int [1000000]();
	int* array60 = new int [1000000]();
	int number = 1;
	int temp;
	int COUNT = 0;
	for (number = 1; number < 1000000; number++){
		temp = digit_fact_sum(number);
		int count = 1;
		while (temp != 169 && temp != 871 && temp != 872 && temp != number && temp != digit_fact_sum(temp)){
			temp = digit_fact_sum(temp);
			count++;
		}
		if (temp == digit_fact_sum(temp))
			count++;
		if (temp == 169)
			count = count + 2;
		if (temp == 871)
			count = count + 1;
		if (temp == 872)
			count = count + 1;
		
		if (count == 59)
			COUNT++;
	}
	cout<<COUNT<<endl;
	return 0;
}

#include <iostream>
using namespace std;
#include <math.h>

int sum_of_divisors(int number){
	int sum = 1;
	for (int i = 2; i <= floor(sqrt(number)); i++){
		if (number % i == 0){
			sum = sum + i + (number/i)*(number/i != i);
			//cout<<i<<" "<<number/i<<" ";
		}
	}
	return sum;
}

int main(){
	int number = 10;
	int labels[15000] = {0};
	for (number = 10; number < 15000; number++){
		int sum = number;
		bool amicable = 0;
		int count = 0 ;
		if (number == sum_of_divisors(number))
			{
			//cout<<number<<endl;
			labels[number - 1] = 1;
			//cout<<labels[number - 1]<<endl;
		}
		//cout<<labels[number - 1]<<endl;
		if (labels[number - 1] == 1)
			amicable = 1;
		while (sum < 15000 && !amicable){
			count++;
			if (count > number)
				break;
			//cout<<sum<<" "<<number<<" "<<count<<endl;
			sum = sum_of_divisors(sum);
			//cout<<sum<<"  ";
			//cout<<sum<<" "<<number<<endl;
			if (sum/10 == 0)
				break;
			if (labels[sum - 1] == 1)
				break;
			if (sum == number){
				amicable = 1;
				labels[number - 1] = 1;
				labels[sum_of_divisors(number) - 1] = 1;
				cout<<number<<"  "<<sum<<" "<<amicable<<endl;
			}
		}
	}
	//cout<<labels[28]<<endl;
	return 0;
}

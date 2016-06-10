#include <iostream>
using namespace std;

int sumOfSquares(int number){
	if (number == 0)
		return 0;
	else{
		int sum = 0;
		int digit = 0;
		
		while (number != 0){
			digit = number - 10*(number/10);
			sum = sum + digit*digit;
			number = number/10;
		}
		return sum;
	}
}

int main(){
	int count = 0;
	for (int i = 1; i < 10000000; i++){
		int sum = i;
		while (sum != 1){
			sum = sumOfSquares(sum);
			if(sum == 89){
				count = count + 1;
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}

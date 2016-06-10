#include <iostream>
using namespace std;
#include <math.h>

bool is_abundant(int number){
	int sum = 1;
	for (int i = 2; i <= floor(sqrt(number)); i++){
		if (number % i == 0){
			sum = sum + i + (number/i)*(number/i != i);
			//cout<<i<<" "<<number/i<<" ";
		}
	}
	if (sum > number)
		return true;
	else return false;
}


int main(){
	int array[28123] = {0};
	for (int i = 0; i < 28123; i++){
		array[i] = i + 1;
	}
	int abundant[28123] = {0};
	for (int i = 0; i < 28123; i++){
		if (is_abundant(i + 1))
			abundant[i] = 1;
	}

	for (int i = 1; i < 28124; i++){
		if (abundant[i-1]){
			for (int j = 1; j < 28124; j++){
				if (abundant[j-1] && i + j <= 28123)
					array[i + j - 1] = 0;
			}
		}
	}
	
	int sum = 0;
	for (int i = 0; i < 28123; i++){
		if (array[i] != 0)
			sum = sum + array[i];
	}
	
	cout<<sum<<endl;
	return 0;
	}

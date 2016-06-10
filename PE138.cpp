#include <iostream>
using namespace std;
#include <math.h>

bool is_coprime(unsigned long long a, unsigned long long b){
	int temp;
	for (int i = 2; i <= floor(sqrt(a)); i++){
		//cout<<i<<endl;
		if (a % i == 0){
			temp = a/i;
			//cout<<i<<" "<<temp<<" "<<b % i<<endl;
			if (b % i == 0)
				return false;
			
			if (b % temp == 0)
				return false;
			
		}
	}
	return true;
}

int main(){
	unsigned long long hyp, a, b;
	unsigned long long sum = 0;
	int count = 0;
	unsigned long long m = 2;
	unsigned long long n;
	unsigned long long n_array[4] = {0};
	int go[4];
	while (count < 12){
		if (sqrt(5*m*m - 1) == (unsigned long long) sqrt(5*m*m - 1))
			{
				go[0] = 1;
				n_array[0] = sqrt(5*m*m - 1) - 2*m;
			}
		if (sqrt(5*m*m + 1) == (unsigned long long) sqrt(5*m*m + 1))
		{
			go[1] = 1;
			n_array[1] = sqrt(5*m*m + 1) - 2*m;
		}
		
		if (sqrt(6*m*m + 1)/2 == (unsigned long long) sqrt(6*m*m + 1)/2)
		{
			go[2] = 1;
			n_array[2] = sqrt(6*m*m + 1)/2 - m;
		}
		
		if (sqrt(6*m*m - 1)/2 == (unsigned long long) sqrt(6*m*m - 1)/2)
		{
			go[3] = 1;
			n_array[3] = sqrt(6*m*m - 1)/2 - m;
		}
		
		for (int i = 0; i < 4; i++){
			n = n_array[i];
			//cout<<n<<" "<<i<<endl;
			int remainder;
			if (m % 2 == 0)
				remainder = 1;
			else 
				remainder = 0;
			if (n % 2 != remainder)
				go[i] = 0;
			if (go[i] == 1){
				if (is_coprime(m,n)){;
					hyp = m*m + n*n;
					//cout<<hyp<<endl;
					cout<<hyp<<endl;
					count++;
					sum+=hyp;
					}
				}
				go[i] = 0;
			}
			m++;
		}
		cout<<sum<<endl;
		return 0;
		}

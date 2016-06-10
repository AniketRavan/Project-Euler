#include <iostream>
using namespace std;
#include <math.h>

bool is_coprime(int a, int b){
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

# define number 1500000

int main(){
	int hyp, a, b;
	long long perimeter;
	int initial;
	int* perimeter_count = new int [number]();
	for (int m = 2; m < floor(sqrt(number)); m++){
		int initial;
		//cout<<m<<"  ";
		if (m % 2 == 0)
			initial = 1;
		else initial = 2;
		for (int n = initial; n < m; n+=2){
			//cout<<m<<" "<<n<<endl;
			if (is_coprime(m,n)){
				a = m*m - n*n;
				b = 2*m*n;
				hyp = m*m + n*n;
				perimeter = a + b + hyp;
				//cout<<a<<"  "<<b<<endl;
				if (perimeter <= number){
					perimeter_count[perimeter - 1]++;
					//cout<<perimeter_count[perimeter - 1]<<endl;
				}
				//cout<<hyp<<endl;
				int k = 2;
				while (k*perimeter <= number){
					//cout<<perimeter<<endl;
					//cout<<k*perimeter<<endl;
					perimeter_count[k*perimeter - 1]++;
			//		cout<<perimeter_count[k*perimeter - 1]<<endl;
					k++;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < number; i++)
		if (perimeter_count[i] == 1)
			count++;
	cout<<count<<endl;
	return 0;
}

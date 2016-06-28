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

int main(){
	int hyp, a, b;
	int m = 2;
	long long perimeter;
	int perimeter_count[1000] = {0};
	while (hyp <= 1000){
		int initial;
		if (m % 2 == 0)
			initial = 1;
		else initial = 2;
		for (int n = initial; n < m; n+=2){
			if (is_coprime(m,n)){
				a = m*m - n*n;
				b = 2*m*n;
				hyp = m*m + n*n;
				perimeter = a + b + hyp;
				if (perimeter <= 1000)
					perimeter_count[perimeter - 1]++;
				//cout<<hyp<<endl;
				int k = 2;
				while (k*perimeter <= 1000){
					//cout<<perimeter<<endl;
					//cout<<k*perimeter<<endl;
					perimeter_count[k*perimeter - 1]++;
			//		cout<<perimeter_count[k*perimeter - 1]<<endl;
					k++;
				//	cout<<m<<"  "<<n<<"  "<<k*perimeter<<"  "<<k<<endl;
				}
			}
		}
		m++;
	}
	int max_count = 0;
	for (int j = 0; j < 1000; j++){
		if (max_count < perimeter_count[j])
			{
			cout<<j + 1<<"  "<<max_count<<endl;
			max_count = perimeter_count[j];
		}
	}
	return 0;
}

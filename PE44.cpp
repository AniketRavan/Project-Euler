#include <iostream>
using namespace std;
#include <math.h>

int main(){
	unsigned long long p1, p2;
	unsigned long long min = 100000000;
	unsigned long long diff;
	for (int n = 2; n < 1200; n++){
		for (int m = 1; m < n; m++){
			p1 = n*(3*n - 1)/2;
			p2 = m*(3*m - 1)/2;
			if (p2 >= p1)
				diff = p2 - p1;
			else 
				diff = p1 - p2;
			float ind1 = (1 + sqrt(1 + 24*diff))/6;
			float ind2 = (1 + sqrt(1 + 24*(p2+p1)))/6;
			if (ind1 == (int)ind1 && ind2 == (int)ind2)
				{cout<<p1<<" "<<p2<<" "<<diff<<endl;
				if (diff < min)
					min = diff;
			}
		}
	}
	cout<<min<<endl;
	return 0;
}

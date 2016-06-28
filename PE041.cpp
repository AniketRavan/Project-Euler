#include <iostream>
using namespace std;

int main(){
	char* prime_array = new char [9876543210] ();
	prime_array[0] = '1';
	prime_array[1] = '1';
	for (int i = 2; i < 4938271605; i++){
		if (i % 10000 == 0)
			cout<<i<<endl;
		for (int j = 2*i; j < 9876543210; j+=i)
			prime_array[j] = '1';
		}
	cout<<prime_array[2];
	return 0;
}

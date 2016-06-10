#include <iostream>
using namespace std;
#include <math.h>

int main() {
	int count = 0;
	for (int i = 1; i < 10; i++){
		int ind = 1;
		int digits;
		// The 'digits' function cannot catch up with the number of indices if indices exceeds digits by 1
		while (floor(ind*log10(i))+1 - ind > -1){
		digits = floor(ind*log10(i))+1; // Calculates the number of digits
		if ((digits - ind) == 0){
			count = count + 1;
			cout<<"Count "<<count<<" "<<ind<<" "<<i<<" "<<endl;
		}
		ind++;
		}
	}
	cout<<"finished!";
	return 0;
}

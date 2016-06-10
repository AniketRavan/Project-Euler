#include <iostream>
using namespace std;
#include <math.h>

long long n_squares(long long tiles){
	if (tiles < 4)
		return 0;
	double a;
	long long count = 0;
	if (tiles % 4 == 0){
		for (a = ceil(sqrt(tiles)); a <= tiles/4 + 1; a++)
		{
			if (sqrt(a*a - tiles) == (long long) sqrt(a*a - tiles) && sqrt(a*a - tiles) != 0)
				count++;
		}
	}
	if (tiles % 5000 == 0)
		cout<<count<<endl;
	return count + n_squares(tiles - 4);
}

int main(){
	int tiles = 1000000;
	int COUNT = 0;
	while (tiles > 4){
		double a;
		int count = 0;
		if (tiles % 4 == 0){
			for (a = ceil(sqrt(tiles)); a <= tiles/4 + 1; a++)
			{
				if (sqrt(a*a - tiles) == (long long) sqrt(a*a - tiles) && sqrt(a*a - tiles) != 0)
					count++;
			}
		}
		if (tiles % 5000 == 0)
			cout<<count<<endl;
		COUNT = count + COUNT;
		tiles = tiles - 4;
		//cout<<count<<endl;
	}
	cout<<COUNT<<endl;
	return 0;
}

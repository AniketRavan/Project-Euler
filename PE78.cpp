#include <iostream>
using namespace std;

long long count(int m, int n)
{
    if (n == 0)
        return 1;
    
    if (n < 0)
        return 0;
 
    if (m <=0 && n >= 1)
        return 0;
 
    return count(m - 1, n) + 1;
}

int main(){
	int n = 10;
	int N = 1;
	while (N % 1000000 != 0){
		n++;
		if (N % 10000 == 0)
			cout<<N<<endl;
		N = count(n, n);
	}
	cout<<n<<endl;
	return 0;
}

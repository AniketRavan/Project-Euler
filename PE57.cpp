#include <iostream>
using namespace std;
#include <math.h>

string add(string a, string b){
	int l_a, l_b;
	l_a = a.length();
	l_b = b.length();
	int shorterLength;
	string str;
	if (l_a > l_b){
		str = a;
		shorterLength = l_b;
	}
	else {
		str = b;
		shorterLength = l_a;
	}
	char carry = '0';
	for (int i = shorterLength - 1; i >= 0; i--){
		int sum;
		sum = carry + a[i + l_a - shorterLength] + b[i + l_b - shorterLength] - '0' -'0' - '0';
		//cout<<a[i + l_a - shorterLength]<<"  "<<b[i + l_b - shorterLength]<<"  "<<sum<<endl;
		if (sum > 9)
		{
			carry = '1';
			sum = sum - 10*(sum/10);
		}
		else 
			carry = '0';
		str[i + l_a - shorterLength + l_b - shorterLength] = sum + '0';
		
	}
	
	if (carry != '0')
	{
		if (str.length() > shorterLength){
			str[str.length() - shorterLength - 1] = str[str.length() - shorterLength - 1] + '1' - '0';
		}
		else {
			str = "1" + str;
		}
	}
	
	return str;
}


int main(){
	// Numerator and Denominator of the fraction under 1 at every iteration
	string temp;
	string NUM = "1";
	string DEN = "1";
	// Number of digits
	int numDigits; 
	int denDigits;
	int count; 
	for (int i = 0; i < 1000; i++){
		temp = NUM;
		NUM = add(NUM, DEN);
		NUM = add(NUM, DEN);
		DEN = add(temp, DEN);
		numDigits = NUM.length();
		denDigits = DEN.length();
		if (numDigits > denDigits){
			count = count + 1;
		}
	}
	
	cout<<count<<endl;
	return 0;
}

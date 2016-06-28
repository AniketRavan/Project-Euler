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
	
	int k = 1;
	while (carry != '0')
	{   int sum;
		if (str.length() > shorterLength && str.length() - shorterLength >= k){
			int sum;
			sum = carry + str[str.length() - shorterLength - k] - '0' - '0';
			//cout<<str<<endl<<endl;
			//cout<<sum<<" "<<carry<<" "<<str.length() - shorterLength - k<<" "<<k<<endl;
			if (sum > 9){
				carry = '1';
				//cout<<sum<<" "<<carry<<" "<<k<<endl<<endl;;
				sum = sum - 10*(sum/10);
			}
			else 
				carry = '0';
			str[str.length() - shorterLength - k] = sum + '0';
			k++;
		}
		else {
			str = "1" + str;
			carry = '0';
		}
	}
	
	return str;
}

bool isPalindrome(string number){
	int length = number.length();
	char invertedNumber[length];
	for (int i = 0; i < length; i++){
		invertedNumber[i] = number[length - i - 1];
		invertedNumber[i + 1] = '\0';
	}
		
	if (invertedNumber == number)
		return true;
	else 
		return false;
}

int str2int(string number){
	char invertedNumber[number.length()];
	for (int i = 0; i < number.length(); i++){
		invertedNumber[i] = number[number.length() - i - 1];
	}
	int sum = 0;
	int tens = 1;
	for (int i = 0; i < number.length(); i++){
		int temp = invertedNumber[i] - '0';
		sum = sum + temp*tens;
		tens = tens*10;
	}
	return sum;
}

string decimal2binary(string Decimal){
	int decimal;
	decimal = str2int(Decimal);
	if (decimal == 1)
		return "1";
	if (decimal == 0)
		return "0";
	int excess, exp;
	double temp;
	temp = floor(log2(decimal));
	exp = (int) temp;
	char binary[exp + 1];
	excess = decimal;
	for (int i = 0; i < exp + 1; i++){
		//cout<<i<<endl;
		if (pow(2,exp - i) <= excess){
			binary[i] = '1';
			excess = excess - pow(2,exp - i);
			}
		else {
			binary[i] = '0';
					}
		binary[i+1] = '\0';
    //cout<<i<<endl;	
	}
	string Binary;
	Binary = binary;
	//cout<<Binary<<" "<<Binary.length()<<endl;
	return Binary;
}

int main(){
	string number = "1";
	string sum = "0";
	while (number.length() < 7){
		if (isPalindrome(number) && isPalindrome(decimal2binary(number))){
			sum = add(sum,number);
			cout<<number<<" "<<decimal2binary(number)<<endl;
		}
		number = add(number,"1");
	}
	//cout<<number<<endl;
	cout<<sum<<endl;
	return 0;
}

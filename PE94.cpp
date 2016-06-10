#include <iostream>
using namespace std;
#include <math.h>

double triangle_area(double a, double b, double c){
	double s = (a + b + c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool is_triangle(double a, double b, double c){
	if (a == 0 || b == 0 || c == 0)
		return false;
	if (a + b <= c || b + c <= a || c + a <= b)
		return false;
	return true;
}

int main(){
	unsigned long long perim;
	unsigned long long a = 1;
	unsigned long long b = 1;
	unsigned long long c = 2;
	double area;
	unsigned long long sum = 0;
	while (perim < 1000000000){
		c = c - 2;
		if (is_triangle(a,b,c)){
			area = triangle_area(a,b,c);
			perim = a + b + c;
			if (area == (long long)area){
				sum = sum + perim;
				//cout<<area<<"  "<<a<<"  "<<b<<"  "<<c<<endl;
				//cout<<a<<"  "<<b<<"  "<<c<<endl;
			}
		}
		c = c + 2;
		if (is_triangle(a,b,c)){
			area = triangle_area(a,b,c);
			perim = a + b + c;
			if (area == (long long)area){
				sum = sum + perim;
				//cout<<area<<"  "<<a<<"  "<<b<<"  "<<c<<endl;
				//cout<<a<<"  "<<b<<"  "<<c<<endl;
			}
		}
		a++;
		b = a;
		c = a + 1;
		
	}
	cout<<sum;
	return 0;
}

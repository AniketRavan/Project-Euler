#include <iostream>
using namespace std;


double new_slope(double x, double y, double m){ 
	double term1, term2;
	term1 = y/(4*x);
	term2 = (y/(4*x) - m)/(1 + y*m/(4*x));
	return (term1 + term2)/(1 - term1*term2);
}

double intercept(double x, double y, double m){
	return y - m*x;
}

double new_x(double x, double m, double c){
	return -2*m*c/(m*m + 4) - x;
}

double new_y(double x, double m, double c){
	return m*x + c;
}

double slope(double x1, double x2, double y1, double y2){
	return (y2 - y1)/(x2 - x1);
}

int main(){
	double x1, x2, y1, y2, m, c;
	x1 = 0.0;
	y1 = 10.1;
	x2 = 1.4;
	y2 = -9.6;
	m = slope(x1,x2,y1,y2);
	int count = 0;
	int flag = 1;
	while (flag == 1){
		count++;
		m = new_slope(x2, y2, m);
		c = intercept(x2, y2, m);
		//cout<<c<<endl;
		x1 = x2;
		y1 = y2;
		x2 = new_x(x1, m, c);
		y2 = new_y(x2, m, c);
		if (y2 > 0 && !(x2 < -0.01 || x2 > 0.01))
			flag = 0;
		//cout<<m<<"  "<<c<<"  "<<endl;
	}
	cout<<count;
	
	return 0;
}

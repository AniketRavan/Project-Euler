#include <iostream>
using namespace std;
#include <math.h>

int main(){
	int n_rectangles = 0;
	int width;
	int breadth;
	int least = 2000000;
	int area;
	int diff = 0;
	for (width = 53; width > 0; width--){
		breadth = floor(((sqrt(1 + 4*4*2000000/(width*(width + 1)))) - 1)/2);
		n_rectangles = (width)*(width + 1)/2*(breadth)*(breadth + 1)/2;
		diff = abs(n_rectangles - 2000000);
		if (diff < least)
			{
			area = breadth*width;
			least = diff;	
			cout<<least<<"  "<<diff<<"  "<<width<<"  "<<"  "<<breadth<<"  "<<n_rectangles<<endl;	
		}
	}
	return 0;
}

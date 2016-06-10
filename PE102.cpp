#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>
#define PI 3.14159265

int main(){
	ifstream myfile;
	myfile.open("p102_triangles.txt");
	string st;
	//myfile>>data;
	int i = 0;
	string temp;
	int rows = 0;
	while (myfile>>st)
		rows++;
	string data[rows];
	myfile.close();
	myfile.open("p102_triangles.txt");
	for (int i = 0; i < rows; i++){
		//myfile>>data>>a;
		getline(myfile,data[i]);
		//cout<<data[i]<<endl;
	}
	ofstream file ( "sample_triangles.txt" );
	for (int i = 0; i < rows; i++){
		temp = data[i];
		int l = temp.length();
		int idx = 0;
		while (idx < l){
			if (temp[idx] == ',')
				file<<' ';
			else 
				file<<temp[idx];
			idx++;
		}
		file<<endl;
	}
	myfile.close();
	file.close();
	int x1, x2, x3, y1, y2, y3;
	double r1, r2, r3, A, B, C;
	ifstream myfile1;
	myfile1.open("sample_triangles.txt");
	int count = 0;
	for (int i = 0; i < rows; i++){
		myfile1>>x1>>y1>>x2>>y2>>x3>>y3;
		r1 = sqrt(x1*x1 + y1*y1);
		r2 = sqrt(x2*x2 + y2*y2);
		r3 = sqrt(x3*x3 + y3*y3);
		A = acos((x1*x2 + y1*y2)/(r1*r2))*180/PI;
		B = acos((x2*x3 + y2*y3)/(r2*r3))*180/PI;
		C = acos((x1*x3 + y1*y3)/(r1*r3))*180/PI;
		if (A + B + C > 359.999 && A + B + C < 360.001)
			count++;
	}
	cout<<count;
	return 0;
}

#include <iostream>
using namespace std;
#include <fstream>
#include <math.h

int main(){
	ifstream myfile;
	myfile.open("p099_base_exp.txt");
	string st;
	//myfile>>data;
	int i = 0;
	string temp;
	int rows = 0;
	while (myfile>>st)
		rows++;
	string data[rows];
	myfile.close();
	myfile.open("p099_base_exp.txt");
	for (int i = 0; i < rows; i++){
		//myfile>>data>>a;
		getline(myfile,data[i]);
		//cout<<data[i]<<endl;
	}
	ofstream file ( "sample.txt" );
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
	ifstream myfile1;
	myfile1.open("sample.txt");
	//myfile>>data;
	int base , exponent, ans;
	long long max;
	for (int i = 0; i < rows; i++){
		myfile1>>base>>exponent;
		if (max < exponent*log(base)){
			max = exponent*log(base);
			ans = i;
			cout<<base<<" "<<exponent<<"  "<<max<<endl;
		}
	}
	cout<<ans + 1;
	//cout<<<<endl;
	return 0;
}

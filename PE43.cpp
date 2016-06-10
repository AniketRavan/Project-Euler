#include <iostream>
using namespace std;


string Permute(string s, int i){
	if (i == s.length())
		cout<<s<<endl;
    else {
    	for (int j = i; j < s.length(); j++ ){
    		swap(s[j], s[i]);
    		Permute(s, i + 1);
    		swap(s[j], s[i]);
		}
	}
}

int main(){
	Permute("0123",0);
	return 0;
}

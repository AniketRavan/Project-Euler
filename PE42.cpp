#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>

int word_score(string name){
	int score = 0;
	for (int i = 0; i < name.length(); i++){
		int temp, deduct;
		temp = name[i];
		if (temp >= 65 && temp <= 90)
			deduct = 64;
		else 
			deduct = 96;
		score = score + name[i] - deduct;
	}
	return score;	
}

int main(){
	ifstream myfile;
	myfile.open("p042_words.txt");
	string names;
	myfile>>names;
	int idx = 0;
	int count = 0;
	while (idx < names.length())
		{if (names[idx] == '"')
			count++;
		idx++;
		}
	int names_count = count/2;
	idx = 0;
	int idx_temp;
	bool read = 0;
	float max_score = 0;
	int scores[names_count];
	for (int i = 0; i < names_count; i++){
		string temp;
		if (names[idx] == ',')
			idx++;
				if (names[idx] == '"'){
			read = !read;
		}
		idx++;
		idx_temp = 0;

		while (read){
			temp = temp + names[idx];
			idx++;
			if (names[idx] == '"'){
				read = !read;
				idx++;
			}
		}
		scores[i] = word_score(temp);
		if (scores[i] > max_score)
			max_score = scores[i];
	}
	int triangle_count = 0;
	int max_n = floor((-1+sqrt(1+8*max_score))/2);
	int triangle_number;
	for (int n = 0; n <= max_n; n++){
		triangle_number = n*(n+1)/2;
		for (int i = 0; i < names_count; i++)
			if (triangle_number == scores[i]){
				triangle_count++;
				//cout<<triangle_number<<endl;
			}
	}
	cout<<triangle_count<<endl;
	myfile.close();
	return 0;
}

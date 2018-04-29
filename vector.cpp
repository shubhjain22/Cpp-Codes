#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i){
	cout << i << " "; 
}
int main(int argc, char const *argv[])
{
	vector<int> v;
	v.reserve(100);
	v.push_back(3);
	v.emplace_back(6);
	int64_t a =10;
	for(auto i = v.rbegin() ; i != v.rend() ; i++){
		cout << *i << " " << endl;  
	}
	sort(v.rbegin(),v.rend());
	for(auto i = v.rbegin() ; i != v.rend() ; i++){
		cout << *i << " " << endl;  
	}

	for_each(v.begin(),v.end(),print);
	return 0;
}
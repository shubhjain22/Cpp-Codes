#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

template <class T>
T max(T& t1, T& t2){
	if(t1>t2){
		return t1;
	}
	else{
		return t2;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int a;
	int b;
	string name;
	cin >> name;
	cout << "Enter the two numbers" << endl;
	cin >> a >> b;
	int c = max(a,b);
	cout << "The sum of the numbers is" << c << endl;
	return 0;
}
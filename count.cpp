#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	vector<string> v;
	v.reserve(5);
	for(int i = 0 ; i < 2 ; i++){
		string str ; 
		cin >> str;
		v.push_back(str);
	}
	auto f = end(v);
	f-=1;
	return 0;
}
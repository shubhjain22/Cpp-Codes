#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int n,m;
	vector<int> v2;
	vector<int> v3;
	cin >> n >> m;
	vector<int> v;
	v.reserve(n);
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		v.emplace_back(temp);
	}
	sort(begin(v),end(v));
	copy_if(begin(v),end(v),begin(v2),[this.m](int k)->int{return k<m;});
	
	for(auto i = begin(v2);i!=end(v2);i++){
		cout << *i << endl;
	}
}	

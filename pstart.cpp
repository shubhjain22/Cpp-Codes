#include <bits/stdc++.h>

using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int64_t n,m;
	cin >> n >> m;
	vector<int64_t> v;
	v.reserve(n);
	for(int64_t i=0;i<n;i++){
		int64_t temp;
		cin >> temp;
		v.emplace_back(temp);
	}
	if(m==1){
		cout << *std::min_element(begin(v),end(v));
	}
	else{
		cout << *std::max_element(begin(v),end(v));
	}
}
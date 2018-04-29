#include <bits/stdc++.h>
using namespace std;

int main(void){
	std::ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> v;
	v.reserve(n);
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		v.emplace_back(temp);
	}
	int count=0;
	sort(begin(v),end(v));
	if(x==0){
		if(find(begin(v),end(v),0)!=end(v)){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
	}
	else{
	for(int i=0;i<x;i++){
		if(find(begin(v),end(v),i)!=end(v)){

		}
		else{
			count++;
		}
	}
	if(find(begin(v),end(v),x)!=end(v)){
		cout << count+1 << endl;
	}
	else{
		cout << count << endl;
	}
}
	return 0;
}

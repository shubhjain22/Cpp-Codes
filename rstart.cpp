#include <bits/stdc++.h>
 
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int64_t n,k;
	cin >> n >> k;
	int64_t count=0;
	vector<int64_t> v;
	v.reserve(n);
	fill(begin(v),end(v),0);
	if(k==0){
		cout << "0 0 " << endl;
	}
	else if(n!=1 && k==1){
		cout << "1 2 " << endl;
	}
	else if(n==k){
		cout << "0 0 " << endl;
	}
	else if(k<n/2){
		if(k<(n/2)-1){
			count = k*2;
		}
		else{
		for(auto i=begin(v);i!=end(v);i=i+3){
			*i=1;
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<i+2;j++){
				if((v[i]==0&&v[j]==1) || (v[i]==1&&v[j]==0)){
					count++;
				}
			}
		}
	}
		cout << "1 " << count << endl;
	}
	else{
		cout << "1 " << n-k << endl;
	}
}
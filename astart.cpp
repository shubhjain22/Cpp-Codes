#include <bits/stdc++.h>
 
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> v;
		v.reserve(n);
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			v.emplace_back(temp);
		}
		
		int flag=0;
		int count=0;
		sort(begin(v),end(v));
		if(k==0){
			sort(begin(v),end(v));
			for(int i=0;i<n;i++){
				if(i==n-1 && v[i]==i){
					flag=n;
					break;
				}
				if(v[i]!=i){
					flag=i;
					break;
				}
			}
		}
		else{
			for(int i=0;;i++){
				if(v[i] - i == k){
					
				}
			}
		}
			cout << flag << endl;
		}
		
	}

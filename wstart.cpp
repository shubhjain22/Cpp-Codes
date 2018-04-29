#include <bits/stdc++.h>

using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int n,k,count=0;
	cin >> n >> k;
	vector<int> v;
	v.reserve(n);
	for(int i=0;i<n;i++){
		int temp ;
		cin >> temp;
		v.emplace_back(temp);
	}	
	bool b=true;
	for(int i=0;i<n && b;i++){
		if(v[i]>=8){
			k = k-8;
			if(k<=0){
				break;
			}
			count++;
		}
		else{
			k=k-v[i];
			if(k<=0){
				break;
			}
			count++;
		}
		
		if(k>0 && i==n-1){
			b = false;
		}
	}
	if(b==false){
		cout << "-1" << endl;
	}
	else{
		cout << count << endl;
	}
}
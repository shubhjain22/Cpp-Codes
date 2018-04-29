#include <bits/stdc++.h>
 
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int count=0;
		for(int i=5;i<=n;i++){
			if(i%5==0){
				count++;
			}
		}
		cout << count << endl;
	}
}
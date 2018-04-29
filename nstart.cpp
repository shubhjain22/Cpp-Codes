#include <bits/stdc++.h>
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sum=0;
		string str = to_string(n);
		if((str[str.size()-1]-'0') %2!=0){
			for(int i=0;i<str.size()-1;i++){
				sum+=(str[i]-'0');
			}
			if(sum%3==0 && (str[str.size()-2]-'0')%2==0){
				cout<< str.substr(0,str.size()-1) << "\n"; 
			}
			else{
				cout <<"-1"  << "\n";
			}
		}
		else{
			for(int i=0;i<str.size();i++){
				sum+=(str[i]-'0');
			}
			int modulo = sum%3;
			if(modulo==0){
				
			}
			reverse(begin(str),end(str));

		}
	}
}
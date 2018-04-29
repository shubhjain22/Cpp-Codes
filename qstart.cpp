#include <bits/stdc++.h>

using namespace std;

int64_t factorial(int64_t n);
int main(void){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int64_t count=0;
		int n;
		int64_t x;
		cin >> x;
		string ini = bitset<34>(1).to_string();
		for(int64_t k=2;k<x+1;k++){
			string c="00000000000000000000000000000000000";
			string b = bitset<34>(k).to_string();
			for(int i=0;i<34;i++){
				if(b[i]=='0'&&ini[i]=='0'){
					c[i] = '0';
				}
				else if(b[i]=='1'&&ini[i]=='1'){
					c[i] = '0';
				}
				else if(b[i]=='0'&&ini[i]=='1'){
					c[i] = '1';
				}
				else{
					c[i] = '1';
				}
			}
			ini= c;
		}
		for(int i=0;i<34;i++){
			int h = (int)ini[i] - 48;
			count+=h*pow(2,33-i);
		}
		cout << count << endl;
	}
}


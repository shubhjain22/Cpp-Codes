#include <bits/stdc++.h>
using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int64_t a,b;
		cin >> a >> b;
		string stra = to_string(a);
		string strb = to_string(b);
		string ans = "";
		if(stra.size() > strb.size()){
			string temp = stra.substr(0,stra.size()-strb.size());
			stra.erase(0,stra.size()-strb.size());
			for(int64_t i=0;i<strb.size();i++){
				char c1 = stra[i];
				char c2 = strb[i];
				int64_t i1 = c1-'0';
				int64_t i2 = c2-'0';
				int64_t flag = i1+i2;
				if(flag>9){
					flag-=10;
					ans+=to_string(flag);
				}
				else{
					ans+=to_string(flag);
				}
			}
			temp+=ans;
			cout <<  temp << "\n";
		}
		else if(stra.size() == strb.size()){
			for(int64_t i=0;i<strb.size();i++){
				char c1 = stra[i];
				char c2 = strb[i];
				int64_t i1 = c1-'0';
				int64_t i2 = c2-'0';
				int64_t flag = i1+i2;
				if(flag>9){
					flag-=10;
					ans+=to_string(flag);
				}
				else{
					ans+=to_string(flag);
				}
			}
			cout <<  ans << "\n";
		}
		else{
			string temp = strb.substr(0,strb.size()-stra.size());
			strb.erase(0,strb.size()-stra.size());
			for(int64_t i=0;i<stra.size();i++){
				char c1 = stra[i];
				char c2 = strb[i];
				int64_t i1 = c1-'0';
				int64_t i2 = c2-'0';
				int64_t flag = i1+i2;
				if(flag>9){
					flag-=10;
					ans+=to_string(flag);
				}
				else{
					ans+=to_string(flag);
				}
			}
			temp+=ans;
			cout <<  temp << "\n";
		}
	}
}


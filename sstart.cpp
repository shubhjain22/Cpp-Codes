#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define vector vector<int64_t>
#define loop(i,n) for(int i=0;i<n;i++)
#define print(v) for (auto i: v) cout << i << ' '
#define eb emplace_back
#define pf push_front
#define whole(x) begin(x),end(x)
int main(){
	std::ios::sync_with_stdio(false);
	int64_t t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		if(str.size()>10){
			unordered_set<char> st;
			int64_t max = 1;
			loop(i,str.size()){
				auto it = st.insert(str[i]);
				if(it.second==false){
					int64_t c = st.size();
					if(c>max){
						max=c;
						st.clear();
						st.insert(str[i]);
					}
				}
				if(i==str.size()-1 && it.second==true){
					int64_t c = st.size();
					if(c>max){
						max=c;
					}
				}
			}
			cout << max << "\n";
		}
		else{
			int64_t max = 1;
			int64_t s = str.size();
			for(int i=0;i<s-1;i++){
				int64_t count=1;
				bool b = true;
				for(int j = i+1;j<s && b;j++){
					if(str[j]==str[i]){
						if(count > max){
							max = count;
						}
						cout << max << " ";
						b=false;
					}
					else{
						count++;
					}
				}
			}
			//cout << max << "\n";
		}
	}
}
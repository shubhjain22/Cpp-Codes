#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vector vector<int64_t>
#define loop(i,n) for(int i=0;i<n;i++)
#define print(v) for (auto i: v) cout << i << ' '
#define eb emplace_back
#define pf push_front
#define whole(x) begin(x),end(x)
int main(){
	std::ios::sync_with_stdio(false);
	int64_t t;
	cin >> t ;
	while(t--){
		string str,s1="";
		cin >> str;
		stack<char> s;
		loop(i,str.size()){
			if(str[i]=='('){
				s.push(str[i]);
			}
			else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){
				s.push(str[i]);
			}
			else if(str[i]==')'){
				s1.push_back(s.top());
				s.pop();
				s.pop();
			}
			else{
				s1.push_back(str[i]);
			}
		}
		cout << s1 << "\n";
	}
} 
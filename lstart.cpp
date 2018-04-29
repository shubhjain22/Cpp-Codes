#include <bits/stdc++.h>

using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);

	
		int n;
		cin >> n;
		string str;
		cin >> str;
		string alpha="abcdefghijklmnopqrstuvwxyz";
		for(int i=0;i<n;i++){
			string ans="";
			string s;
			cin >> s;
			auto j = begin(s); 
			for(auto k = begin(s);k!=end(s);k++){

				*j = tolower(*k);
				int b = (*j==*k);
				if(b!=0){
					
				if(*k==' '){
					ans+=' ';
				}
				else if(*k=='.' || *k=='?' || *k=='!' || *k=='.'){
					ans+=*k;
				}
				else{
				auto o = find(begin(alpha),end(alpha),*k)- begin(alpha);
				char s1 = str[o];
				ans+=s1;
			}
		}
			else{
				if(*k==' '){
					ans+=' ';
				}
				else if(*k=='.' || *k=='?' || *k=='!' || *k=='.'){
					ans+=*k;
				}
				else{
				auto o = find(begin(alpha),end(alpha),*k)- begin(alpha);
				char s1 = str[o];
				ans+=toupper(s1);
			}
			}
			}
			cout << ans << endl;
		}
	
}
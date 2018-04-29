#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vector vector<int64_t>
#define loop(i,n) for(int i=0;i<n;i++)
#define print(v) for (auto i: v) cout << i << ' '
#define eb emplace_back
#define pf push_front
#define whole(x) begin(x),end(x)
unordered_map<string, int> mp;
int64_t ways(int64_t n,vector v,int64_t m){
	if(n==0){
		return 1;
	}
	if(n<0 || m<0){
		return 0;
	}
    string key = to_string(m)+"|"+to_string(n);
    if(mp.find(key)==end(mp)){
        int64_t i = ways(n-v[m],v,m);
        //int64_t j = ways(n,v,m-1);
        mp[key] = i;
    }
    return mp[key]; 
}
int main() {
    int64_t t;
    cin >> t;
    while(t--){
        int64_t n,m;
        cin >> n >> m;
        vector v;
        v.reserve(n);
        loop(i,n){
            int64_t temp;
            cin >> temp;
            v.eb(temp);
        }
        int64_t r = ways(m,v,n);
        if(r>0){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n"; 
        }
    }   
}

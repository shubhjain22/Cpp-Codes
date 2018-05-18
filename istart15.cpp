#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
using namespace std;
vector<int> v1,v2;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        stack<string> s1,s2;
        for(int i=0;i<n;i++){
            string temp;cin>>temp;
            if(i!=0){
                if(s1.size()==0) s1.push(temp);
                else{
                    if(s1.top()==temp) s1.pop();
                    else s1.push(temp);
                }
            }
            else{
                s1.push(temp);
            }
        }
        cout << s1.size() << "\n";
    }
}

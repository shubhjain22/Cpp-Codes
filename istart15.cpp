#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define MOD 1000000007
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        stack<int> s1;
        int64_t buffer = MOD;
        for(auto i : s){
            if(i!='*' && i!='+' && i!='-' && i!='/'){
                s1.push(i-'0');
            }
            else{
                if(buffer==MOD){
                    int a=s1.top();s1.pop();
                    int b=s1.top();s1.pop();
                    if(i=='*') buffer = a*b;
                    else if(i=='+') buffer = a+b;
                    else if(i=='-') buffer = b-a;
                    else buffer = b/a;
                }
                else{
                    int a = s1.top();s1.pop();
                    if(i=='*') buffer = buffer*a;
                    else if(i=='+') buffer = buffer+a;
                    else if(i=='-') buffer = buffer-a;
                    else buffer = buffer/a;
                }
            }
        }
        cout << buffer << "\n";
    }
}

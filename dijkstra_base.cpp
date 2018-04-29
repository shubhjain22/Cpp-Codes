#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
vector<pair<int,int>> v[10005];
int D[10005];
int n,m;
void djks(int source){
    for(int i=1;i<=n;i++){
        D[i] = INT_MAX;
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    D[source]=0;
    q.push({0,source});
    while(!q.empty()){
        auto it = q.top();q.pop();
        int u = it.second;
        for(auto i : v[u]){
            if(D[i.first] > D[u] + i.second){
                D[i.first] = D[u] + i.second;
                q.push({D[i.first],i.first});
            } 
        }
    }
    for(int i=1;i<=n;i++){
        cout << D[i] << " ";
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        v[a].eb(make_pair(b,w));
        v[b].eb(make_pair(a,w));
    }
    djks(1);
}
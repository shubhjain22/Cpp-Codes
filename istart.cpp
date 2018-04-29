#include <bits/stdc++.h>
using namespace std;
#define pii pair<int64_t,int64_t>
#define eb emplace_back
#define mp make_pair



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    int64_t visited[100005];
    vector<pii> v[100005];
    int64_t dist[100005];
    int64_t par[100005];
    vector<int64_t> path;
    int64_t n,m;
    cin>>n>>m;
    priority_queue<pii,vector<pii>,greater<pii>> q;

    memset(visited,0,sizeof visited);
    par[1]=-8;
    
    for(int64_t i=0;i<=n;i++){
        dist[i] = INT_MAX;
    }

    while(m--){
        int64_t a,b,w;cin>>a>>b>>w;
        v[a].eb(mp(b,w));
        v[b].eb(mp(a,w));
    }
    visited[1] = 1;
    queue<int64_t> dq;
    dq.push(1);
    while(!dq.empty()){
        int u = dq.front();dq.pop();
        for(auto j : v[u]){
            if(!visited[j.first]){
                visited[j.first]=1;
                dq.push(j.first);
            }
        }
    }
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        auto it = q.top();q.pop();
        int64_t u = it.second;
        for(auto i : v[u]){
            if(dist[i.first] > dist[u]+i.second){
                dist[i.first] = dist[u]+i.second;
                q.push({dist[i.first],i.first});
                par[i.first] = u;
            }
        }
    }
    
    if(!visited[n]) cout << "-1";
    else{
        
        for(int64_t j=n;j!=-8;j = par[j]){
            path.push_back(j);
        }
        reverse(begin(path),end(path));
        for (int64_t i=0; i<path.size(); ++i)
            cout << path[i] << " ";
    }
}

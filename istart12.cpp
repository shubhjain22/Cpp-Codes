#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define eb emplace_back
#define mp make_pair
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    int n,m,k;cin>>n>>m>>k;
    int arr[n+1];
    memset(arr,0,sizeof arr);
    while(k--){
        int flag;cin>>flag;arr[flag]=1;
    }
    vector<pii> v[1000];
    while(m--){
        int a,b,w;cin>>a>>b>>w;
        v[a].eb(mp(b,w));
        v[b].eb(mp(a,w));
    }
    int source;cin>>source;
    int dis[1000],visited[1000];
    for(int i=0;i<1000;i++){
        dis[i] = INT_MAX;
        visited[i]=0;
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    queue<int> dq;
    dq.push(source);
    visited[source]=1;
    while(!dq.empty()){
        int u = dq.front();dq.pop();
        for(auto j : v[u]){
            if(!visited[j.first]){
                visited[j.first]=1;
                arr[j.first]=0;
                dq.push(j.first);
            }
        }
    }
    dis[source]=0;
    q.push({0,source});
    int max = -90;
    while(!q.empty()){
        auto it = q.top();q.pop();
        int u = it.second;
        for(auto j : v[u]){
            if(dis[j.first] > dis[u]+j.second){
                dis[j.first] = dis[u]+j.second;
                if(dis[j.first]>max){
                    max = dis[j.first];
                }
                q.push({dis[j.first],j.first});
            }
        }
    }
    bool b= true;
    for(int i=1;i<=n;i++){
        if(arr[i]==1 || dis[i]==INT_MAX || max == INT_MAX) b = false;break;
    }
    if(b){
        cout << "The good sponsor!\n" << max << " ";
    }
    else{
        cout <<  "It is not fault of sponsor...\n";
    }
}
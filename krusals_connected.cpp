#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1000005];
struct edge{
    int u,v,w;
};
vector<int> par,size;
struct DisjointSet{
    
    DisjointSet(int n){
        par.resize(n);size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;size[i]=1;
        }
    }
    int find(int u){
        if(u==par[u]) return u;
        return par[u]=find(par[u]);
    }
    void connect(int u,int v){
        u = find(u);v=find(v);
        if(u==v) return ;
        if(size[u]<size[v]) swap(u,v);
        par[v]=u;
        size[u]+=size[v];
    }
    
    bool connected(int u,int v){
        return find(u)==find(v);
    }
};

auto comp = [](edge& e1,edge& e2){
    return e1.w < e2.w;
};
vector<edge> E;
int main(){

    
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;a--;b--;
        E.push_back({a,b,w});
    }
    DisjointSet dsu(n);
    int x = 1;
    arr[0] = n;
    sort(E.begin(),E.end(),comp);
    for(auto& e : E){
        arr[x] = arr[x-1];
        if(!dsu.connected(e.u,e.v)){
            dsu.connect(e.u,e.v);
            --arr[x];
        }
        x++;
    }
    int q;
    cin >> q;
    while(q--){
        int temp;cin>>temp;
        cout << arr[temp] << "\n";
    }
    
}

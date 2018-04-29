#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
		int n,m;
		cin >> n >> m;
		vector<pii> v[n];
		for(int i=0;i<m;i++){
			int a,b,w;
			cin >> a >> b >> w;a--;b--;
			v[a].push_back(mp(b,w));
			v[b].push_back(mp(a,w));
		}
		int w[n],par[n],vis[n],mst=0;
		for(int i=0;i<n;i++){
			w[i] = INT_MAX;vis[i]=0;par[i]=-1;
		}
		priority_queue<pii,vector<pii>,greater<pii>> pq;
    int t;cin>>t;
		par[t--]=0;
		pq.push({0,t--});
		while(!pq.empty()){
			auto it = pq.top();pq.pop();
			int u = it.second;
			if(vis[u]) continue;
			vis[u]=1;
			mst+=it.first;
			for(auto j : v[u]){
				if(!vis[j.first] && w[j.first] > j.second){
					pq.push({j.second,j.first});
					par[j.first] = u;
				}
			}
		}
		cout << mst << "\n";
		
	
}

/*
5 6
1 2 2
1 4 3
2 4 1
2 3 5
4 5 8
3 5 6
*/


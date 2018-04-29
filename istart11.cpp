#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin>>t;
    while(t--){
    	vector<pair<int,int>> v[100005];
		int vis[100005],dis[100005],par[100005];
		memset(vis,0,sizeof vis);
		for(int i=0;i<100005;i++){
			dis[i]=INT_MAX;
		}
    	int n,m;cin>>n>>m;
    	for(int i=0;i<m;i++){
    		int a,b;cin>>a>>b;
    		v[a].push_back(make_pair(b,0));
    		v[b].push_back(make_pair(a,1));
    	}
    	dis[1]=0;
    	deque<int> q;q.push_front(1);
    	while(!q.empty() ){
    		int u = q.front();q.pop_front();
    		for(int j=0;j<v[u].size();j++){
    			int el = v[u][j].first;
    			int w = v[u][j].second;
    			if(dis[el] > dis[j]+w){
    				dis[el]=dis[j]+w;
    				if(w==1){
    					q.push_back(el);
    				}
    				else{
    					q.push_front(el);
    				}
    			}
    		}
    	}
    	cout << dis[2] << "\n";
    }
}
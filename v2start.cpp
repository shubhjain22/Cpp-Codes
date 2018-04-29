#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
bool visited[10000];
void initialize(){
	for(int i=0;i<10000;i++){
		visited[i] = false;
	}
}

void dfs(int s,bool visited[]){
	visited[s]=true;
	cout << s << " ";
	for(int i=0;i<v[s].size();i++){
		if(visited[v[s][i]]==false){
			dfs(v[s][i],visited);
		}
	}
}
int main(void){
	int nodes,edges,x,y;
	cin >> nodes >> edges;
	v.resize(nodes+1);
	for(int i=0;i<edges;i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	initialize();
	for(int i=0;i<nodes;i++){
		if(visited[i]==false){
			dfs(i,visited);
			cout << "\n";
		}
	}
}
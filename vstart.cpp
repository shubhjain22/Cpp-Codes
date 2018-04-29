#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> v1;
bool visited[10];
void initialize(){
	for(int i=0;i<10;i++){
		visited[i] = false;
	}
}
void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < v[s].size();++i)    {
         if(visited[v[s][i]] == false)
             dfs(v[s][i]);
         	 
        }
}
int main(){
	int nodes,edges,x,y,connected = 0;
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
			dfs(i);
			connected++;
		}
	}
	cout << "Number of connected components: " << connected << endl;
	
}
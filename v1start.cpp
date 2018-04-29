#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &V, int u, int v)
{
    V[u].push_back(v);
    V[v].push_back(u);
}

void traverse(vector<vector<int>> V, int node){
	for(int i=0;i<V[node].size();i++)
	{
  		int adjacent_node=V[node][i];
  		cout << adjacent_node;
	}
}

int main()
{
    vector<vector<int>> V;
    V.clear();
    V.resize(5);
    addEdge(V, 0, 1);
    addEdge(V, 0, 2);
    addEdge(V, 1, 2);
    addEdge(V, 1, 3);
    traverse(V,1);
    return 0;
}
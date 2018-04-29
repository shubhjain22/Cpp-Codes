#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
bool visited[10000];
void dfs(int s,bool visited[]){
     visited[s] = true;
     cout << s << " ";
     for(int i=0;i<v[s].size();i++){
          if(visited[v[s][i]] == false){
               dfs(v[s][i],visited);
          }
     }
}

void initialise(){
     for(int i=0;i<10;i++){
          visited[i] = false;
     }
}
int main(void){
     int nodes,edges,x,y,connected=0;
     cin >> nodes >> edges;
     v.resize(nodes+1);
     for(int i=0;i<edges;i++){
          cin >> x >> y;
          v[x].push_back(y);
          v[y].push_back(x);
     }

     initialise();

     for(int i=0;i<nodes;i++){
          if(visited[i]==false){

               dfs(i,visited);
               cout << "\n";
          }
         
     }
     cout << connected << endl;
}
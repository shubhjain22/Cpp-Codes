#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair

int n, m;

string g[1500];
int dist[1500][1500];
int vis[1500][1500]; 

void bfs(int s1, int s2)
{
    dist[s1][s2] = 0;
    vis[s1][s2] = 1;

    deque<pair<int, int> > q;
    q.pf(mp(s1, s2));
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        if(x - 1 >= 0 && !vis[x - 1][y])
        {
            if(g[x - 1][y] == '*')
            {
                vis[x - 1][y] = 1;
                q.pb(mp(x - 1, y));
                dist[x - 1][y] = dist[x][y] + 1;
            }
            else if(g[x - 1][y] != 'B')
            {
                vis[x - 1][y] = 1;
                q.pf(mp(x - 1, y));
                dist[x - 1][y] = dist[x][y];
            }
        }
        if(x + 1 < n && !vis[x + 1][y])
        {
            if(g[x + 1][y] == '*')
            {
                vis[x + 1][y] = 1;
                q.pb(mp(x + 1, y));
                dist[x + 1][y] = dist[x][y] + 1;
            }
            else if(g[x + 1][y] != 'B')
            {
                vis[x + 1][y] = 1;
                q.pf(mp(x + 1, y));
                dist[x + 1][y] = dist[x][y];
            }
        }
        if(y - 1 >= 0 && !vis[x][y - 1])
        {
            if(g[x][y - 1] == '*')
            {
                vis[x][y - 1] = 1;
                q.pb(mp(x, y - 1));
                dist[x][y - 1] = dist[x][y] + 1;
            }
            else if(g[x][y - 1] != 'B')
            {
                vis[x][y - 1] = 1;
                q.pf(mp(x, y - 1));
                dist[x][y - 1] = dist[x][y];
            }
        }
        if(y + 1 < m && !vis[x][y + 1])
        {
            if(g[x][y + 1] == '*')
            {
                vis[x][y + 1] = 1;
                q.pb(mp(x, y + 1));
                dist[x][y + 1] = dist[x][y] + 1;
            }
            else if(g[x][y + 1] != 'B')
            {
                vis[x][y + 1] = 1;
                q.pf(mp(x, y + 1));
                dist[x][y + 1] = dist[x][y];
            }
        }
    }

}

int main()
{
    int t, i, j, s1, s2, e1, e2;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            cin >> g[i];
            for(j = 0; j < m; j++)
            {
                dist[i][j] = -1;
                vis[i][j] = 0;
                if(g[i][j] == 'P')
                {
                    s1 = i;
                    s2 = j;
                }
                if(g[i][j] == 'G')
                {
                    e1 = i;
                    e2 = j;
                }
            }
        }
        bfs(s1, s2);
        cout << dist[e1][e2] << "\n";
    }
    return 0;
}
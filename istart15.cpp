#include <bits/stdc++.h>
#define pii pair<int64_t,int64_t>
#define eb emplace_back
#define pb push_back
using namespace std;
     
int64_t n, m,source,visited[300005][2];
    vector<pii> vec[300005];
     
    void breadthSearch(int64_t start)
    {
        visited[start][0] = 1;
        visited[start][1] = 1;
        deque <pii> deq;
        for(int64_t i=0; i<vec[start].size(); i++)
        {
            visited[vec[start][i].first][vec[start][i].second] = 1;
            deq.eb(make_pair(vec[start][i].first, vec[start][i].second));
        }
        while(!deq.empty())
        {
            int64_t current = deq.front().first;
            int64_t pattern = deq.front().second;
            for(int64_t i=0; i<vec[current].size(); i++)
            {
                if(vec[current][i].second != pattern && !visited[vec[current][i].first][vec[current][i].second])
                {
                    visited[vec[current][i].first][vec[current][i].second] = 1;
                    deq.eb(make_pair(vec[current][i].first, vec[current][i].second));
                }
            }
            deq.pop_front();
        }
    }
    int main()
    {
        cin >> n >> m;
        int64_t a, b, wt;
        for(int64_t i=0; i<m; i++)
        {
            cin >> a >> b >> wt;
            vec[a].eb(make_pair(b,wt));
        }
        cin >> source;
        breadthSearch(source);
        int64_t t,flag;cin >> t;
        while(t--)
        {
            cin >> flag;
            if(visited[flag][0] || visited[flag][1])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> pq;
	int64_t k,n;
	cin >> k >> n;
	vector<int64_t> a;
	a.reserve(n*k);
	vector<deque<int64_t>> v(k);
	for(int64_t i=0;i<k;i++){
		for(int64_t j=0;j<n;j++){
			cin >>  v[i][j] ;
		}
	}
	for(int64_t i=0;i<k;i++){
		pq.push(make_pair(v[i][0],i));
		v[i].pop_front();
	}
	for(int64_t i=0;i<n*k;i++){
		auto it = pq.top();
		pq.pop();
		a.push_back(it.first);
		if(!v[it.second].empty()){
			pq.push(v[it.second][0]);
			v[it.second].pop_front();
		}
		else{
			for(int64_t i=0;i<k;i++){
				if(!v[i].empty())
			}
		}
	}
}

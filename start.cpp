#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main(void){
	std::ios::sync_with_stdio(false);
	int64_t n,a,b,c;
	int64_t count = 0;
	cin >> n >> a >> b >> c;
	vector<int64_t> v;
	v.reserve(n);
	for(int64_t i=0;i<n;i++){
		int64_t temp;
		cin >> temp;
		v.emplace_back(temp);
	}
	auto q = max_element(begin(v), end(v));
	auto w = min_element(begin(v), end(v));
	if(a<0){
		count+=a*(*w);
	}
	else{
		count+=a*(*q);
	}
	if(b<0){
		count+=b*(*w);
	}
	else{
		count+=b*(*q);
	}
	if(c<0){
		count+=c*(*w);
	}
	else{
		count+=c*(*q);
	}
	cout << count << endl;
	return 0;
}
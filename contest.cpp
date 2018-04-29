#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int64_t n,k;
		cin >> n >> k;
		if(n==0 && k ==0){
			cout << "0" << " " << "0" << endl;
			
		}
		else if(n==0){
			cout << "0" << " " << "0" << endl;
		}
		else if(k==0){
			cout << "0" << " " << n << endl;
		}
		else{
			cout << n/k << " " << n%k << endl ; 
		}
	}
}


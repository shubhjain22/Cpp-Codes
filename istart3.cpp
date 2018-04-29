#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define loop(i,n) for(int64_t i=0;i<n;i++)

bool rat(char arr[1001][1001],int sol[][1001],int i,int j,int m,int n){
	if(i==m && j==n){
		sol[i][j]=1;
		loop(i,m){
			loop(j,n){
				cout << sol[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		return true;
	}
	if(i>m || j>n || arr[i][j]=='X'){
		return false;
	}
	sol[i][j]=1;
	bool b1 = rat(arr,sol,i,j+1,m,n);
	if(b1){
		return true;
	}
	bool b2 = rat(arr,sol,i+1,j,m,n);
	if(b2){
		return true;
	}
	sol[i][j]=0;
	return false;
}
int main(){
	int64_t m,n;
	cin >> m >> n;
	char arr[1000][1000];
	loop(i,m){
		loop(j,n){
			cin >> arr[i][j];
		}
	}
	int sol[1001][1001]={0};
	bool ans = rat(arr,sol,0,0,m,n);
	if(!ans){
		cout << "No sol Exists" << "\n";
	}
	return 0;
}
/*5
4
O
X
O
O
O
O
O
X
O
O
X
O
X
O
O
O
X
X
O
O*/
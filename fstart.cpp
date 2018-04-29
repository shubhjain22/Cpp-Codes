#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int k,i,j,t;
	char a[27];
	for(int c = 'z';c>='a';c--)
		a['z'-c] = c;
	a[26]='\0';
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k%25!=0){
		for(char c = 'a'+k%25;c>='a';c--)
			cout<<c;
		}
		k = k/25;
		while(k--)
			cout<<a;
	cout<<endl;
	}
	return 0;
} 
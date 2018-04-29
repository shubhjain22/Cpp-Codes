#include<bits/stdc++.h>
using namespace std;
bool isHeapmax(int64_t arr[],  int64_t n)
{
    for (int64_t i=0; i<=(n-2)/2; i++)
    {
        if (arr[2*i +1] > arr[i] && (2*i+2)<n)
                return false;
            
        if (arr[2*i+2] > arr[i] && (2*i+2)<n)
                return false;
    }
    return true;
}
bool isHeapmin(int64_t *arr,  int64_t n)
{
    for (int i=0; i<=(n-2)/2; i++)
    {
        if (arr[2*i +1] < arr[i] && (2*i+2)<n)
                return false;

        if (arr[2*i+2] < arr[i] && (2*i+2)<n)
                return false;
    }
    return true;
}
int main(){
	int64_t n;
	cin >> n;
	int64_t arr[n];
	for(int64_t i=0;i<n;i++){
		cin >> arr[i];
	}
	bool b1 = isHeapmax(arr,n);
	if(b1){
		cout << "MAXHEAP" << "\n";
	}
	else{
		bool b2 = isHeapmin(arr,n);
		if(b2){
			cout <<"MINHEAP" << "\n";
		}
		else {
			cout << "NONE"  << "\n";
		}
	}
}
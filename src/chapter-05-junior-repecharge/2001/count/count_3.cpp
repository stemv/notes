#include<iostream>
using namespace std;

int main(){
	int a[1001],n,i,s;
	a[1]=1;
	
	cin>>n;

	for(s=2;s<=n;s++){
		a[s]=0;
    	for(i=1;i<=s/2;i++){
        	a[s]+=a[i];
		}
		a[s]++;
	}
	
	cout << a[n] << endl;
	
	return 0;
}
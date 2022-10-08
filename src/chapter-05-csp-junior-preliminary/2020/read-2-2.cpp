#include <iostream>
using namespace std;

long long n, ans;
int k,len;
long long d[1000000];

int main(){
	cin >> n >> k;
	d[0]=0;
	len = 1;
	ans = 0;
	for(long long i=0;i<n;i++){
		++d[0];
		for(int j=0;j+1<len;j++){
			if(d[j]==k){
				cout << "->";
				d[j]=0;
				d[j+1]+=1;
				++ans;
			}
		}
		if(d[len-1]==k){
			cout << "=>";
			d[len-1]=0;
			d[len]=1;
			++len;
			++ans;
		}
	}
	for (int i=0;i<len;i++)
		cout << d[i] << ",";
	cout << endl;
	
	cout << "len=" << len << endl;
	cout << "ans=" << ans << endl;
	
	return 0;
} 
